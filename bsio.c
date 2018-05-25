//------------------------------------------------------------------------+
#include <bzlib.h>

#include "utils.h"

static unsigned long refcount = 0;

//------------------------------------------------------------------------+
int bsio_Read(int * bzerror, void * b, void * buf, int len)
{
	return BZ2_bzRead(bzerror, b, buf, len);
}

//------------------------------------------------------------------------+
void * bsio_ReadOpen(int * bzerror, FILE * f, int verbosity, int small,
		void * unused, int nUnused)
{
	return BZ2_bzReadOpen(bzerror, f, verbosity, small, unused, nUnused);
}

//------------------------------------------------------------------------+
void bsio_ReadClose(int * bzerror, void * b)
{
	BZ2_bzReadClose(bzerror, b);
}

//------------------------------------------------------------------------+
void bsio_Write(int * bzerror, void * b, void * buf, int len)
{
	printf("%s: refcount: %lu\n", __FUNCTION__, refcount);
	hexdump(buf, len);
	refcount++;
	printf("\n");

	BZ2_bzWrite(bzerror, b, buf, len);
}

//------------------------------------------------------------------------+
void* bsio_WriteOpen(int * bzerror, FILE * f,int blockSize100k,
		int verbosity, int workFactor)
{
	return BZ2_bzWriteOpen(bzerror, f, blockSize100k, verbosity,
			workFactor);
}

//------------------------------------------------------------------------+
void bsio_WriteClose(int * bzerror, void * b, int abandon,
		unsigned int * nbytes_in, unsigned int * nbytes_out)
{
	BZ2_bzWriteClose(bzerror, b, abandon, nbytes_in, nbytes_out);
}
