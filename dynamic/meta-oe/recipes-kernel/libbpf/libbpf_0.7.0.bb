SUMMARY = "Library for BPF handling"
DESCRIPTION = "Library for BPF handling"
HOMEPAGE = "https://github.com/libbpf/libbpf"
SECTION = "libs"
LICENSE = "LGPL-2.1-or-later"

LIC_FILES_CHKSUM = "file://../LICENSE.LGPL-2.1;md5=b370887980db5dd40659b50909238dbd"

DEPENDS = "zlib elfutils"

FILESEXTRAPATHS:prepend := "${THISDIR}/libbpf:"

SRC_URI = "git://github.com/libbpf/libbpf.git;protocol=https;branch=master \
	   file://0001-libbpf-add-txtime-field-in-xdp_desc-struct.patch;patchdir=${S}/../"
SRCREV = "2cd2d03f63242c048a896179398c68d2dbefe3d6"

PACKAGE_ARCH = "${MACHINE_ARCH}"
COMPATIBLE_HOST = "(x86_64|i.86|aarch64|riscv64|powerpc64).*-linux"

S = "${WORKDIR}/git/src"

EXTRA_OEMAKE += "DESTDIR=${D} LIBDIR=${libdir} INCLUDEDIR=${includedir}"
EXTRA_OEMAKE:append:class-native = " UAPIDIR=${includedir}"

inherit pkgconfig

do_compile() {
	oe_runmake
}

do_install() {
	oe_runmake install
}

do_install:append:class-native() {
	oe_runmake install_uapi_headers
}

BBCLASSEXTEND = "native nativesdk"
