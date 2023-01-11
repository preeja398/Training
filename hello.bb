SUMMARY = "GNU Helloworld application"
SECTION = "examples"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = " \
           file://hello.c \
           file://configure.ac \
           file://Makefile.am \
           "

S = "${WORKDIR}"

inherit autotools

do_install() {
        install -d ${D}${bindir}
        install -m 0755 hello ${D}${bindir}
}
