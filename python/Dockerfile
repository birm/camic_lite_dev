FROM ubuntu:trusty

########################################
#
# openslide 3.4.1 image based on Ubuntu:trusty
#
#######################################

# Set Locale

RUN locale-gen en_US.UTF-8
ENV LANG en_US.UTF-8
ENV LANGUAGE en_US:en
ENV LC_ALL en_US.UTF-8

RUN echo deb http://archive.ubuntu.com/ubuntu precise universe multiverse >> /etc/apt/sources.list; \
    apt-get update -qq && apt-get install -y --force-yes \
    curl \
    wget \
    git \
    g++ \
    autoconf \
    automake \
    build-essential \
    checkinstall \
    cmake \
    pkg-config \
    zlib1g-dev \
    libopenjpeg-dev \
    libglib2.0-dev \
    libcairo2-dev \
    libgdk-pixbuf2.0-dev \
    libxml2-dev \
    libsqlite3-dev \
    libtiff4-dev \
    libpng-dev \
    libjpeg-dev \
    libjasper-dev \
    libgtk2.0-dev \
    libtool \
    python2.7 \
    python2.7-dev \
    python-pip \
    wget \
    unzip; \
    apt-get clean

WORKDIR /usr/local/src

RUN wget https://github.com/openslide/openslide/releases/download/v3.4.1/openslide-3.4.1.tar.gz
RUN tar -xvf openslide-3.4.1.tar.gz
WORKDIR /usr/local/src/openslide-3.4.1
RUN ./configure
RUN make
RUN make install
RUN ldconfig

# Remove all tmpfile
# =================================
WORKDIR /usr/local/
RUN rm -rf /usr/local/src
# =================================

RUN pip install openslide-python
RUN pip install pyinstaller
RUN mkdir /src
WORKDIR /src
COPY . /src
CMD pyinstaller util.py -y ; ls /src/dist/util
