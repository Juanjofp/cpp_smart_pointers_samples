#include "unique_pointer.h"

#include <iostream>

#include "common.h"
#include "test.h"
#include "unique_container.h"

using unique_pointer::Test;
using unique_pointer::UniqueContainer;

// Smart Pointers are a type of pointer that manages the memory automatically.

void objectsInStack() {
  // Instance stored in the stack

  Test test{"Test in Stack"};

  test.print_me();

  // When the instance goes out of scope, the memory is automatically released
}

void objectsInHeap() {
  // Instance stored in the heap manually

  Test* test1{new Test("Test in Heap")};

  test1->print_me();

  // We need to delete the instance manually to avoid memory leaks

  delete test1;
}

void unique_pointer_sample() {
  // Unique Pointer

  // Unique pointers are smart pointers that cannot be copied but can be moved.
  // They are used to manage the memory of a single object.
  // When the unique pointer goes out of scope, the memory is automatically
  // released.

  std::unique_ptr<Test> test2{new Test("Test Unique Pointer old style")};
  test2->print_me();

  // We can also use the make_unique function

  std::unique_ptr<Test> test3{
      std::make_unique<Test>("Test Unique Pointer make_unique")};
  test3->print_me();

  // We can also use auto

  auto test4{std::make_unique<Test>("Test Unique Pointer auto")};
  test4->print_me();

  // We do not need to delete the instance manually
}

void passing_unique_pointer(std::unique_ptr<Test> test) { test->print_me(); }
void passing_pointer(Test* test) { test->print_me(); }

void using_unique_pointers() {
  auto test{std::make_unique<Test>("Test with Unique Pointer")};

  // auto test2 = test;  // Error: unique_ptr cannot be copied

  auto test2 = std::move(test);  // OK: unique_ptr can be moved
  test2->print_me();

  // passing_unique_pointers(test);  // Error: unique_ptr cannot be copied
  passing_pointer(
      test2.get());  // OK: raw pointer can be passed, but we need to manage the
                     // memory manually It can be dangerous because we can
                     // delete the instance twice

  passing_unique_pointer(std::move(test2));  // OK: unique_ptr can be moved

  // passing_pointer(test2.get());  // Error: test2 is null because it was moved
}

void reset_unique_pointer() {
  auto test{std::make_unique<Test>("Test with unique reset")};

  test->print_me();

  // Unique pointer is set to nullptr and resource is released

  test.reset();

  if (test == nullptr) {
    std::cout << "Test unique pointer is nullptr" << std::endl;
  }

  // Create a placeholder for a unique pointer

  std::unique_ptr<Test> placeholder{nullptr};

  auto test_to_move{
      std::make_unique<Test>("Test with unique to move to placeholder")};

  placeholder = std::move(test_to_move);
  placeholder->print_me();

  // placeholder can be reset with a new Raw pointer

  placeholder.reset(new Test{"Raw pointer for Test"});
  placeholder->print_me();
}

void unique_pointer_container() {
  {
    auto test{std::make_unique<Test>("Test Unique for container")};

    UniqueContainer container{test};
  }

  {
    auto test2{std::make_unique<Test>("Test 2 Unique for container")};

    UniqueContainer container2{test2.release()};
  }
}

void unique_pointer::unique_pointer_main() {
  common::print_header("Unique Pointers");

  // Objects in the stack

  objectsInStack();

  common::print_separator();

  // Objects in the heap manually

  objectsInHeap();

  common::print_separator();

  // Unique Pointer

  unique_pointer_sample();

  common::print_separator();

  // Using Unique Pointers

  using_unique_pointers();

  common::print_separator();

  // Reset unique pointers

  reset_unique_pointer();

  common::print_separator();

  // Container for unique pointer

  unique_pointer_container();
}
