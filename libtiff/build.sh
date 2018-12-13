#!/bin/bash
LIBTIFF_VERSION=4.0.10

PREFIX=`pwd`/local
mkdir ${PREFIX}

curl -O http://download.osgeo.org/libtiff/tiff-${LIBTIFF_VERSION}.tar.gz
tar xzvf tiff-${LIBTIFF_VERSION}.tar.gz
cd tiff-${LIBTIFF_VERSION}
patch -u libtiff/tiff.h < ../tiff_h_int_size.patch
emconfigure ./configure --prefix=${PREFIX}
emmake make
emmake make install
cd ../

emcc test.c \
     ./local/lib/libtiff.a \
     -I./local/include \
     -s EXPORTED_FUNCTIONS="['_tiff_get_width', '_tiff_get_height']" \
     -s EXTRA_EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]' \
     -s FORCE_FILESYSTEM=1 \
     -o tifinfo.js
