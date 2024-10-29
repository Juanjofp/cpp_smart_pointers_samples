#pragma once

#include <string>

namespace move_semantic {

class Meeting {
 public:
  explicit Meeting(const char* name);
  Meeting(Meeting&& other) noexcept;
  ~Meeting();

 private:
  std::string name;
};

}  // namespace move_semantic