cmake_minimum_required(VERSION 3.10)
project(my-data-structure)

include_directories(${CMAKE_PROJECT_NAME} PUBLIC 
    ./include
)

aux_source_directory(./src SRC)

add_executable(${CMAKE_PROJECT_NAME} ${SRC})
