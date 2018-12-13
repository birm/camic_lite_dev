#include <stdint.h>
#include <stdlib.h>
#include <tiffio.h>


uint32 tiff_get_height(char* filename){
  TIFF *image = TIFFOpen(filename, "r");
  uint32 height;
  if(!TIFFGetField(image, TIFFTAG_IMAGELENGTH, &height)) {
    fprintf(stderr, "Failed to get height.\n");
    TIFFClose(image);
    return (uint32) -1;
  }
  return height;
}

uint32 tiff_get_width(char* filename){
  TIFF *image = TIFFOpen(filename, "r");
  uint32 width;
  if(!TIFFGetField(image, TIFFTAG_IMAGEWIDTH, &width)) {
    fprintf(stderr, "Failed to get height.\n");
    TIFFClose(image);
    return (uint32) -1;
  }
  TIFFClose(image);
  return width;
}

int tiff_get_dir(char *filename){
  TIFF *image = TIFFOpen(filename, "r");
  int dircount = -1;
  if (image) {
    dircount = 0;
    do {
      dircount++;
    } while (TIFFReadDirectory(image));
    printf("%d directories in %s\n", dircount, filename);
    TIFFClose(image);
  }
  return dircount;
}
