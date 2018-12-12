#include <stdint.h>
#include <stdlib.h>
#include <tiffio.h>


int tiff_get_height(char* filename){
  TIFF *image;
  uint32 height;
  if(!TIFFGetField(image, TIFFTAG_IMAGELENGTH, &height)) {
    fprintf(stderr, "Failed to get height.\n");
    TIFFClose(image);
    return -1;
  }
  return (int) height;
}

int tiff_get_width(char* filename){
  TIFF *image;
  uint32 width;
  if(!TIFFGetField(image, TIFFTAG_IMAGEWIDTH, &width)) {
    fprintf(stderr, "Failed to get height.\n");
    TIFFClose(image);
    return -1;
  }
  TIFFClose(image);
  return (int) width;
}
