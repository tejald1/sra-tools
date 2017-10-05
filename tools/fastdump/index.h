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

#ifndef _h_index_
#define _h_index_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _h_klib_rc_
#include <klib/rc.h>
#endif

#ifndef _h_klib_text_
#include <klib/text.h>
#endif

#ifndef _h_kfs_directory_
#include <kfs/directory.h>
#endif

#define DFLT_INDEX_FREQUENCY 20000

struct index_writer;

void release_index_writer( struct index_writer * writer );
rc_t make_index_writer( KDirectory * dir, struct index_writer ** writer,
                        size_t buf_size, uint64_t frequency, const char * fmt, ... );
rc_t write_key( struct index_writer * writer, uint64_t key, uint64_t offset );

struct index_reader;

void release_index_reader( struct index_reader * reader );
rc_t make_index_reader( KDirectory * dir, struct index_reader ** reader,
                        size_t buf_size, const char * fmt, ... );
rc_t get_nearest_offset( const struct index_reader * reader, uint64_t key_to_find,
                   uint64_t * key_found, uint64_t * offset );

rc_t get_max_key( const struct index_reader * reader, uint64_t * max_key );

#ifdef __cplusplus
}
#endif

#endif
