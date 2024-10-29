#include "employee.h"

#include <iostream>

#include "company.h"

shared_ptr_sample::Employee::Employee(const string &name, int age,
                                      const weak_ptr<Company> &company)
    : Person{name, age}, company{company} {
  cout << "Employee::Employee(" << name << ", " << age << ") working for: ";
  if (auto company_ptr = company.lock()) {
    cout << company_ptr->get_name();
  } else {
    cout << "No company";
  }

  cout << endl;
}

shared_ptr_sample::Employee::~Employee() {
  cout << "Employee::~Employee()" << endl;

  if (auto company_ptr = company.lock()) {
    company_ptr->print();
  }
}

void shared_ptr_sample::Employee::print() const {
  cout << "Employee::print() ";

  if (auto company_ptr = company.lock()) {
    cout << "Company: " << company_ptr->get_name() << endl;
  }

  Person::print();

  cout << endl;
}
