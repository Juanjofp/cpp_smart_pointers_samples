#include <iostream>
#include <string>
#include <vector>

#include "basic_concepts.h"
#include "move_semantic.h"
#include "raw_pointers.h"
#include "references.h"
#include "shared_pointer.h"
#include "unique_pointer.h"

int main() {
  // basic_concepts::run_examples();

  raw_pointers::raw_pointers();

  references_sample::sample_references();

  unique_pointer::unique_pointer_main();

  shared_ptr_sample::sample_shared_ptr();

  move_semantic::sample_move_semantic();

  return 0;
}