#include<gst/gst.h>

typedef struct _CustomData {
    GstElement *pipeline,*source, *typeFind, *tsdemux, *multiQueue, *audioParse, *videoParse, *audioDecoder, *capsFilter, *videoDecoder, *audioInputSelector, *videoInputSelector, *audioTee, *streamSync, *audioQueue, *audioConvert, *audioResample, *audioSink, *vdconv, *deinterlace, *videoQueue, *videoconvert, *videoScale, *glUpload, *glColorConvert, *glColorBalance, *glImageSink;

    GstElement *uridecodebin, *decodebin, *playsink, *audiobin, *audioconv, *videobin, *vbin, *videoconv, *gimagesinkbin;
} CustomData;

static void pad_added_handler(GstElement *src, GstPad *new_pad, CustomData *data);

int main(int argc, char *argv[]) {
    CustomData data;	
    GstBus *bus;
    GstMessage *msg;
    GstStateChangeReturn ret;

    gst_init (&argc, &argv);
    
    data.pipeline = gst_pipeline_new("pipeline");

    data.uridecodebin = gst_bin_new("uridecodebin");
    data.decodebin = gst_bin_new("decodebin");
    data.playsink = gst_bin_new("playsink");
    data.audiobin = gst_bin_new("audiobin");
    data.audioconv = gst_bin_new("audioconvertbin");
    data.videobin = gst_bin_new("videobin");
    data.vbin = gst_bin_new("vbin,");
    data.videoconv = gst_bin_new("videoconv");
    data.gimagesinkbin = gst_bin_new("gimagesinkbin");

    data.source = gst_element_factory_make("filesrc", "source");
    data.typeFind = gst_element_factory_make("typefind", "typefind");
    data.tsdemux = gst_element_factory_make("tsdemux", "tsdemux");
    data.multiQueue = gst_element_factory_make("multiqueue", "multiqueue");
    data.audioParse = gst_element_factory_make("mpegaudioparse", "audioparse");
    data.videoParse  = gst_element_factory_make("h264parse", "videoparse");
    data.audioDecoder = gst_element_factory_make("avdec_mp2float", "audiodecoder");
    data.capsFilter = gst_element_factory_make("capsfilter", "capsfilter");
    data.videoDecoder = gst_element_factory_make("avdec_h264", "videodecoder");
    data.audioInputSelector = gst_element_factory_make("input-selector", "audioinputSelector"); 
    data.videoInputSelector = gst_element_factory_make("input-selector", "videoinputSelector");
    data.audioTee = gst_element_factory_make("tee", "audiotee");
    data.streamSync = gst_element_factory_make("streamsynchronizer", "streamsync");
    data.audioQueue = gst_element_factory_make("queue", "audioqueue");
    data.audioConvert = gst_element_factory_make("audioconvert", "audioconvert");
    data.audioResample = gst_element_factory_make("audioresample", "audioresample");
    data.audioSink = gst_element_factory_make("pulsesink", "audiosink");
    data.vdconv = gst_element_factory_make("videoconvert", "vdconv");
    data.deinterlace = gst_element_factory_make("deinterlace", "deinterlace");
    data.videoQueue = gst_element_factory_make("queue", "videoqueue");
    data.videoconvert = gst_element_factory_make("videoconvert", "videoconvert");
    data.videoScale = gst_element_factory_make("videoscale", "videoscale");
    data.glUpload = gst_element_factory_make("glupload", "gl-upload");
    data.glColorConvert = gst_element_factory_make("glcolorconvert", "glcolorconvert");
    data.glColorBalance = gst_element_factory_make("glcolorbalance", "glcolorbalance");
    data.glImageSink = gst_element_factory_make("glimagesink", "glimagesink");

    if( !data.uridecodebin || !data.decodebin || !data.playsink || !data.audiobin || !data.audioconv || !data.videobin || !data.vbin || !data.videoconv || !data.gimagesinkbin || !data.pipeline || !data.source || !data.typeFind || !data.tsdemux || !data.multiQueue || !data.audioParse || !data.videoParse || !data.audioDecoder || !data.capsFilter || !data.videoDecoder || !data.audioInputSelector || !data.videoInputSelector || !data.audioTee || !data.streamSync  || !data.audioQueue || !data.audioConvert || !data.audioResample || !data.audioSink || !data.vdconv || !data.deinterlace || !data.videoQueue || !data.videoconvert || !data.videoScale  || !data.glUpload || !data.glColorConvert || !data.glColorBalance || !data.glImageSink) {
        g_printerr("All element is not created\n");
    }

    g_object_set(G_OBJECT(data.source), "location", "/home/kalaiyarasan/Downloads/786MHz.ts", NULL);

    gst_bin_add_many (GST_BIN(data.uridecodebin), data.source, data.decodebin, NULL);
    gst_bin_add_many (GST_BIN(data.decodebin), data.typeFind, data.tsdemux, data.multiQueue, data.audioParse, data.videoParse,data.audioDecoder,  data.capsFilter, data.videoDecoder, NULL);
    gst_bin_add_many(GST_BIN(data.playsink), data.audioTee, data.streamSync, data.audiobin, data.videobin, data.vbin, NULL);
    gst_bin_add_many(GST_BIN(data.audiobin), data.audioQueue, data.audioconv, NULL);
    gst_bin_add_many(GST_BIN(data.audioconv), data.audioConvert, data.audioResample, NULL);
    gst_bin_add(GST_BIN(data.audiobin), data.audioSink);
    gst_bin_add_many(GST_BIN(data.videobin), data.vdconv, data.deinterlace, NULL);
    gst_bin_add_many(GST_BIN(data.vbin), data.videoQueue, data.videoconv, data.gimagesinkbin, NULL);
    gst_bin_add_many(GST_BIN(data.videoconv), data.videoconvert, data.videoScale, NULL);
    gst_bin_add_many(GST_BIN(data.gimagesinkbin), data.glUpload, data.glColorConvert, data.glColorBalance, data.glImageSink, NULL);

    gst_bin_add_many (GST_BIN(data.pipeline), data.uridecodebin, data.audioInputSelector, data.videoInputSelector, data.playsink, NULL);
    
    if (!gst_element_link_many (data.source, data.typeFind, data.tsdemux, NULL)) {
        g_printerr ("***ELEMENT NOT LINKED(source, typefine, tsdemux)***\n");
        gst_object_unref (data.pipeline);
        return -1;
    }

    g_signal_connect (data.tsdemux, "pad-added", G_CALLBACK (pad_added_handler), &data);

    if(!gst_element_link_many(data.audioParse, data.audioDecoder, data.audioInputSelector, data.audioTee, data.streamSync, data.audioQueue, data.audioConvert, data.audioResample, data.audioSink, NULL)) {
        g_printerr ("***ELEMENT NOT LINKED AUDIO ELEMENYS***\n");
        gst_object_unref (data.pipeline);
        return -1;
    }

    if (!gst_element_link_many(data.videoParse, data.capsFilter, data.videoDecoder, data.videoInputSelector, data.streamSync, data.vdconv, data.deinterlace, data.videoQueue, data.videoconvert, data.videoScale, data.glUpload, data.glColorConvert, data.glColorBalance, data.glImageSink, NULL)) {
        g_printerr ("***ELEMENT NOT LINKED VIDEO ELEMENTS***\n");
        gst_object_unref (data.pipeline);
        return -1;
    }

    ret = gst_element_set_state (data.pipeline, GST_STATE_PLAYING);
    if (ret == GST_STATE_CHANGE_FAILURE) {
        g_printerr ("***UNABLE TO SET THE PIPELINE TO PLAYING STATE***\n");
        gst_object_unref (data.pipeline);
        return -1;
    }

    bus = gst_element_get_bus (data.pipeline);
    msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE, GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

    if(msg != NULL) {
        GError *err;
        gchar *debug_info;

        switch(GST_MESSAGE_TYPE(msg)) {
            case GST_MESSAGE_ERROR:
                gst_message_parse_error(msg, &err, &debug_info);
                g_printerr("Error from element: %s\n%s\n",GST_OBJECT_NAME( msg->src), err->message);
                g_printerr("Debug info: %s\n", debug_info ? debug_info : "none");
                g_clear_error(&err);
                g_free(debug_info);
                break;

            case GST_MESSAGE_EOS:
                g_printerr("EOS reached\n");
                break;

            default:
                g_printerr("unexpected message received\n");
	}
        gst_message_unref(msg);
    }
    gst_object_unref(bus);
    gst_element_set_state(data.pipeline, GST_STATE_NULL);
    gst_object_unref (data.pipeline);
    return 0;
}

static void pad_added_handler(GstElement *src, GstPad *new_pad, CustomData *data) {
    GstCaps *new_pad_caps = NULL;
    GstStructure *new_pad_struct = NULL;
    const gchar *new_pad_type = NULL;

    g_print("Received new pad '%s' from '%s'\n", GST_PAD_NAME(new_pad), GST_ELEMENT_NAME(src));

    new_pad_caps = gst_pad_get_current_caps (new_pad);
    new_pad_struct = gst_caps_get_structure (new_pad_caps, 0);
    new_pad_type = gst_structure_get_name (new_pad_struct);
   
    g_print ("It has pad type '%s'\n", new_pad_type);

    GstPadTemplate *multiqueue_sinkpad_template =gst_element_class_get_pad_template(GST_ELEMENT_GET_CLASS(data->multiQueue), "sink_%u");
    GstPad *multiqueue_sinkpad = gst_element_request_pad(data->multiQueue, multiqueue_sinkpad_template, NULL, NULL);
    
    if (g_str_has_prefix (new_pad_type, "video/")) {
        if(gst_pad_link(new_pad, multiqueue_sinkpad) != GST_PAD_LINK_OK) {
            g_printerr("***LINK FAILED WITH %s and %s***\n", GST_PAD_NAME(new_pad), GST_PAD_NAME(multiqueue_sinkpad));
	} 

	if(!gst_element_link_pads(data->multiQueue, NULL, data->videoParse, "sink")) {
            g_printerr("***LINK FAILED WITH (multiqueue, videoparse)***");
	}
    } else if (g_str_has_prefix (new_pad_type, "audio/")) {
          if(gst_pad_link(new_pad, multiqueue_sinkpad) != GST_PAD_LINK_OK) {
              g_printerr("***LINK FAILED WITH %s and %s***\n", GST_PAD_NAME(new_pad), GST_PAD_NAME(multiqueue_sinkpad));
	  }

	  if(!gst_element_link_pads(data->multiQueue, NULL, data->audioParse, "sink")) {
              g_printerr("***LINK FAILED WITH (multiqueue, audioparse)***");
	  }
    } else {
        g_printerr("***UNSUPPORTED STREAM TYPE:%s\n***", new_pad_type);
    }

    if (new_pad_caps != NULL)
        gst_caps_unref (new_pad_caps);
    
    GST_DEBUG_BIN_TO_DOT_FILE(GST_BIN(data->pipeline), GST_DEBUG_GRAPH_SHOW_ALL, "pipeline");
}
