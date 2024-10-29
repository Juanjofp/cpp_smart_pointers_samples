#include "basic_concepts.h"

#include "common.h"
#include "enum.h"
#include "input_sample.h"

using namespace basic_concepts;

void basic_concepts::run_examples() {
  common::print_header("Basics Concepts");

  choose_color(FillColor::RED, StrokeColor::GREEN);

  basic_input();
}
