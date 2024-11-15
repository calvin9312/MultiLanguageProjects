cmake_minimum_required(VERSION 3.14)

project(Lexer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Lexer
  main.cpp
)

include(GNUInstallDirs)
