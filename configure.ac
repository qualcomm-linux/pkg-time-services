# Copyright (c) 2024, Qualcomm Innovation Center, Inc. All rights reserved.
# SPDX-License-Identifier: BSD-3-Clause

# Requires autoconf tool later than 2.61
AC_PREREQ(2.61)
# Initialize the qmi-framework package version 0.1.1
AC_INIT([time-services],0.1.1)
# Does not strictly follow GNU Coding standards
AM_INIT_AUTOMAKE([foreign])
# Disables auto rebuilding of configure, Makefile.ins
AM_MAINTAINER_MODE
# Verifies the --srcdir is correct by checking for the path
AC_CONFIG_SRCDIR([time_daemon.c])
# defines some macros variable to be included by source
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AC_PROG_CC
AM_PROG_CC_C_O
AC_PROG_LIBTOOL
AC_PROG_AWK
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
PKG_PROG_PKG_CONFIG

# Checks for libraries with user.
AC_ARG_WITH([qmi-prefix],
    [AS_HELP_STRING([--with-qmi-prefix=PATH],
     [Fallback path to qmi-framework if pkg-config cannot find it])],
    [QMIF_PREFIX=$withval], [QMIF_PREFIX=])
PKG_CHECK_MODULES([QMIF], [qmi-framework],
    [QMIF_CFLAGS="-I`$PKG_CONFIG --variable=prefix qmi-framework`/include/qmi_framework"],
    [AS_IF([test -n "$QMIF_PREFIX"],
        [QMIF_CFLAGS="-I${QMIF_PREFIX}/include/qmi_framework"
         QMIF_LIBS="-L${QMIF_PREFIX}/lib -lqcci -lqcsi -lqencdec -lqmi_common"],
        [AC_MSG_ERROR([qmi-framework not found via pkg-config and --with-qmi-prefix not specified])])])
AC_SUBST([QMIF_CFLAGS])
AC_SUBST([QMIF_LIBS])
CFLAGS="$CFLAGS  -DSYSLOG_ENABLE"

AC_DEFINE(ENABLE_USEGLIB, 1, [Define if HLOS systems uses glib])
PKG_CHECK_MODULES(GLIB, glib-2.0 >= 2.16, dummy=yes, AC_MSG_ERROR(GLib >= 2.16 is required))
GLIB_LIBS="$GLIB_LIBS $GTHREAD_LIBS"
AC_SUBST(GLIB_LIBS)


AC_CONFIG_FILES([ \
        Makefile \
        ])
AC_OUTPUT
