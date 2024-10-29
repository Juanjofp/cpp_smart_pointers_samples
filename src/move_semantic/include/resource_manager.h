#pragma once

#include <string>

#include "heavy_resource.h"

namespace move_semantic {
class ResourceManager {
 public:
  // Rule of Five

  explicit ResourceManager(const char* name);
  ~ResourceManager();

  ResourceManager(const ResourceManager& other);
  ResourceManager& operator=(const ResourceManager& other);

  ResourceManager(ResourceManager&& other) noexcept;
  ResourceManager& operator=(ResourceManager&& other) noexcept;

  std::string get_name() const;

 private:
  std::string name;
  HeavyResource* resource;
};
}  // namespace move_semantic
