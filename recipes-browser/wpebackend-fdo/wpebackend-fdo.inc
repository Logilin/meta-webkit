SUMMARY = "WPE's backend based on a freedesktop.org stack."
HOMEPAGE = "https://github.com/Igalia/WPEBackend-fdo"
BUGTRACKER = "https://github.com/Igalia/WPEBackend-fdo/issues"

SRC_URI = "https://wpewebkit.org/releases/${BPN}-${PV}.tar.xz"

LICENSE = "BSD"
LIC_FILES_CHKSUM = "file://COPYING;md5=1f62cef2e3645e3e74eb05fd389d7a66"
DEPENDS = "glib-2.0 libxkbcommon wayland libepoxy libwpe"
DEPENDS:append:class-target = " wayland-native"
PROVIDES += "virtual/wpebackend"
RPROVIDES:${PN} += "virtual/wpebackend"

FILES_SOLIBSDEV = ""
FILES:${PN} += "${libdir}/libWPEBackend-fdo-*.so"
INSANE_SKIP:${PN} ="dev-so"

# wpebackend-fdo uses meson since (not branched yet)
#   https://github.com/Igalia/WPEBackend-fdo/commit/9c13d73bcc3726e2290c182d76d67b384f4c1318
inherit meson features_check pkgconfig

REQUIRED_DISTRO_FEATURES = "opengl"

