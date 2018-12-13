#include <stdint.h>
#include <stdlib.h>
#include <tiffio.h>


uint32 tiff_get_height(char* filename){
  TIFF *image;
  uint32 height;
  if(!TIFFGetField(image, TIFFTAG_IMAGELENGTH, &height)) {
    fprintf(stderr, "Failed to get height.\n");
    TIFFClose(image);
    return (uint32) -1;
  }
  return height;
}

uint32 tiff_get_width(char* filename){
  TIFF *image;
  uint32 width;
  if(!TIFFGetField(image, TIFFTAG_IMAGEWIDTH, &width)) {
    fprintf(stderr, "Failed to get height.\n");
    TIFFClose(image);
    return (uint32) -1;
  }
  TIFFClose(image);
  return width;
}
