cmake_minimum_required(VERSION 3.0)
project(Helper)

add_library(Helper SHARED
        src/ResourceManager/ResourceManager.cpp
        src/FileSystem/FileSystem.cpp
        src/ResourceManager/IResource.cpp
        src/Debug/Debug.cpp
        )

target_include_directories(Helper PUBLIC inc)