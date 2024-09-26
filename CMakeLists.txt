# The following lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)

# Add a flag to specify if ESP32 should be used
# option(USE_ESP32 "Compile with ESP32 support" ON

if(ESP_PLATFORM)
    message(STATUS "Building with ESP32")
    include($ENV{IDF_PATH}/tools/cmake/project.cmake)
    project(Traffic_Light)
    
else()
    message(STATUS "Building without ESP32")
    project(Traffic_Light)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
    # inlude($ENV{CADMIUM}/include)
    add_subdirectory(main)
endif()