#ifndef _LZMA_H_
#define _LZMA_H_

#include "LzmaDecode.h"
#include "../miniclib.h"

/* prototypes for our read function */
typedef void * gzFile;
int gzread(gzFile file, void * buf, unsigned len);

_fsize64_t g_totalRead;

/* holds any information needed about stream */
struct LZMAFile;
typedef struct LZMAFile LZMAFile;

/* routines implemented */
int lzma_init(gzFile infile, struct LZMAFile **lzmaFile);
void lzma_cleanup(struct LZMAFile *lzmaFile);
long lzma_read(struct LZMAFile *lzmaFile,
               unsigned char *buffer,
			   unsigned len,
			   _fsize64_t *bytesRead);

#endif /* _LZMA_H_ */
