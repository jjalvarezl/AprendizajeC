cmake_minimum_required(VERSION 2.8)
project(Aprendizaje)

set (PARAMTYPES_SRC
    ParamTypes/Main.cpp
    ParamTypes/ParamTypes.cpp
    ParamTypes/ParamTypes.h
    )

set (STDBIND_SRC
    StdBind/StdBind.cpp
    StdBind/StdBind.h
    StdBind/Main.cpp
    )

# Paramtypes main
add_executable(ParamTypes ${PARAMTYPES_SRC})

# std::bind main
add_executable(StdBind ${STDBIND_SRC})

# Principal main
add_executable(${PROJECT_NAME} "main.cpp")
