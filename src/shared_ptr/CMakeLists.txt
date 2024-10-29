message(STATUS "Shared pointers sample")

# Add library
add_library(
  libshared_pointers
  src/shared_pointers.cpp
  src/person.cpp
  src/employee.cpp
  src/company.cpp
)

target_include_directories(libshared_pointers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(libshared_pointers PRIVATE libcommon)
