#pragma once
#include <string>

using namespace std;

namespace shared_ptr_sample {
class Person {
 public:
  Person(const string& name, int age);
  virtual ~Person();

  virtual void print() const;

 private:
  string name;
  int age;
};
}  // namespace shared_ptr_sample