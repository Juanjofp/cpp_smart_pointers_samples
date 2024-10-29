message(STATUS "Common library")

# Add library
add_library(libcommon src/common.cpp)

target_include_directories(libcommon PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
