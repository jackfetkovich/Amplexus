cmake_minimum_required(VERSION 3.27)
project(amplexus C)

set(CMAKE_C_STANDARD 17)

add_executable(amplexus src/main.c
        src/AmplexusTypes.h
        src/MoveGen.h
        src/MoveGen.c
        src/DataStructures.c
        src/DataStructures.h
        src/Utilities.c
        src/Utilities.h
        src/DevUtilities.c
        src/DevUtilities.h
        src/test.c)
