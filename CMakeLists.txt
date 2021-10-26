cmake_minimum_required(VERSION 3.21)
project(Physical_Modelling_Percussion_Example_1 C)

set(CMAKE_C_STANDARD 99)

add_executable(Physical_Modelling_Percussion_Example_1 main.c)

target_link_libraries(Physical_Modelling_Percussion_Example_1
        PRIVATE
        m)

