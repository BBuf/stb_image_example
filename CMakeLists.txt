# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

# Set the project name
project (image)

set(ENABLE_OPENCV OFF CACHE BOOL "Enable OpenCV support.")

if(ENABLE_OPENCV)
  find_package(OpenCV REQUIRED CONFIG)
  include_directories(${OpenCV_INCLUDE_DIRS})
  link_directories(${OpenCV_LIBRARY_DIRS})
endif()

# Create a sources variable with a link to all cpp files to compile
set(SOURCES main.cpp)

# Add an executable with the above sources
add_executable(image ${SOURCES})

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(image
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)
if(ENABLE_OPENCV)
target_link_libraries(image ${OpenCV_LIBS})
endif()
