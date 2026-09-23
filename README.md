# cpp_module_06

# cpp_module_06

### Clarifications and general tips:

* If you find any kind of error or have suggestions to improve, please do not hesitate to point them out in the `issues` section! Obviously always respectfully, thank you :D.
* Always remember that the output examples are just examples. They can vary in your own project and still be fine.
* Remember that the project must comply with the **C++98 standard**.
* Watch out for **memory leaks**.

---

## ex00: Conversion of scalar types

### Mandatory requirements:

* Create a `ScalarConverter` class.
* The class must contain only one static method:

  * `static void convert(std::string literal);`
* The class must not be instantiable by users.
* The `convert` method receives a string representation of a C++ literal in its most common form.
* The literal must be converted and its value displayed as:

  * `char`
  * `int`
  * `float`
  * `double`
* For `char` literals, examples include:

  * `'c'`
  * `'a'`
* Non-displayable characters should not be used as inputs.
* If the conversion to `char` produces a non-displayable character, print an informative message.
* Integer literals include examples such as:

  * `0`
  * `-42`
  * `42`
* Floating-point literals include examples such as:

  * `0.0f`
  * `-4.2f`
  * `4.2f`
* The following pseudo-literals must also be handled:

  * `-inff`
  * `+inff`
  * `nanf`
* Only decimal notation is used, except for `char` parameters.
* Any function that converts a string to an `int`, `float`, or `double` is allowed.

### What can we learn about this exercise?:

The purpose of this exercise is to understand **scalar type conversion** in C++ and how a literal represented as a string can be converted into different scalar types.

### Output example:

![Example](images/ex00-output.png)

---

## ex01: Serialization

### Mandatory requirements:

* Create a `Serializer` class.
* The `Serializer` class must not be instantiable.
* Implement two static member functions:

  * `uintptr_t serialize(Data* ptr);`
  * `Data* deserialize(uintptr_t raw);`
* `serialize()` must convert a `Data` pointer into a `uintptr_t`.
* `deserialize()` must convert the `uintptr_t` value back into a `Data` pointer.
* Create a `Data` structure to use for testing the serialization and deserialization.
* Test that the pointer obtained after deserialization corresponds to the original pointer.

### What can we learn about this exercise?:

This exercise introduces **serialization and deserialization**, working with pointers and converting them to and from an unsigned integer type capable of holding a pointer.

### Output example:

![Example](images/ex01-output.png)

---

## ex02: Identify real type

### Mandatory requirements:

* Create a `Base` class with:

  * A public virtual destructor.
* Create three empty classes derived from `Base`:

  * `A`
  * `B`
  * `C`
* Implement:

  * `Base* generate(void);`

    * It must randomly instantiate `A`, `B` or `C`.
    * It must return the object as a `Base` pointer.
* Implement:

  * `void identify(Base* p);`

    * It must print the real type of the object pointed to by `p`.
* Implement:

  * `void identify(Base& p);`

    * It must print the real type of the object referenced by `p`.
    * No pointer can be used inside this function.
* The possible output types are:

  * `A`
  * `B`
  * `C`
* Do not use the `typeinfo` library.
* Do not use the `typeid` operator.

### What can we learn about this exercise?:

This exercise focuses on **identifying the real type of an object at runtime** and working with `dynamic_cast` and polymorphism through both pointers and references.

### Output example:

![Example](images/ex02-output.png)

---

#### Last but not least, check out these other repositories if you feel lost, they helped me a lot through the project:

https://github.com/Kromolux/42_cpp_06
https://github.com/tblaase/CPP-Module-06





bilioteca #include <stdint.h> necesaria para compilar
Los nombres son cosa mía, en el final no tienen por que ser así
No todos los floats son representables

https://github.com/Kromolux/42_cpp_06
https://github.com/tblaase/CPP-Module-06


ex00 mirar del 80 a 89