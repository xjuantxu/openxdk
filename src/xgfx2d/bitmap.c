// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : bitmap.c
// *
// * note : Simple 2D Bitmap library
// *
// ******************************************************************

#include <malloc.h>
#include <stdio.h>
#include "xgfx2d/bitmap.h"

Bitmap *create_bitmap(int w, int h)
{
	int dataSize = w*h*sizeof(uint32);
	void *block = malloc(sizeof(Bitmap) + dataSize);
	Bitmap *theBmp = block;
	theBmp->data = (uint32 *) ((char *)block + sizeof(Bitmap));
	theBmp->w = w;
	theBmp->h = h;
	theBmp->pitch = w;
	return theBmp;
}

void destroy_bitmap(Bitmap *bmp)
{
	free(bmp);
}

//UNTESTED, assuming standard Type 2 32-bit TGA files
// will probably load images upside down :D
Bitmap *load_tga(char *filename)
{
	HANDLE handle;
	char header[18];
	Bitmap *bmp;
	int w,h;
	int bpp;

	//"\\??\\D:\\test.tga"
	handle = _open(filename, _O_RDWR | _O_BINARY, 0 );
	
	_read(handle, header, 18);

	w = *(short *)(header+12);
	h = *(short *)(header+14);
	bpp = (int)header[16];

	if (bpp != 32)
	{
		_close(handle );
		return 0; //we need some format converters to read other bitdepths
	}

	bmp = create_bitmap(w,h);

	_read(handle, bmp->data, w*h*4);
	_close(handle );

	return bmp;
}