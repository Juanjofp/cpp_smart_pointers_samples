#include <iostream>

#include "common.h"
#include "company.h"
#include "employee.h"
#include "person.h"
#include "shared_pointer.h"

using namespace shared_ptr_sample;

void basic_usage() {
  // Create a shared pointer to an integer
  shared_ptr<int> p1{make_shared<int>(42)};

  // Create a shared pointer to a Person object, old way
  // shared_ptr<Person> p2{new Person{"Juan", 43}};

  // Create a shared pointer to a Person object using make_shared
  shared_ptr<Person> maria{make_shared<Person>("Maria", 35)};

  // Create a shared pointer from another shared pointer
  shared_ptr<Person> maria_ptr{maria};

  // Create a shared pointer from a unique pointer
  unique_ptr<Person> pedro{make_unique<Person>("Pedro", 25)};
  shared_ptr<Person> pedro_shared{std::move(pedro)};
  shared_ptr<Person> pedro_shared_ptr{pedro_shared};

  // Reset a shared pointer to a new object
  pedro_shared.reset(new Person{"New Pedro", 26});

  // Reset a shared pointer to a nullptr
  pedro_shared_ptr.reset();

  // Create a shared pointer from a raw pointer
  // Person* p7{new Person{"Ana", 30}};
  // shared_ptr<Person> p8{p7};

  // Create a weak pointer from a shared pointer
  weak_ptr<Person> maria_weak{maria};

  // Create a shared pointer from a weak pointer using lock
  shared_ptr<Person> maria_from_weak{maria_weak.lock()};
  if (maria_from_weak) {
    cout << "Maria from weak pointer: ";
    maria_from_weak->print();
  } else {
    cout << "Maria from weak pointer is null" << endl;
  }

  // Create a shared pointer from a weak pointer using lock
  // using if to narrow the scope
  if (auto maria_from_weak2 = maria_weak.lock()) {
    cout << "Maria from weak pointer 2: ";
    maria_from_weak2->print();
  } else {
    cout << "Maria from weak pointer 2 is null" << endl;
  }

  // Check if weak pointer is expired
  if (maria_weak.expired()) {
    cout << "Maria weak pointer is expired" << endl;
  } else {
    cout << "Maria weak pointer is not expired" << endl;
  }
}

void sample_weak_pointer(shared_ptr<Company> &company_ptr) {
  common::print_header("Weak Pointers");

  auto company{company_ptr};

  {
    common::print_separator();

    shared_ptr<Employee> juan{std::make_shared<Employee>("Juan", 43, company)};

    company->add_employee(juan);

    shared_ptr<Employee> pedro{make_shared<Employee>("Pedro", 25, company)};

    company->add_employee(pedro);

    shared_ptr<Employee> maria{make_shared<Employee>("Maria", 35, company)};

    company->add_employee(maria);

    common::print_separator();
  }

  company->print();

  common::print_separator();
}

void shared_ptr_sample::sample_shared_ptr() {
  common::print_header("Shared Pointers");

  cout << "shared_ptr::sample_shared_ptr()" << endl;

  {
    // Create a shared pointer to a Person object
    shared_ptr<Person> juan{make_shared<Person>("Juan", 43)};

    // Create a shared pointer from another shared pointer
    shared_ptr<Person> juan_ptr{juan};
  }

  common::print_separator();

  { basic_usage(); }

  common::print_separator();

  {
    shared_ptr<Company> company{make_shared<Company>("Company")};

    sample_weak_pointer(company);

    company->print();

    common::print_separator();
  }
}