cmake_minimum_required(VERSION 3.27)
project(amplexus C)

set(CMAKE_C_STANDARD 17)

add_executable(amplexus main.c
        AmplexusTypes.h
        Amplexus.h
        Amplexus.c
        DataStructures.c
        DataStructures.h
        Tests.c)
