#include<gst/gst.h>

int main() {
    GstElement *pipeline;
    GstBus *bus;
    GstMessage *msg;

    gst_init (NULL, NULL);

    pipeline = gst_element_factory_make("playbin", "pipeline");

    if (!pipeline) {
        g_printerr("***ELEMENT IS NOT CREATED***\n");
       	return 1;
    }

    g_object_set(pipeline, "uri", "file:///home/kalaiyarasan/Downloads/786MHz.ts", NULL);

    gst_element_set_state (pipeline, GST_STATE_PLAYING);

    GST_DEBUG_BIN_TO_DOT_FILE(GST_BIN(pipeline), GST_DEBUG_GRAPH_SHOW_ALL, "pipeline");

    bus = gst_element_get_bus (pipeline);
    msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE, GST_MESSAGE_ERROR | GST_MESSAGE_EOS);


    if(msg != NULL) {
        GError *err;
	gchar *debug_info;

	switch(GST_MESSAGE_TYPE(msg)) {
            case GST_MESSAGE_ERROR:
                gst_message_parse_error(msg, &err, &debug_info);
		g_printerr("Error from element %s --->%s\n",GST_OBJECT_NAME( msg->src), err->message);
		g_printerr("Debug info %s\n", debug_info ? debug_info : "none");
		g_clear_error(&err);
		g_free(debug_info);
		break;
	    case GST_MESSAGE_EOS:
		g_printerr("EOS reached\n");
		break;
	    default:
	        g_printerr("***UNEXPECTED MESSAGE RECEIVED***\n");
	}
    }	
		
    gst_message_unref(msg);
    gst_object_unref(bus);
    gst_element_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref (pipeline);
    return 0;
}
