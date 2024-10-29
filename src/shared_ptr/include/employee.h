#pragma once

#include <memory>

#include "person.h"

namespace shared_ptr_sample {
class Company;

class Employee : public Person {
 public:
  Employee(const string &name, int age, const std::weak_ptr<Company> &company);
  ~Employee();

  void print() const override;

 private:
  std::weak_ptr<Company> company;
};
}  // namespace shared_ptr_sample