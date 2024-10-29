message(STATUS "Sample References")

# Add library
add_library(libreferences src/references.cpp)

target_include_directories(libreferences PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(libreferences PRIVATE libcommon)
