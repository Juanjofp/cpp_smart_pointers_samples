#include "references.h"

#include <iostream>
#include <string>
#include <vector>

#include "common.h"

using namespace std;

struct Person {
  Person(std::string name, int age) : name(name), age(age) {
    cout << "Ctor: Person " << name << " created." << endl;
  }
  std::string name;
  int age;
};

void person_by_value(Person person) {
  person.name = "John";
  person.age = 30;
}

void person_by_reference(Person &person) {
  person.name = "John";
  person.age = 30;
}

Person &person_by_reference_return(Person &person) {
  person.name = "John";
  person.age = 30;
  return person;
}

Person person_by_reference_return_copy(Person &person) {
  person.name = "John";
  person.age = 30;
  return person;
}

// Person &person_by_reference_return_invalid() {
//   Person person = Person{"John", 30};
//   return person;  // Error: Reference to stack memory associated with local
//                   // variable 'person' returned
// }

Person &person_by_reference_return_valid() {
  // It should be returned as a pointer.

  Person *person = new Person{"John", 30};
  return *person;
}

void references_sample::sample_references() {
  common::print_header("References Samples");

  // References are a way to create an alias to a variable. It is a way to refer
  // to a variable by another name.
  // References are declared using the & operator.

  int a = 10;

  int &b = a;

  common::print_separator();

  // References are used to pass arguments to functions by reference, which
  // means that the function can modify the value of the argument. This avoids
  // the overhead of copying the value.

  Person alicia = Person{"Alice", 25};
  person_by_value(alicia);  // The original value is not modified. It is copied.
  person_by_reference(alicia);  // The original value is modified.

  common::print_separator();

  // References are also used to return values from functions by reference. This
  // avoids the overhead of copying the value.

  Person bob = Person{"Bob", 30};

  Person &john =
      person_by_reference_return(bob);  // The original value is modified.
  cout << "Person by reference return: " << john.name << " " << john.age
       << endl;

  Person john_copy =
      person_by_reference_return_copy(bob);  // The original value is copied.
  cout << "Person by reference return copy: " << john_copy.name << " "
       << john_copy.age << endl;

  common::print_separator();

  // Person &invalid_john = person_by_reference_return_invalid();

  Person &valid_john = person_by_reference_return_valid();

  cout << "Person by reference return valid pointer as ref: " << valid_john.name
       << " " << valid_john.age << endl;

  delete &valid_john;

  common::print_separator();

  // References cannot be null. It must be initialized when declared.

  // int &invalid_ref;  // Error: Reference variable 'invalid_ref' requires an
  // initializer

  // References cannot be re-assigned to refer to another variable.

  int c = 20;

  int &d = c;

  // d = a;  // Error: Non-const lvalue reference to type 'int' cannot bind to

  // References cannot be used to refer to a temporary value.

  // int &invalid_e = 10;  // Error: Cannot bind non-const lvalue reference of
  // type 'int&' to an rvalue of type 'int'

  common::print_separator();

  // An Array cannot contain references.

  // int &invalid_array[] = {a, b, c};  // Error: Array of references is not

  // References can be used to refer to elements of an array.
  // to avoid copying the value when iterating over an array.

  int array[] = {a, b, c};

  // Without references each element is copied.
  for (int &element : array) {
    cout << "Element: " << element << endl;
  }

  common::print_separator();

  // References can be const, which means that the value cannot be modified.
  // const references can refer to non-const values, but not the other way
  // around. You should use const_cast to remove the const qualifier.
  const int const_x = 10;

  // int &invalid_x_ref = x;  // Error: Cannot bind non-const lvalue reference
  // of type 'int&' to an rvalue of type 'int'

  int &x_ref = const_cast<int &>(const_x);

  x_ref = 20;

  cout << "x: " << const_x
       << endl;  // x is modified (watch in debuger) but
                 // print 10, may be compiler optimizations??.
  cout << "x_ref: " << x_ref << endl;  // x_ref is modified.

  common::print_separator();

  const string name = "Alice";

  // string &invalid_name_ref = name;  // Error: Cannot bind non-const lvalue
  // reference of type 'string&' to an rvalue of type 'string'

  string &name_ref = const_cast<string &>(name);

  name_ref = "Bob";

  cout << "name: " << name << endl;
  cout << "name_ref: " << name_ref << endl;

  common::print_separator();

  // Iterate a vector of string avoiding copying the value and using const
  // references to avoid modifying the value.

  vector<string> names{"Alice", "Bob", "Charlie"};

  for (const auto &name : names) {
    cout << "Name: " << name << endl;
  }
}