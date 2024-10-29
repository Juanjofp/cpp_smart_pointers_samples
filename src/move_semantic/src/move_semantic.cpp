#include "move_semantic.h"

#include <iostream>
#include <memory>

#include "common.h"
#include "meeting.h"
#include "resource_manager.h"

using namespace move_semantic;

double double_salary(double salary) { return salary * 2; }

double compute_bonus(double salary, double percent) {
  double bonus = salary + salary * percent / 100;

  return bonus;
}

void basic_right_value_reference() {
  double salary = 1000.0;

  double expenses = 500.0;

  double &new_expenses = expenses;

  const double &new_salary = double_salary(salary);

  const double &bonus = compute_bonus(salary, 10);

  std::cout << "Salary: " << salary << std::endl;
  std::cout << "Expenses: " << expenses << std::endl;
  std::cout << "New Expenses: " << new_expenses << std::endl;

  std::cout << "New Salary: " << new_salary << std::endl;
  std::cout << "Bonus: " << bonus << std::endl;

  double &&new_expenses_rvalue = compute_bonus(salary, 10);

  std::cout << "New Expenses R-Value: " << new_expenses_rvalue << std::endl;

  double &&new_salary_rvalue = double_salary(salary);

  std::cout << "New Salary R-Value: " << new_salary_rvalue << std::endl;

  new_salary_rvalue = 8000.0;

  std::cout << "New Salary R-Value: " << new_salary_rvalue << std::endl;
}

void basic_rule_of_five() {
  common::print_header(">>> Rule of Five");

  common::print_separator();

  ResourceManager resource_manager{"Resource Manager"};

  common::print(">>> Copy Constructor");

  ResourceManager resource_manager_copy{resource_manager};

  common::print(">>> Copy Assignment Operator");

  ResourceManager resource_manager_copy_assignment{"Second Resource Manager"};
  resource_manager_copy_assignment = resource_manager;

  common::print(">>> Move Constructor");

  ResourceManager resource_manager_move{std::move(resource_manager)};

  common::print(">>> Move Assignment Operator");

  ResourceManager resource_manager_move_assignment{"Third Resource Manager"};
  resource_manager_move_assignment = std::move(resource_manager_copy);

  common::print(">>> Destructor");
}

void move_unique_ptr() {
  common::print_header("Move unique pointer");

  Meeting *meeting1{new Meeting{"Meeting 1"}};

  std::unique_ptr<Meeting> meeting2{std::make_unique<Meeting>("Meeting 2")};

  // Move meeting1 to meeting3

  Meeting *meeting3{std::move(meeting1)};
  meeting1 = nullptr;

  // Move meeting2 to meeting4

  std::unique_ptr<Meeting> meeting4 = std::move(meeting2);

  delete meeting1;
  delete meeting3;

  // Meeting constructor: Meeting 1 0x138605d20
  // Meeting constructor: Meeting 2 0x138605a80
  // Meeting destructor: Meeting 1 0x138605d20
  // Meeting destructor: Meeting 2 0x138605a80
}

void move_semantic::sample_move_semantic() {
  common::print_header("Move Semantic");

  common::print_separator();

  common::print("R-Value Reference");

  basic_right_value_reference();

  common::print_separator();

  basic_rule_of_five();

  common::print_separator();

  move_unique_ptr();

  common::print_separator();
}
