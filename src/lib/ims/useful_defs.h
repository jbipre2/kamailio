/*
 * $Id$
 *
 * Copyright (C) 2012 Smile Communications, jason.penton@smilecoms.com
 * Copyright (C) 2012 Smile Communications, richard.good@smilecoms.com
 *
 * The initial version of this code was written by Dragos Vingarzan
 * (dragos(dot)vingarzan(at)fokus(dot)fraunhofer(dot)de and the
 * Fruanhofer Institute. It was and still is maintained in a separate
 * branch of the original SER. We are therefore migrating it to
 * Kamailio/SR and look forward to maintaining it from here on out.
 * 2011/2012 Smile Communications, Pty. Ltd.
 * ported/maintained/improved by
 * Jason Penton (jason(dot)penton(at)smilecoms.com and
 * Richard Good (richard(dot)good(at)smilecoms.com) as part of an
 * effort to add full IMS support to Kamailio/SR using a new and
 * improved architecture
 *
 * NB: Alot of this code was originally part of OpenIMSCore,
 * FhG Fokus.
 * Copyright (C) 2004-2006 FhG Fokus
 * Thanks for great work! This is an effort to
 * break apart the various CSCF functions into logically separate
 * components. We hope this will drive wider use. We also feel
 * that in this way the architecture is more complete and thereby easier
 * to manage in the Kamailio/SR environment
 *
 * This file is part of Kamailio, a free SIP server.
 *
 * Kamailio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * Kamailio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#define STR_SHM_DUP(dest,src,txt)\
{\
        if ((src).len==0) {\
                (dest).s=0;\
                (dest).len=0;\
        }else {\
                (dest).s = shm_malloc((src).len);\
                if (!(dest).s){\
                        LM_ERR("Error allocating %d bytes\n",(src).len);\
                        (dest).len = 0;\
                        goto out_of_memory;\
                }else{\
                        (dest).len = (src).len;\
                        memcpy((dest).s,(src).s,(src).len);\
                }\
        }\
}

#define STR_PKG_DUP(dest,src,txt)\
{\
        if ((src).len==0) {\
                (dest).s=0;\
                (dest).len=0;\
        }else {\
                (dest).s = pkg_malloc((src).len);\
                if (!(dest).s){\
                        LM_ERR("Error allocating %d bytes\n",(src).len);\
                        (dest).len = 0;\
                        goto out_of_memory;\
                }else{\
                        (dest).len = (src).len;\
                        memcpy((dest).s,(src).s,(src).len);\
                }\
        }\
}

#define STR_APPEND(dst,src)\
	{memcpy((dst).s+(dst).len,(src).s,(src).len);\
	(dst).len = (dst).len + (src).len;}
