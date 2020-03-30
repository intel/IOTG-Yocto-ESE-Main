SUMMARY = "Intel(R) Graphics Memory Management Library"
DESCRIPTION = "The Intel(R) Graphics Memory Management Library provides \
device specific and buffer management for the Intel(R) Graphics \
Compute Runtime for OpenCL(TM) and the Intel(R) Media Driver for VAAPI."

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE.md;md5=d9a6e772cd4c362ee4c8ef87c5aad843"

SRC_URI = " \
            git://github.com/intel/gmmlib.git;protocol=https \
            "

SRCREV = "c01f0041811a3f1ff7913e620ba93e6c3ec10820"
PV_append = "+git${SRCPV}"

S = "${WORKDIR}/git"

UPSTREAM_CHECK_GITTAGREGEX = "^intel-gmmlib-(?P<pver>(\d+(\.\d+)+))$"

inherit pkgconfig cmake

EXTRA_OECMAKE += "-DRUN_TEST_SUITE=OFF"
BBCLASSEXTEND = "native"
