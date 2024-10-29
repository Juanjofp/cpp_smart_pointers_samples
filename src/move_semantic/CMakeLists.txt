message(STATUS "Move semantic")

# Add library
add_library(
  libmovesemantic
  src/move_semantic.cpp
  src/meeting.cpp
  src/heavy_resource.cpp
  src/resource_manager.cpp
)

target_include_directories(
  libmovesemantic
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(
  libmovesemantic
  PRIVATE
  libcommon
)