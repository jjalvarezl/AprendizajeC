cmake_minimum_required(VERSION 2.8)
project(Aprendizaje)

set (PARAMTYPES_SRC
    ParamTypes/Main.cpp
    ParamTypes/ParamTypes.cpp
    ParamTypes/ParamTypes.h
    )

set (FUNCTORS_SRC
    Functors/AddVectors.cpp
    Functors/AddVectors.h
    Functors/Functors.cpp
    Functors/Functors.h
    Functors/LambdaCall.cpp
    Functors/LambdaCall.h
    Functors/Main.cpp
    Functors/StdBind.cpp
    Functors/StdBind.h
    Functors/Vector.cpp
    Functors/Vector.h
    )

set (SMARTPOINTERS_SRC
    SmartPointers/SmartPointers.cpp
    SmartPointers/SmartPointers.h
    SmartPointers/Song.cpp
    SmartPointers/Song.h
    SmartPointers/Main.cpp
    )

set (RVALUEREFERENCES_SRC
    RValueReferences/RValueReferences.cpp
    RValueReferences/RValueReferences.h
    RValueReferences/Main.cpp
    )

# ParamTypes main
add_executable(ParamTypes ${PARAMTYPES_SRC})

# StdBind main
add_executable(Functors ${FUNCTORS_SRC})

# SmartPointers main
add_executable(SmartPointers ${SMARTPOINTERS_SRC})

# RValueReferences main
add_executable(RValueReferences ${RVALUEREFERENCES_SRC})

# Principal main
add_executable(${PROJECT_NAME} "main.cpp")
