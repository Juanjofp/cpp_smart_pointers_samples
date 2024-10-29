#pragma once

namespace move_semantic {
class HeavyResource {
 public:
  // Rule of Three

  explicit HeavyResource(const char* name);
  ~HeavyResource();
  HeavyResource(const HeavyResource& other);
  HeavyResource& operator=(const HeavyResource& other);

 private:
  char* data;
};
}  // namespace move_semantic