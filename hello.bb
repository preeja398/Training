SUMMARY = "Simple helloworld application using CMake"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = " \
          file://myhello.c \
          file://CMakeLists.txt \
          "

S = "${WORKDIR}"

inherit cmake

do_install() {
	install -d ${D}${bindir}
	install -m 0755 myhello ${D}${bindir}
} 

