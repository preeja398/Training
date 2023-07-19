#include<gst/gst.h>

typedef struct _CustomData {
    GstElement *pipeline, *source, *tsdemux, *multiqueue, *videoparse, *mpegaudioparse_1, *mpegaudioparse_2, *mpegaudioparse_3, *ac3audioparse, *mpegtsmux, *filesink;
} CustomData;


static void pad_added_handler(GstElement *src, GstPad *new_pad, CustomData *data);

int main(int argc, char *argv[]) {
    CustomData data;
    GstBus *bus;
    GstMessage *msg;
    GstStateChangeReturn ret;
    gint programNumber;

    if(argc != 4) {
        g_print("Execute as below format\n");
        g_print("<a.out> <input file> <program-number> <output file>\n");
        return -1;
    }

    gst_init(&argc, &argv);

    data.pipeline = gst_pipeline_new("pipeline");

    data.source = gst_element_factory_make ("filesrc", "source");
    data.tsdemux = gst_element_factory_make("tsdemux", "tsdemux");
    data.multiqueue = gst_element_factory_make("multiqueue", "multi-queue");
    data.videoparse = gst_element_factory_make ("h264parse", "video-parse");
    data.mpegaudioparse_1 = gst_element_factory_make ("mpegaudioparse", "mpegaudio-parse01");
    data.mpegaudioparse_2 = gst_element_factory_make ("mpegaudioparse", "mpegaudio-parse02");
    data.mpegaudioparse_3 = gst_element_factory_make ("mpegaudioparse", "mpegaudio-parse03");
    data.ac3audioparse = gst_element_factory_make ("ac3parse", "ac3audio-parse");
    data.mpegtsmux = gst_element_factory_make("mpegtsmux", "mpegtsmux");
    data.filesink = gst_element_factory_make("filesink", "filesink");


    if(!data.pipeline || !data.source || !data.tsdemux || !data.multiqueue || !data.videoparse || !data.mpegaudioparse_1 || !data.mpegaudioparse_2 || !data.mpegaudioparse_3 || !data.ac3audioparse || !data.mpegtsmux || !data.filesink){
        g_printerr("***NOT ALL ELEMENT IS CREATED***\n");
        return -1;
    }

    gst_bin_add_many(GST_BIN(data.pipeline), data.source, data.tsdemux, data.multiqueue, data.videoparse, data.mpegaudioparse_1, data.mpegaudioparse_2, data.mpegaudioparse_3, data.ac3audioparse, data.mpegtsmux, data.filesink, NULL);

    if(!gst_element_link(data.source,  data.tsdemux)) {
        g_printerr("***LINKED  FAILED WITH (source, tsdemux)***\n");
        gst_object_unref(data.pipeline);
        return -1;
    }

    g_signal_connect(data.tsdemux, "pad-added", G_CALLBACK(pad_added_handler), &data);

    if(!gst_element_link(data.mpegtsmux, data.filesink)) {
        g_printerr("***LINKED  FAILED WITH (mpegtsmux, filesink)***\n");
        gst_object_unref(data.pipeline);
        return -1;
    }

    programNumber = atoi(argv[2]);

    g_object_set(data.source, "location", argv[1], NULL);
    g_object_set(data.tsdemux, "program-number", programNumber, NULL);
    g_object_set(data.filesink, "location", argv[3], NULL);

    ret = gst_element_set_state (data.pipeline, GST_STATE_PLAYING);

    if(ret == GST_STATE_CHANGE_FAILURE) {
        g_printerr("***UNABLE TO SET THE PIPELINE IN PLAYING STATE***\n");
        gst_object_unref(data.pipeline);
        return -1;
    }

    bus = gst_element_get_bus (data.pipeline);
    msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE, GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

    if (msg != NULL) {
    GError *err;
    gchar *debug_info;

        switch (GST_MESSAGE_TYPE (msg)) {
            case GST_MESSAGE_ERROR:
                gst_message_parse_error (msg, &err, &debug_info);
                g_printerr ("Error received from element %s: %s\n", GST_OBJECT_NAME (msg->src), err->message);
                g_printerr ("Debugging information: %s\n", debug_info ? debug_info : "none");
                g_clear_error (&err);
                g_free (debug_info);
                break;

            case GST_MESSAGE_EOS:
                g_print ("End-Of-Stream reached.\n");
                break;
            default:
                g_printerr ("Unexpected message received.\n");
                break;
        }
        gst_message_unref (msg);
    }

    gst_object_unref (bus);
    gst_element_set_state (data.pipeline, GST_STATE_NULL);
    gst_object_unref (data.pipeline);
    return 0;
}

static void pad_added_handler(GstElement *src, GstPad *new_pad, CustomData *data) {
    GstCaps *new_pad_caps = NULL;
    GstStructure *new_pad_struct = NULL;
    const gchar *new_pad_type = NULL;
    g_print ("\nReceived new pad '%s' from '%s':\n", GST_PAD_NAME (new_pad), GST_ELEMENT_NAME (src));

    new_pad_caps = gst_pad_get_current_caps (new_pad);
    new_pad_struct = gst_caps_get_structure (new_pad_caps, 0);
    new_pad_type = gst_structure_get_name (new_pad_struct);
    g_print ("It has pad type '%s'\n", new_pad_type);
    static gint count=1;

    GstPadTemplate *multiqueue_sinkpad_template =gst_element_class_get_pad_template(GST_ELEMENT_GET_CLASS(data->multiqueue), "sink_%u");
    if(g_str_has_prefix(new_pad_type, "video/")) {
        GstPad *multiqueue_sinkpad = gst_element_request_pad(data->multiqueue, multiqueue_sinkpad_template, NULL, NULL);
        if(gst_pad_link(new_pad, multiqueue_sinkpad) != GST_PAD_LINK_OK) {
            g_printerr("***LINK FAILED WITH(tsdemux, multiqueue) %s and %s***\n", GST_PAD_NAME (new_pad), GST_PAD_NAME (multiqueue_sinkpad));
            gst_object_unref(data->pipeline);
        } else {
              if(!gst_element_link_pads(data->multiqueue, NULL, data->videoparse, "sink")) {
                  g_printerr("***LINK FAILED WITH multiqueue, videoparse ***");
                  gst_object_unref(data->pipeline);
              } else {
                    if(!gst_element_link_pads(data->videoparse, "src", data->mpegtsmux, NULL)) {
                        g_printerr("***LINKED FAILED WITH videoparse, mpegtsmux***\n");
                        gst_object_unref(data->pipeline);
                    }
              }
        }
    } else if (g_str_has_prefix(new_pad_type, "audio/") ) {
          GstElement *audioparse;
          GstPad *multiqueue_sinkpad = gst_element_request_pad(data->multiqueue, multiqueue_sinkpad_template, NULL, NULL);
          if(gst_pad_link(new_pad, multiqueue_sinkpad) != GST_PAD_LINK_OK) {
              g_printerr("***LINK FAILED WITH (tsdemux, multiqueue) %s and %s***\n", GST_PAD_NAME (new_pad), GST_PAD_NAME (multiqueue_sinkpad));
              gst_object_unref(data->pipeline);
          }

          if (g_str_has_prefix(new_pad_type, "audio/mpeg")) {
              if(count == 1) audioparse = data->mpegaudioparse_1;
                  else if(count == 2) audioparse = data->mpegaudioparse_2;
                      else if (count == 3) audioparse = data->mpegaudioparse_3;
                          else g_print("maximum no.of mpeg audio parse element reached\n");
              count ++;
          } else if (g_str_has_prefix(new_pad_type, "audio/x-ac3")) {
                audioparse = data->ac3audioparse;
          } else {
                g_print ("UNSUPPORTED audio stream\n");
          }
          if (audioparse != NULL) {
              if(!gst_element_link_pads(data->multiqueue, NULL, audioparse, "sink")) {
                  g_printerr("***LINK FAILED WITH (multiqueue,mpegaudioparse_1)***\n");
                  gst_object_unref(data->pipeline);
              } else {
                    if(!gst_element_link_pads(audioparse, "src", data->mpegtsmux, NULL)) {
                        g_printerr("***LINKED FAILED WITH (mpegaudioparse_1, mpegtsmux)***\n");
                        gst_object_unref(data->pipeline);
                    }
              }
          }
    } else {
          g_print("***UNSUPPORTED STREAM TYPE: %s\n", new_pad_type);
          gst_caps_unref(new_pad_caps);
    }
    GST_DEBUG_BIN_TO_DOT_FILE(GST_BIN(data->pipeline), GST_DEBUG_GRAPH_SHOW_ALL, "pipeline");
}
