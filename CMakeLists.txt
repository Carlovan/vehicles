cmake_minimum_required(VERSION 3.10)
project(Vehicles VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

##
## Install packages with Conan
##

# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
                  "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_check(REQUIRED)
conan_add_remote(NAME bincrafters
                 URL https://api.bintray.com/conan/bincrafters/public-conan)
conan_cmake_install(PATH_OR_REFERENCE ${CMAKE_SOURCE_DIR}/conanfile.txt
                    BUILD missing)

set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
find_package(sfml)

##
## Executable
##

add_subdirectory(libs)

add_executable(Vehicles main.cpp)
target_link_libraries(Vehicles PUBLIC sfml::sfml VehiclesLib)
