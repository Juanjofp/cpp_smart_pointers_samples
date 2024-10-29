#include "company.h"

#include <iostream>

shared_ptr_sample::Company::Company(const string& name) : name{name} {
  cout << "Company::Company(" << name << ")" << endl;
}

shared_ptr_sample::Company::~Company() {
  cout << "Company::~Company()" << endl;
}

void shared_ptr_sample::Company::print() const {
  cout << "Company::print()" << endl;

  cout << "Company name: " << name << endl;

  cout << "Employees: " << employees.size() << endl;

  for (const auto& employee : employees) {
    employee->print();
  }
}

const string& shared_ptr_sample::Company::get_name() const { return name; }

void shared_ptr_sample::Company::add_employee(
    const shared_ptr<Employee>& employee) {
  employees.push_back(employee);
}
