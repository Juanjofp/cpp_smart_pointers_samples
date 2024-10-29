message(STATUS "Unique Pointer")

# Add library
add_library(
  libuniquepointer
  src/unique_pointer.cpp
  src/test.cpp
  src/unique_container.cpp
)

target_include_directories(libuniquepointer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(libuniquepointer PRIVATE libcommon)
