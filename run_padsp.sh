#!/bin/bash
LD_PRELOAD_BACKUP=$LD_PRELOAD
export LD_PRELOAD=$(pwd)/pulseaudio/src/.libs/libpulsedsp.so
./pulseaudio/src/padsp $1
LD_PRELOAD=$LD_PRELOAD_BACKUP