#!/bin/bash

#Checking if Linux is 32 or 64-bit based on integer overflow

if ((1<<32)); then
  echo 64 bit architecture
else
  echo 32 bit architecture
fi
