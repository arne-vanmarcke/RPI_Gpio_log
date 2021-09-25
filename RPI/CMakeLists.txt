cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project (RPI)

add_library(RPI RPI.c)

install (TARGETS RPI DESTINATION lib)

install (FILES RPI.h DESTINATION include)
