#include "input_sample.h"

#include <iostream>

#include "common.h"

using namespace std;

void basic_concepts::basic_input() {
  common::print_header("Basic Input");

  ask_user_input();

  common::print_separator();
}

void basic_concepts::ask_user_input() {
  int number;
  cout << "Enter a number: ";
  cin >> number;

  cout << "You entered: " << number << endl;
}