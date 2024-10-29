#pragma once

#include <string>

using namespace std;

namespace basic_concepts {

// enum FillColor { RED, GREEN, BLUE };

// enum StrokeColor {
//   RED,  // Error: redefinition of enumerator 'RED'
//   GREEN,
//   BLUE
// };

// Use enum class to avoid redefinition of enumerator
// If you want to use the same enumerator in different enums, use enum class
// to avoid redefinition of enumerator

enum class FillColor { RED, GREEN, BLUE };

enum class StrokeColor { RED, GREEN, BLUE };

void choose_color(FillColor fill_color, StrokeColor stroke_color);

class ColorUtils {
 public:
  static string fill_color_name(FillColor fill_color);

  static string stroke_color_name(StrokeColor stroke_color);
};

}  // namespace basic_concepts