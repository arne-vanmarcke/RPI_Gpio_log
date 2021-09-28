cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(gpioLog)

add_executable(gpioLog main.c)

include_directories(/usr/include/gpiod.h /usr/include/mariadb /usr/include/mariadb/mysql)

target_link_libraries(gpioLog gpiod mariadb)