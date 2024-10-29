message(STATUS "Basic conpects")

# Add library
add_library(
  libbasicconcepts
  src/basic_concepts.cpp
  src/enum.cpp
  src/input_sample.cpp
)

target_include_directories(
  libbasicconcepts
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(
  libbasicconcepts
  PRIVATE
  libcommon
)