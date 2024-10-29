#include "common.h"

#include <iostream>

void common::print_header(const std::string& header) {
  std::cout << std::endl;
  std::cout << "==============================" << std::endl;
  std::cout << header << std::endl;
  std::cout << "==============================" << std::endl;
  std::cout << std::endl;
}

void common::print_separator() {
  std::cout << "------------------------------" << std::endl;
}

void common::print(const std::string& message) {
  std::cout << message << std::endl;
}
