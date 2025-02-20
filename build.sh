#!/bin/bash

# Compiler options
CC=g++
CFLAGS="-O1 -Wall -std=c++17 -Wno-missing-braces"

# Paths
INCLUDE_DIR="include/"
LIB_DIR="lib/"

# Build command
$CC main.cpp $LIB_DIR/libraylib.mac.a -o app $CFLAGS -I $INCLUDE_DIR -L $LIB_DIR -lraylib.mac -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
./app