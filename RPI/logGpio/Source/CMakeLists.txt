cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(logGpio)

add_executable(logGpio main.c)

include_directories(/usr/include/mariadb /usr/include/mariadb/mysql)

target_link_libraries(logGpio RPI mariadb)
