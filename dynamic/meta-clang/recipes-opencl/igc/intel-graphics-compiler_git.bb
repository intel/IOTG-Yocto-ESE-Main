SUMMARY = "The Intel(R) Graphics Compiler for OpenCL(TM)"
DESCRIPTION = "The Intel(R) Graphics Compiler for OpenCL(TM) is an \
llvm based compiler for OpenCL(TM) targeting Intel Gen graphics \
hardware architecture."

LICENSE = "MIT & BSD-3-Clause"
LIC_FILES_CHKSUM = "file://IGC/BiFModule/Implementation/ExternalLibraries/libclc/LICENSE.TXT;md5=311cfc1a5b54bab8ed34a0b5fba4373e \
                    file://IGC/Compiler/LegalizationPass.cpp;beginline=1;endline=25;md5=4abf1738ff96b18e34186eb763e28eeb"

SRC_URI = "git://github.com/intel/intel-graphics-compiler.git;protocol=https \
           file://0002-skip-execution-of-ElfPackager.patch \
           file://0001-Should-not-hardcode-the-patch-to-the-LLVM-lib.patch \
           "

SRCREV = "60df49c8569c98bcf262da396f85581c21a3ed5e"
PV = "git+${SRCPV}"

S = "${WORKDIR}/git"

inherit cmake

COMPATIBLE_HOST = '(x86_64).*-linux'
COMPATIBLE_HOST_libc-musl = "null"

DEPENDS += " flex-native bison-native clang opencl-clang"
DEPENDS_append_class-target = " clang-cross-x86_64"

RDEPENDS_${PN} += "opencl-clang"

LLVM_COMPAT_VER = "${@bb.utils.contains('LLVMVERSION', '9.0.1', '9.0.0', '10.0.0', d)}"

EXTRA_OECMAKE = "-DIGC_PREFERRED_LLVM_VERSION=${LLVM_COMPAT_VER} -DPYTHON_EXECUTABLE=${HOSTTOOLS_DIR}/python3"

LDFLAGS_append_class-native = " -fuse-ld=lld"
TOOLCHAIN_class-native = "clang clang++"

BBCLASSEXTEND = "native nativesdk"

UPSTREAM_CHECK_GITTAGREGEX = "^igc-(?P<pver>(?!19\..*)\d+(\.\d+)+)$"
