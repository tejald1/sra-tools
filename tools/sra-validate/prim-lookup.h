/*===========================================================================
*
*                            PUBLIC DOMAIN NOTICE
*               National Center for Biotechnology Information
*
*  This software/database is a "United States Government Work" under the
*  terms of the United States Copyright Act.  It was written as part of
*  the author's official duties as a United States Government employee and
*  thus cannot be copyrighted.  This software/database is freely available
*  to the public for use. The National Library of Medicine and the U.S.
*  Government have not placed any restriction on its use or reproduction.
*
*  Although all reasonable efforts have been taken to ensure the accuracy
*  and reliability of the software and data, the NLM and the U.S.
*  Government do not and cannot warrant the performance or results that
*  may be obtained by using this software or data. The NLM and the U.S.
*  Government disclaim all warranties, express or implied, including
*  warranties of performance, merchantability or fitness for any particular
*  purpose.
*
*  Please cite the author in any work or product based on this material.
*
* ===========================================================================
*
*/

#ifndef _h_prim_lookup_
#define _h_prim_lookup_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _h_klib_rc_
#include <klib/rc.h>
#endif

#ifndef _h_klib_directory_
#include <kfs/directory.h>
#endif

#ifndef _h_prim_iter_
#include "prim-iter.h"  /* because of prim_rec */
#endif

struct prim_lookup;

typedef struct lookup_entry
{
    uint64_t seq_spot_id;
    uint32_t read_len;
    uint8_t seq_read_id, ref_orient;
} lookup_entry;

rc_t make_prim_lookup( struct prim_lookup ** lookup, KDirectory * dir, const char * tmp_file );
void destroy_prim_lookup( struct prim_lookup * self );

rc_t prim_lookup_enter( struct prim_lookup * self, const prim_rec * rec );

rc_t prim_lookup_get( struct prim_lookup * self, uint64_t align_id, lookup_entry * entry, bool * found );

#ifdef __cplusplus
}
#endif

#endif