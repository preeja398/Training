RDEPENDS_packagegroup-rdk-generic-mediaclient_append = " ${@bb.utils.contains('DISTRO_FEATURES', 'cobalt-plugin', 'cobalt-plugin', '', d)}"

RDEPENDS_packagegroup-rdk-generic-mediaclient_append += "hello" 
