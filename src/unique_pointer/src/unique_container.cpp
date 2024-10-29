#include "unique_container.h"

#include <iostream>

// When call this constructor we need to move unique_ptr for test parameter
// original unique_ptr test value is moved to a temporal variable named test
// this variable needs to be moved to the member test_ptr using move again.

// We can use reference to avoid a copy of the unique_ptr, but we need to move
// the value to the member test_ptr

// Podriamos haber usado otras estrategias como mover el valor en el cuerpo
// del constructor mediante una asignacion `test_ptr = std::move(test)`

// Otra opcion es haber declarado el constructor de forma que reciba un raw
// pointer de Test y crear el unique_ptr a partir de dicho puntero
// `sample2::UniqueContainer::UniqueContainer(Test* test) : test_ptr{test}`
// y llamar al constructor con un Raw pointer
// `UniqueContainer container{new Test{"Test raw pointer"}};`

// La opcion del raw pointer podria dar problemas por no usar la funcion
// std::make_unique() para crear el unique_ptr ?????

// Tambien esta la opcion de que el constructor reciba los valores que
// necesita Test para construirse y encargarse de su construccion
// `sample2::UniqueContainer::UniqueContainer(const char* name) :
// test_ptr{std::make_unique<Test>{name}}`
// y llamar al constructor con dicho valor
// `UniqueContainer container{"Test raw pointer"};`

// Quzas la mejor opcion es usar release() que libera el raw pointer
// y deja el unique_ptr apuntando a nullptr, de esta forma podemos
// volver a utilizar el raw pointer para crear un nuevo unique_ptr
// sin necesidad de hacer un new
// `sample2::UniqueContainer::UniqueContainer(Test* test) : test_ptr{test}`
// y llamar al constructor con un Raw pointer
// `auto test{std::make_unique<Test>("Test unique pointer")}`
// `UniqueContainer container{test.release()};`

unique_pointer::UniqueContainer::UniqueContainer(unique_ptr<Test>& test)
    : test_ptr{std::move(test)} {
  std::cout << "UniqueContainer Unique Pointer ctor!!! " << std::endl;

  test_ptr->print_me();
}

unique_pointer::UniqueContainer::UniqueContainer(Test* test) : test_ptr{test} {
  std::cout << "UniqueContainer Raw Pointer ctor!!! " << std::endl;

  test_ptr->print_me();
}

unique_pointer::UniqueContainer::~UniqueContainer() {
  std::cout << "~UniqueContainer" << std::endl;

  test_ptr->print_me();
}
