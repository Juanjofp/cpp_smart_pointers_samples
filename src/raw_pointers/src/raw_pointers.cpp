#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "common.h"
#include "raw_pointers.h"

using std::string;

void raw_pointers::raw_pointers() {
  common::print_header("Regular Pointers");

  std::vector<string*> vec = {new string("Hello"), new string("World"),
                              new string("C++")};

  std::cout << "Vector address: " << &vec << std::endl;

  std::cout << "First element: " << *vec[0] << " in position " << vec[0]
            << std::endl;

  std::cout << "First element bis: " << *vec.at(0) << " in position "
            << vec.at(0) << std::endl;

  std::cout << "Length of first element: " << vec.at(0)->length() << std::endl;

  for (auto item : vec) {
    std::cout << "Element: " << *item << " in position " << item << std::endl;
  }

  // cbegin() returns a const_iterator pointing to the first element in the
  // vector cend() returns a const_iterator pointing to the element following
  // the last element in the vector begin() and end() are the same as cbegin()
  // and cend() but for non-const iterators

  for (auto item = vec.cbegin(); item != vec.cend(); ++item) {
    std::cout << "Element: " << **item << " in position " << *item << std::endl;
  }

  // rbegin() returns a reverse_iterator pointing to the last element in the
  // vector rend() returns a reverse_iterator pointing to the element preceding
  // the first element in the vector

  for (auto item = vec.crbegin(); item != vec.crend(); ++item) {
    std::cout << "Element: " << **item << " in position " << *item << std::endl;
  }

  // Free memory

  for (auto item : vec) {
    delete item;
  }

  vec.clear();

  // Maps

  std::map<int, string*> map = {{1, new string("Hello")},
                                {2, new string("World")},
                                {3, new string("C++")}};

  std::cout << "Map address: " << &map << std::endl;

  std::cout << "First element: " << *map[1] << " in position " << map[1]
            << std::endl;

  for (auto item : map) {
    std::cout << "Map Element: " << "Level: " << item.first
              << " Message: " << *item.second << " in position " << item.second
              << std::endl;
  }

  for (auto item = map.cbegin(); item != map.cend(); ++item) {
    std::cout << "Map Const Element: " << "Level: " << item->first
              << " Message: " << *item->second << " in position "
              << item->second << std::endl;
  }

  // Free memory

  for (auto item : map) {
    delete item.second;
  }

  map.clear();
}