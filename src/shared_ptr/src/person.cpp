#include "person.h"

#include <iostream>

shared_ptr_sample::Person::Person(const string& name, int age)
    : name{name}, age{age} {
  cout << "Person::Person(" << name << ", " << age << ")" << endl;
}

shared_ptr_sample::Person::~Person() {
  cout << "Person::~Person(" << name << "," << age << ")" << endl;
}

void shared_ptr_sample::Person::print() const {
  cout << "Person::print(" << name << ", " << age << ")" << endl;
}
