#include "enum.h"

#include <iostream>

#include "common.h"

using namespace std;

void basic_concepts::choose_color(FillColor fill_color,
                                  StrokeColor stroke_color) {
  common::print_header("Enum Scoped");

  cout << "Fill color: " << ColorUtils::fill_color_name(fill_color) << endl;

  cout << "Stroke color: " << ColorUtils::stroke_color_name(stroke_color)
       << endl;
}

string basic_concepts::ColorUtils::fill_color_name(FillColor fill_color) {
  switch (fill_color) {
    case FillColor::RED:
      return "Red";
    case FillColor::GREEN:
      return "Green";
    case FillColor::BLUE:
      return "Blue";
  }

  return "";
}

string basic_concepts::ColorUtils::stroke_color_name(StrokeColor stroke_color) {
  switch (stroke_color) {
    case StrokeColor::RED:
      return "Red";
      break;
    case StrokeColor::GREEN:
      return "Green";
      break;
    case StrokeColor::BLUE:
      return "Blue";
      break;
  }

  return "";
}
