cmake_minimum_required(VERSION 3.27)
project(amplexus C)

set(CMAKE_C_STANDARD 17)

add_executable(amplexus main.c
        AmplexusTypes.h
        MoveGen.h
        MoveGen.c
        DataStructures.c
        DataStructures.h
        Tests.c
        Utilities.c
        Utilities.h
        DevUtilities.c
        DevUtilities.h)
