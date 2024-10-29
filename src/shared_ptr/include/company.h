#pragma once

#include <memory>
#include <string>
#include <vector>

#include "employee.h"

using namespace std;

namespace shared_ptr_sample {

class Company {
 public:
  Company(const string &name);
  ~Company();

  void print() const;
  const string &get_name() const;

  void add_employee(const shared_ptr<Employee> &employee);

 private:
  // Company name
  string name;

  // Employees
  vector<shared_ptr<Employee>> employees;
};
}  // namespace shared_ptr_sample