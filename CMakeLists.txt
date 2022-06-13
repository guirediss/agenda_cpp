cmake_minimum_required(VERSION 3.5)

project(agenda_poo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(agenda_poo
    main.cpp
    agenda.cpp
    agenda.h
    agendaprograma.cpp
    agendaprograma.h
    )
