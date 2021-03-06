/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License (the "License").
 * You may not use this file except in compliance with the License.
 *
 * You can obtain a copy of the license at src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */

/*
 * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

/* Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T */
/* All Rights Reserved */

/*	from OpenSolaris "qstrdup.c	1.10	06/11/17 SMI"	*/

/*
 * Portions Copyright (c) 2007 Gunnar Ritter, Freiburg i. Br., Germany
 *
 * Sccsid @(#)qstrdup.c	1.2 (gritter) 2/24/07
 */

/*LINTLIBRARY*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <locale.h>
#include <libintl.h>
#include <pkglib.h>
#include <libinst.h>

#define	ERR_MEMORY	"memory allocation failure, errno=%d"

char *
qstrdup(char *s)
{
	register char *pt = NULL;

	if (s && *s) {
		pt = calloc((strlen(s) + 1), sizeof (char));
		if (pt == NULL) {
			progerr(gettext(ERR_MEMORY), errno);
			quit(99);
		}
		(void) strcpy(pt, s);
	}
	return (pt);
}
