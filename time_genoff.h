// Copyright (c) 2024, Qualcomm Innovation Center, Inc. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#ifndef TIME_GENOFF_H
#define TIME_GENOFF_H

#define OFFSET_LOCATION "/var/lib/time"
#define MAX_CB_FUNC              10
#define TIME_GENOFF_REMOTE_UPDATE_MS  10
#define TIME_GENOFF_UPDATE_THRESHOLD_MS 10
#define GENOFF_SOCKET_NAME	"#time_genoff"
#define GENOFF_MAX_CONCURRENT_CONN	4

#define SEC_TO_MSEC(s)	((s) * 1000ULL)
#define MSEC_TO_SEC(s)	((s) / 1000ULL)
#define USEC_TO_MSEC(s)	((s) / 1000ULL)
#define NSEC_TO_MSEC(s)	((s) / 1000000ULL)
#define	MODEM_EPOCH_DIFFERENCE	 315964800
#define ATS_MAX		ATS_TOD_GEN + 1
#define FILE_NAME_MAX	100

/* Dividend of factor to multiply for converting sclk to cx32 */
#define TIME_CONV_SCLK_CX32_DIVIDEND 256
/* Divisor of factor to multiply for converting sclk to cx32 */
#define TIME_CONV_SCLK_CX32_DIVISOR 125
/* Conversion from cx32 to 1.25ms */
#define TIME_CONV_CX32_PER_1p25MS 0xC000

/* Indication message ID's to turn On/Off
 *
 * TIME_SERVICE_ATS_RTC_IND_MSG (0) --  Indication message for RTC offset update.
 * TIME_SERVICE_ATS_TOD_IND_MSG (1) --  Indication message for TOD offset update.
 * TIME_SERVICE_ATS_USER_IND_MSG (2) --  Indication message for USER offset update.
 * TIME_SERVICE_ATS_SECURE_IND_MSG (3) --  Indication message for SECURE offset update.
 * TIME_SERVICE_ATS_DRM_IND_MSG (4) --  Indication message for DRM offset update.
 * TIME_SERVICE_ATS_USER_UTC_IND_MSG (5) --  Indication message for USER_UTC offset update.
 * TIME_SERVICE_ATS_USER_TZ_DL_IND_MSG (6) --  Indication message for USER_TZ_DL offset update.
 * TIME_SERVICE_ATS_GPS_IND_MSG (7) --  Indication message for GPS offset update.
 * TIME_SERVICE_ATS_1X_IND_MSG (8) --  Indication message for 1X offset update.
 * TIME_SERVICE_ATS_HDR_IND_MSG (9) --  Indication message for HDR offset update.
 * TIME_SERVICE_ATS_WCDMA_IND_MSG (10) --  Indication message for WCDMA offset update.
 * TIME_SERVICE_ATS_MFLO_IND_MSG (11) --  Indication message for MFLO offset update.
 * TIME_SERVICE_ATS_3GPP_IND_MSG (12) --  Indication message for 3GPP offset update.
 * TIME_SERVICE_ATS_UTC_IND_MSG (13) --  Indication message for UTC offset update.
 * TIME_SERVICE_ATS_LTE_HR_IND_MSG (14) --  Indication message for LTE_HR offset update.
 * TIME_SERVICE_ATS_LTE_HR_GPS_IND_MSG (15) --  Indication message for LTE_HR_GPS offset update.
 * TIME_SERVICE_ATS_WLAN_IND_MSG (16) --  Indication message for WLAN offset update.
 * TIME_SERVICE_ATS_5G_IND_MSG (17) --  Indication message for 5G offset update.
 * TIME_REMOTE_QTIMER_TIMESTAMP_DELTA_IND_MSG (18) --  Indication message for qtimer delta update.
*/
#define TIME_SERVICE_ATS_3GPP_IND_MSG 12

enum time_persistant_operation {
	TIME_READ_MEMORY,
	TIME_WRITE_MEMORY
} time_persistant_opr_type;

/* Time Generic Offset 'type 1' callback function */
int (*time_genoff_t1_cb_type)(void);

struct time_genoff_per_storage {
	/* Mark as TRUE if persistent storage is needed */
	uint8_t initialized;
	/* file name for efs item file */
	char f_name[100];
	/* Threshold in ms for writing back in efs item file */
	int64_t threshold;
} ;

/* Time Generic Offset pointer type */
// struct time_genoff_struct *time_genoff_ptr;

struct time_genoff_struct {
	/* Generic Offset, always stored in ms */
	int64_t generic_offset;
	/* Flag to indicate if time-of-day has ever been set before */
	uint8_t initialized;
	/* Time base Type */
	time_bases_type bases_type;
	/* Initialization Sequence */
	int (*init_func)(void);
	/* Mark if subsys based on another subsys */
	uint8_t reqd_base_genoff;
	/* Base Subsys */
	time_bases_type subsys_base;
	/* Specification for persistent storage */
	struct time_genoff_per_storage    per_storage_spec;
} ;

struct send_recv_struct {
	uint32_t base;
	uint32_t unit;
	uint32_t operation;
	uint64_t value;
	int result;
};

struct time_genoff_info {
	time_bases_type base;		/* Genoff in consideration */
	void *ts_val;			/* Time to be set/get */
	time_unit_type unit;		/* Time unit */
	time_genoff_opr_type operation; /* Time operation to be done */
} ;


#endif /* TIME_GENOFF_I_H */
