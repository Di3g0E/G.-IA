cmake_minimum_required(VERSION 3.24)
project(Grafos C)

set(CMAKE_C_STANDARD 99)

add_executable(Grafos main.c tElemento.h tElemento.c tGrafo.h tGrafo.c)
