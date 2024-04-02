cmake_minimum_required(VERSION 3.27)
project(GestorContactos)

set(CMAKE_CXX_STANDARD 23)

add_executable(GestorContactos main.cpp
        menuPrincipal.cpp
        menuPrincipal.h
        menuTerminal.cpp
        menuTerminal.h
        menuReportes.cpp
        menuReportes.h
        menuGraficas.cpp
        menuGraficas.h
        menuArchivos.cpp
        menuArchivos.h)
