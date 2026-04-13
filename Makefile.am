# Copyright (c) 2024, Qualcomm Innovation Center, Inc. All rights reserved.
# SPDX-License-Identifier: BSD-3-Clause

QMIF_CPPFLAGS = @QMIF_CFLAGS@
QMIF_LDADD = @QMIF_LIBS@

AM_CFLAGS = -Wundef \
        -Wstrict-prototypes \
        -Wno-trigraphs \
        -g -O0 \
        -fno-inline \
        -fno-short-enums \
        -fpic \
        $(QMIF_CPPFLAGS) \
        -I.

h_sources = ./time_service_v01.h \
            ./localdefs.h \
            ./time_genoff_i.h

requiredlibs = $(QMIF_LDADD)

bin_PROGRAMS = time_daemon
time_daemon_SOURCES = time_daemon.c time_service_v01.c
time_daemon_LDADD = $(requiredlibs)
time_daemon_LDFLAGS = -lpthread  @GLIB_LIBS@
