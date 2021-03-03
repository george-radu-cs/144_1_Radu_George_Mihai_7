cmake_minimum_required(VERSION 3.0)

project(project1 VERSION 1.0)

set(SOURCES nod.cpp lista_dublu_inltantuita.h lista_dublu_inltantuita.cpp)
add_executable(teste ${SOURCES} teste.cpp)
add_executable(project1 ${SOURCES} enums.h main.cpp)

target_compile_features(project1 PRIVATE cxx_lambda_init_captures)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
