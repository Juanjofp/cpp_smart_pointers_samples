cmake_minimum_required(VERSION 3.28)

project(SmartPointers)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Common functions
add_subdirectory(src/common)

add_subdirectory(src/basics)
add_subdirectory(src/raw_pointers)
add_subdirectory(src/unique_pointer)
add_subdirectory(src/shared_ptr)
add_subdirectory(src/references)
add_subdirectory(src/move_semantic)

# Executable
add_executable(Smartpointers src/main.cpp)

# Add libcommon in the last postion to avoid linking errors
# because libcommon is a dependency for librawpointers and libuniquepointer and other libraries
target_link_libraries(
  Smartpointers
  PRIVATE
  libbasicconcepts
  librawpointers
  libuniquepointer
  libshared_pointers
  libreferences
  libmovesemantic
  libcommon
)