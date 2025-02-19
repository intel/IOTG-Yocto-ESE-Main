SUMMARY = "Fast open source processor emulator"
DESCRIPTION = "QEMU is a hosted virtual machine monitor: it emulates the \
machine's processor through dynamic binary translation and provides a set \
of different hardware and device models for the machine, enabling it to run \
a variety of guest operating systems"
HOMEPAGE = "http://qemu.org"
LICENSE = "GPL-2.0-only & LGPL-2.1-only"

DEPENDS += "bison-native meson-native ninja-native"

RDEPENDS:${PN}-ptest = "bash"

require qemu-targets.inc
# https://gitlab.com/qemu-project/qemu/-/commit/81e2b198a8cb4ee5fdf108bd438f44b193ee3a36 means
# we need a full python3-native setup
inherit pkgconfig ptest update-rc.d systemd python3native

LIC_FILES_CHKSUM = "file://COPYING;md5=441c28d2cf86e15a37fa47e15a72fbac \
                    file://COPYING.LIB;endline=24;md5=8c5efda6cf1e1b03dcfd0e6c0d271c7f"

SRC_URI = "https://download.qemu.org/${BPN}-${PV}.tar.xz \
           file://powerpc_rom.bin \
           file://run-ptest \
           file://0001-qemu-Add-addition-environment-space-to-boot-loader-q.patch \
           file://0003-apic-fixup-fallthrough-to-PIC.patch \
           file://0004-configure-Add-pkg-config-handling-for-libgcrypt.patch \
           file://0005-qemu-Do-not-include-file-if-not-exists.patch \
           file://0006-qemu-Add-some-user-space-mmap-tweaks-to-address-musl.patch \
           file://0007-qemu-Determinism-fixes.patch \
           file://0008-tests-meson.build-use-relative-path-to-refer-to-file.patch \
           file://0009-Define-MAP_SYNC-and-MAP_SHARED_VALIDATE-on-needed-li.patch \
           file://0010-hw-pvrdma-Protect-against-buggy-or-malicious-guest-d.patch \
           file://0002-linux-user-Replace-use-of-lfs64-related-functions-an.patch \
           file://fixedmeson.patch \
           file://no-pip.patch \
           file://4a8579ad8629b57a43daa62e46cc7af6e1078116.patch \
           file://0001-linux-user-x86_64-Handle-the-vsyscall-page-in-open_s.patch \
           file://0002-linux-user-loongarch64-Remove-TARGET_FORCE_SHMLBA.patch \
           file://0003-linux-user-Add-strace-for-shmat.patch \
           file://0004-linux-user-Rewrite-target_shmat.patch \
           file://0005-tests-tcg-Check-that-shmat-does-not-break-proc-self-.patch \
           file://CVE-2023-6683.patch \
           file://qemu-guest-agent.init \
           file://qemu-guest-agent.udev \
           file://CVE-2024-3446-01.patch \
           file://CVE-2024-3446-02.patch \
           file://CVE-2024-3446-03.patch \
           file://CVE-2024-3446-04.patch \
           file://CVE-2024-3567.patch \
           file://0001-ui-gtk-skip-drawing-guest-scanout-when-associated-VC.patch \
           file://0002-ui-gtk-set-the-ui-size-to-0-when-invisible.patch \
           file://0003-ui-gtk-reset-visible-flag-when-window-is-minimized.patch \
           file://0004-ui-gtk-Disable-the-scanout-when-a-detached-tab-is-cl.patch \
           file://0005-ui-gtk-Factor-out-tab-window-creation-into-a-separat.patch \
           file://0006-ui-gtk-Add-a-new-parameter-to-assign-connectors-moni.patch \
           file://0007-ui-gtk-unblock-gl-if-draw-submitted-already-or-fence.patch \
           file://0008-ui-gtk-skip-drawing-if-any-of-ctx-surface-image-don-.patch \
           file://0009-ui-gtk-flush-display-pipeline-before-saving-vmstate-.patch \
           file://0010-virtio-gpu-first-surface-update-with-blob-scanout-af.patch \
           file://0011-ui-gtk-attach-fullscreen-hotkey-cb-to-new-vc-window.patch \
           file://0012-ui-gtk-properly-handling-detached-VC-window.patch \
           file://0013-virtio-gpu-replace-the-surface-with-null-surface-onl.patch \
           file://0014-ui-gtk-negative-page_number-shouldn-t-be-processed.patch \
           file://0015-ui-gtk-move-guest-mouse-cursor-after-host-cursor-hit.patch \
           file://0016-ui-gtk-fullscreen-control-on-all-QEMU-windows.patch \
           file://0017-ui-gtk-fullscreening-display-state-as-well.patch \
           file://0018-ui-gtk-adds-status-bar-for-expressing-ups-and-fps.patch \
           file://0019-virtio-gpu-call-dpy_gl_frame_counter-at-every-guest-.patch \
           file://0020-ui-gtk-Added-an-input-mode.patch \
           file://0021-usb-hid-added-new-type-for-touch-stylus.patch \
           file://0022-ui-gtk-Handle-relative-mode-events-correctly-with-Wa.patch \
           file://0023-ui-gtk-Consider-the-scaling-factor-when-getting-the-.patch \
           file://0024-ui-gtk-gl-area-Don-t-forget-to-calculate-the-scaling.patch \
           file://0025-virtio-gpu-Provide-position-info-x-y-to-the-Guest.patch \
           file://0026-ui-gtk-Include-the-position-info-while-setting-the-u.patch \
           file://0027-ui-gtk-enable-ungrabbing-fullscreened-widget.patch \
           file://0028-ui-spice-Add-an-option-for-users-to-provide-a-prefer.patch \
           file://0029-ui-spice-Enable-gl-on-option-for-non-local-or-remote.patch \
           file://0030-ui-spice-Submit-the-gl_draw-requests-at-60-FPS-for-r.patch \
           file://0031-Switch-audio-status-with-Guest-VM-switch-from-QMP-co.patch \
           file://0032-ui-gtk-Enable-delay-in-gd-configure-while-resize-win.patch \
           file://0033-ui-gtk-gd_ui_show-and-hide-only-when-ui_info-exists.patch \
           file://0034-ui-gtk-Regrabbing-only-on-the-VC-which-owned-it-befo.patch \
           file://0035-hw-display-virtio-gpu-udmabuf-dmabuf-fence_fd-should.patch \
           file://0036-virtio-gpu-Enabling-performance-mode-for-blob-true-c.patch \
           file://0037-gtk-untabifying-the-primary-window-as-well.patch \
           file://0038-ui-console-gl-Add-a-helper-to-create-a-texture-with-.patch \
           file://0039-ui-spice-Create-another-texture-with-linear-layout-w.patch \
           file://0040-ui-spice-Blit-the-scanout-texture-if-its-memory-layo.patch \
           "
UPSTREAM_CHECK_REGEX = "qemu-(?P<pver>\d+(\.\d+)+)\.tar"

# SDK_OLDEST_KERNEL is set below 4.17, which is the minimum version required by QEMU >= 8.1
# This is due to two MMAP flags being used at certain points
SRC_URI:append:class-nativesdk = " \
	file://0011-linux-user-workaround-for-missing-MAP_FIXED_NOREPLAC.patch \
	file://0012-linux-user-workaround-for-missing-MAP_SHARED_VALIDAT.patch \
        "

# Support building and using native version on pre 4.17 kernels
SRC_URI:append:class-native = " \
	file://0011-linux-user-workaround-for-missing-MAP_FIXED_NOREPLAC.patch \
	file://0012-linux-user-workaround-for-missing-MAP_SHARED_VALIDAT.patch \
        "

SRC_URI[sha256sum] = "8562751158175f9d187c5f22b57555abe3c870f0325c8ced12c34c6d987729be"

CVE_STATUS[CVE-2007-0998] = "not-applicable-config: The VNC server can expose host files uder some circumstances. We don't enable it by default."

# https://bugzilla.redhat.com/show_bug.cgi?id=1609015#c11
CVE_STATUS[CVE-2018-18438] = "disputed: The issues identified by this CVE were determined to not constitute a vulnerability."

# As per https://nvd.nist.gov/vuln/detail/CVE-2023-0664
# https://bugzilla.redhat.com/show_bug.cgi?id=2167423
CVE_STATUS[CVE-2023-0664] = "not-applicable-platform: Issue only applies on Windows"

# As per https://bugzilla.redhat.com/show_bug.cgi?id=2203387
CVE_STATUS[CVE-2023-2680] = "not-applicable-platform: RHEL specific issue."

CVE_STATUS[CVE-2023-3019] = "cpe-incorrect: Applies only against versions before 8.2.0"

CVE_STATUS[CVE-2023-5088] = "cpe-incorrect: Applies only against version 8.2.0 and earlier"

CVE_STATUS[CVE-2023-6693] = "cpe-incorrect: Applies only against version 8.2.0 and earlier"

COMPATIBLE_HOST:mipsarchn32 = "null"
COMPATIBLE_HOST:mipsarchn64 = "null"
COMPATIBLE_HOST:riscv32 = "null"

# Per https://lists.nongnu.org/archive/html/qemu-devel/2020-09/msg03873.html
# upstream states qemu doesn't work without optimization
DEBUG_BUILD = "0"

do_install:append() {
    # Prevent QA warnings about installed ${localstatedir}/run
    if [ -d ${D}${localstatedir}/run ]; then rmdir ${D}${localstatedir}/run; fi
}

do_install_ptest() {
	cp -rL ${B}/tests ${D}${PTEST_PATH}
	find ${D}${PTEST_PATH}/tests -type f -name "*.[Sshcodp]" | xargs -i rm -rf {}

	# Don't check the file genreated by configure
	sed -i -e "1s,#!/usr/bin/bash,#!${base_bindir}/bash," ${D}${PTEST_PATH}/tests/data/acpi/disassemle-aml.sh

	# Strip the paths from the QEMU variable, we can use PATH
	makfiles=$(find ${D}${PTEST_PATH} -name "*.mak")
	sed -i -e "s#^QEMU=.*/qemu-#QEMU=qemu-#g" $makfiles

	# Strip compiler flags as they break reproducibility
	sed -i -e "s,^CC=.*,CC=gcc," \
	       -e "s,^CCAS=.*,CCAS=gcc," \
	       -e "s,^LD=.*,LD=ld," $makfiles

	# Update SRC_PATH variable to the right place on target
	sed -i -e "s#^SRC_PATH=.*#SRC_PATH=${PTEST_PATH}#g" $makfiles

	# https://gitlab.com/qemu-project/qemu/-/issues/1403
	rm ${D}${PTEST_PATH}/tests/unit/test-io-channel-command
}

# QEMU_TARGETS is overridable variable
QEMU_TARGETS ?= "arm aarch64 i386 loongarch64 mips mipsel mips64 mips64el ppc ppc64 ppc64le riscv32 riscv64 sh4 x86_64"

EXTRA_OECONF = " \
    --prefix=${prefix} \
    --bindir=${bindir} \
    --includedir=${includedir} \
    --libdir=${libdir} \
    --mandir=${mandir} \
    --datadir=${datadir} \
    --docdir=${docdir}/${BPN} \
    --sysconfdir=${sysconfdir} \
    --libexecdir=${libexecdir} \
    --localstatedir=${localstatedir} \
    --with-suffix=${BPN} \
    --disable-strip \
    --disable-werror \
    --extra-cflags='${CFLAGS}' \
    --extra-ldflags='${LDFLAGS}' \
    --disable-download \
    --disable-docs \
    --host-cc='${BUILD_CC}' \
    --disable-af-xdp \
    ${PACKAGECONFIG_CONFARGS} \
    "

EXTRA_OECONF:append:class-target = " --cross-prefix=${HOST_PREFIX}"
EXTRA_OECONF:append:class-nativesdk = " --cross-prefix=${HOST_PREFIX}"

B = "${WORKDIR}/build"

#EXTRA_OECONF:append = " --python=${HOSTTOOLS_DIR}/python3"

do_configure:prepend:class-native() {
	# Append build host pkg-config paths for native target since the host may provide sdl
	BHOST_PKGCONFIG_PATH=$(PATH=/usr/bin:/bin pkg-config --variable pc_path pkg-config || echo "")
	if [ ! -z "$BHOST_PKGCONFIG_PATH" ]; then
		export PKG_CONFIG_PATH=$PKG_CONFIG_PATH:$BHOST_PKGCONFIG_PATH
	fi
}

do_configure() {
    export PKG_CONFIG=pkg-config
    ${S}/configure ${EXTRA_OECONF}
}
do_configure[cleandirs] += "${B}"

do_install () {
	export STRIP=""
	oe_runmake 'DESTDIR=${D}' install

	# If we built the guest agent, also install startup/udev rules
	if [ -e "${D}${bindir}/qemu-ga" ]; then
		install -d ${D}${sysconfdir}/init.d/
		install -m 0755 ${WORKDIR}/qemu-guest-agent.init ${D}${sysconfdir}/init.d/qemu-guest-agent
		sed -i 's:@bindir@:${bindir}:' ${D}${sysconfdir}/init.d/qemu-guest-agent

		install -d ${D}${sysconfdir}/udev/rules.d/
		install -m 0644 ${WORKDIR}/qemu-guest-agent.udev ${D}${sysconfdir}/udev/rules.d/60-qemu-guest-agent.rules

		install -d ${D}${systemd_unitdir}/system/
		install -m 0644 ${S}/contrib/systemd/qemu-guest-agent.service ${D}${systemd_unitdir}/system
		sed -i -e 's,-/usr/bin/,-${bindir}/,g' ${D}${systemd_unitdir}/system/qemu-guest-agent.service
	fi
	# ELF binary /usr/share/qemu/s390-netboot.img has relocations in .text
	rm ${D}${datadir}/qemu/s390-netboot.img -f
	# ELF binary /usr/share/qemu/s390-ccw.img has relocations in .text [textrel]
	rm ${D}${datadir}/qemu/s390-ccw.img -f
}

# The following fragment will create a wrapper for qemu-mips user emulation
# binary in order to work around a segmentation fault issue. Basically, by
# default, the reserved virtual address space for 32-on-64 bit is set to 4GB.
# This will trigger a MMU access fault in the virtual CPU. With this change,
# the qemu-mips works fine.
# IMPORTANT: This piece needs to be removed once the root cause is fixed!
do_install:append() {
	if [ -e "${D}/${bindir}/qemu-mips" ]; then
		create_wrapper ${D}/${bindir}/qemu-mips \
			QEMU_RESERVED_VA=0x0
	fi
}
# END of qemu-mips workaround

# Disable kvm/virgl/mesa on targets that do not support it
PACKAGECONFIG:remove:darwin = "kvm virglrenderer epoxy gtk+"
PACKAGECONFIG:remove:mingw32 = "kvm virglrenderer epoxy gtk+ pie"

PACKAGECONFIG[sdl] = "--enable-sdl,--disable-sdl,libsdl2"
PACKAGECONFIG[png] = "--enable-png,--disable-png,libpng"
PACKAGECONFIG[virtfs] = "--enable-virtfs --enable-attr --enable-cap-ng,--disable-virtfs,libcap-ng attr,"
PACKAGECONFIG[aio] = "--enable-linux-aio,--disable-linux-aio,libaio,"
PACKAGECONFIG[uring] = "--enable-linux-io-uring,--disable-linux-io-uring,liburing"
PACKAGECONFIG[xen] = "--enable-xen,--disable-xen,xen-tools,xen-tools-libxenstore xen-tools-libxenctrl xen-tools-libxenguest"
PACKAGECONFIG[vnc-sasl] = "--enable-vnc --enable-vnc-sasl,--disable-vnc-sasl,cyrus-sasl,"
PACKAGECONFIG[vnc-jpeg] = "--enable-vnc --enable-vnc-jpeg,--disable-vnc-jpeg,jpeg,"
PACKAGECONFIG[libcurl] = "--enable-curl,--disable-curl,curl,"
PACKAGECONFIG[nss] = "--enable-smartcard,--disable-smartcard,nss,"
PACKAGECONFIG[curses] = "--enable-curses,--disable-curses,ncurses,"
PACKAGECONFIG[gtk+] = "--enable-gtk,--disable-gtk,gtk+3 gettext-native"
PACKAGECONFIG[vte] = "--enable-vte,--disable-vte,vte gettext-native"
PACKAGECONFIG[libcap-ng] = "--enable-cap-ng,--disable-cap-ng,libcap-ng,"
PACKAGECONFIG[ssh] = "--enable-libssh,--disable-libssh,libssh,"
PACKAGECONFIG[gcrypt] = "--enable-gcrypt,--disable-gcrypt,libgcrypt,"
PACKAGECONFIG[nettle] = "--enable-nettle,--disable-nettle,nettle"
PACKAGECONFIG[libusb] = "--enable-libusb,--disable-libusb,libusb1"
PACKAGECONFIG[fdt] = "--enable-fdt,--disable-fdt,dtc"
PACKAGECONFIG[alsa] = "--audio-drv-list=default,,alsa-lib"
PACKAGECONFIG[epoxy] = "--enable-opengl,--disable-opengl,libepoxy"
PACKAGECONFIG[lzo] = "--enable-lzo,--disable-lzo,lzo"
PACKAGECONFIG[dax] = "--enable-libdaxctl,--disable-libdaxctl,ndctl"
PACKAGECONFIG[numa] = "--enable-numa,--disable-numa,numactl"
PACKAGECONFIG[gnutls] = "--enable-gnutls,--disable-gnutls,gnutls"
PACKAGECONFIG[bzip2] = "--enable-bzip2,--disable-bzip2,bzip2"
PACKAGECONFIG[libiscsi] = "--enable-libiscsi,--disable-libiscsi"
PACKAGECONFIG[kvm] = "--enable-kvm,--disable-kvm"
PACKAGECONFIG[virglrenderer] = "--enable-virglrenderer,--disable-virglrenderer,virglrenderer"
# spice will be in meta-networking layer
PACKAGECONFIG[spice] = "--enable-spice,--disable-spice,spice"
# usbredir will be in meta-networking layer
PACKAGECONFIG[dbus-display] = "--enable-dbus-display,--disable-dbus-display,glib-2.0-native,dbus"
PACKAGECONFIG[usb-redir] = "--enable-usb-redir,--disable-usb-redir,usbredir"
PACKAGECONFIG[snappy] = "--enable-snappy,--disable-snappy,snappy"
PACKAGECONFIG[glusterfs] = "--enable-glusterfs,--disable-glusterfs,glusterfs"
PACKAGECONFIG[xkbcommon] = "--enable-xkbcommon,--disable-xkbcommon,libxkbcommon"
PACKAGECONFIG[libudev] = "--enable-libudev,--disable-libudev,udev"
PACKAGECONFIG[attr] = "--enable-attr,--disable-attr,attr,"
PACKAGECONFIG[rbd] = "--enable-rbd,--disable-rbd,ceph,ceph"
PACKAGECONFIG[vhost] = "--enable-vhost-net,--disable-vhost-net,,"
PACKAGECONFIG[ust] = "--enable-trace-backends=ust,,lttng-ust,"
PACKAGECONFIG[pie] = "--enable-pie,--disable-pie,,"
PACKAGECONFIG[seccomp] = "--enable-seccomp,--disable-seccomp,libseccomp"
# libnfs is currently provided by meta-kodi
PACKAGECONFIG[libnfs] = "--enable-libnfs,--disable-libnfs,libnfs"
PACKAGECONFIG[pmem] = "--enable-libpmem,--disable-libpmem,pmdk"
PACKAGECONFIG[pulseaudio] = "--enable-pa,--disable-pa,pulseaudio"
PACKAGECONFIG[selinux] = "--enable-selinux,--disable-selinux"
PACKAGECONFIG[bpf] = "--enable-bpf,--disable-bpf,libbpf"
PACKAGECONFIG[capstone] = "--enable-capstone,--disable-capstone"
PACKAGECONFIG[rdma] = "--enable-rdma,--disable-rdma"
PACKAGECONFIG[vde] = "--enable-vde,--disable-vde"
PACKAGECONFIG[fuse] = "--enable-fuse --enable-fuse-lseek,--disable-fuse --disable-fuse-lseek,fuse3"
PACKAGECONFIG[slirp] = "--enable-slirp,--disable-slirp,libslirp"
PACKAGECONFIG[brlapi] = "--enable-brlapi,--disable-brlapi"
PACKAGECONFIG[jack] = "--enable-jack,--disable-jack,jack,"
PACKAGECONFIG[debuginfo] = "--enable-libdw,--disable-libdw,elfutils"
PACKAGECONFIG[pipewire] = "--enable-pipewire,--disable-pipewire,pipewire"
PACKAGECONFIG[sndio] = "--enable-sndio,--disable-sndio,sndio"

INSANE_SKIP:${PN}-common = "arch"

FILES:${PN} += "${datadir}/icons"

# For user who want to install all arch packages
PACKAGES =+ "${PN}-common"
RDEPENDS:${PN} += "${PN}-common"

ALLOW_EMPTY:${PN} = "1"
FILES:${PN} = ""

FILES:${PN}-common = "${bindir}/* ${includedir}/* ${libexecdir}/* ${datadir}/* ${localstatedir}"

PACKAGES_DYNAMIC += "^${PN}-user-.*  ^${PN}-system-.*"

PACKAGESPLITFUNCS =+ "split_qemu_packages"

python split_qemu_packages () {
    archdir = d.expand('${bindir}/')
    subpackages = do_split_packages(d, archdir, r'^qemu-system-(.*)$', '${PN}-system-%s', 'QEMU full system emulation binaries(%s)' , prepend=True, extra_depends='${PN}-common')

    subpackages += do_split_packages(d, archdir, r'^qemu-((?!system|edid|ga|img|io|nbd|pr-helper|storage-daemon).*)$', '${PN}-user-%s', 'QEMU full user emulation binaries(%s)' , prepend=True, extra_depends='${PN}-common')
    if subpackages:
        d.appendVar('RDEPENDS:' + d.getVar('PN'), ' ' + ' '.join(subpackages))
    mipspackage = d.getVar('PN') + "-user-mips"
    if mipspackage in ' '.join(subpackages):
        d.appendVar('RDEPENDS:' + mipspackage, ' ' + d.getVar("MLPREFIX") + 'bash')
}

# Put the guest agent in a separate package
PACKAGES =+ "${PN}-guest-agent"
SUMMARY:${PN}-guest-agent = "QEMU guest agent"
FILES:${PN}-guest-agent += " \
    ${bindir}/qemu-ga \
    ${sysconfdir}/udev/rules.d/60-qemu-guest-agent.rules \
    ${sysconfdir}/init.d/qemu-guest-agent \
    ${systemd_unitdir}/system/qemu-guest-agent.service \
"

INITSCRIPT_PACKAGES = "${PN}-guest-agent"
INITSCRIPT_NAME:${PN}-guest-agent = "qemu-guest-agent"
INITSCRIPT_PARAMS:${PN}-guest-agent = "defaults"

SYSTEMD_PACKAGES = "${PN}-guest-agent"
SYSTEMD_SERVICE:${PN}-guest-agent = "qemu-guest-agent.service"
