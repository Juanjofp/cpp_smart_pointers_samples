message(STATUS "Raw Pointers")

# Add library
add_library(librawpointers src/raw_pointers.cpp)

target_include_directories(librawpointers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(librawpointers PRIVATE libcommon)
