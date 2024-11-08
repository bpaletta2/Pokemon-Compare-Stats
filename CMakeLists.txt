cmake_minimum_required(VERSION 3.15)
project(M3OEP)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(SOURCE_FILES main.cpp)
#set(PYTHON_FILES PythonOutput.py)

#add_executable(M3OEP ${SOURCE_FILES} ${PYTHON_FILES})
#target_link_libraries(M3OEP ${PYTHON_LIBRARIES})

add_executable(main main.cpp
        Trainer.cpp
        Pokemon.cpp)
