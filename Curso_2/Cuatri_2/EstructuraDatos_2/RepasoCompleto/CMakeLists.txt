cmake_minimum_required(VERSION 3.24)
project(RepasoCompleto)

set(CMAKE_CXX_STANDARD 23)

add_executable(RepasoCompleto main.cpp BinaryTree.h LinkedTree.h LCRSTree.h BasicGraph.h ../Códigos/EvenPosIterator-Codigo_iteradores.cpp)
