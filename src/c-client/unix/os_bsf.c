/* ========================================================================
 * Copyright 2008-2009 Mark Crispin
 * Copyright 1988-2008 University of Washington
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * ========================================================================
 */

/*
 * Program:	Operating-system dependent routines -- FreeBSD version
 *
 * Author:	Mark Crispin
 *
 * Date:	1 August 1988
 * Last Edited:	18 May 2009
 */

#include "tcp_unix.h" /* must be before osdep includes tcp.h */
#include "mail.h"
#include "osdep.h"
#include <stdio.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ctype.h>
#include <errno.h>
#include <pwd.h>
#include "misc.h"

#include "fs_unix.c"
#include "ftl_unix.c"
#include "nl_unix.c"
#include "env_unix.c"
#include "getspnam.c"
#define fork vfork
#include "tcp_unix.c"
#include "gr_waitp.c"
#include "tz_bsd.c"
#include "utime.c"
