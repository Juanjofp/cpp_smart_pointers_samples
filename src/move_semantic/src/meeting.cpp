#include "meeting.h"

#include <format>

#include "common.h"

using namespace move_semantic;

Meeting::Meeting(const char* name) : name{name} {
  const std::string message = std::format("Meeting constructor: {} {}", name,
                                          static_cast<const void*>(this));

  common::print(message);
}

move_semantic::Meeting::Meeting(Meeting&& other) noexcept {
  name = std::move(other.name);

  const std::string message = std::format("Meeting move constructor: {} {}",
                                          name, static_cast<const void*>(this));

  common::print(message);
}

Meeting::~Meeting() {
  const std::string message = std::format("Meeting destructor: {} {}", name,
                                          static_cast<const void*>(this));

  common::print(message);
}