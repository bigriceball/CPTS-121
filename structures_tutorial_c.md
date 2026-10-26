# 08 - Structures in C

## 1. Strings in C

In C, text is commonly stored in a character array (`char` array). A C string ends with the null character `'\0'`, so the array must have enough space for all characters plus this terminator.

```c
#include <stdio.h>
#include <string.h>

char text[] = "Hello world!";
printf("%s\n", text);
```

You can read a single word with `scanf("%s", ...)`:

```c
char more_text[100];

printf("Enter one word: ");
scanf("%99s", more_text);

printf("%s\n", more_text);
```

`%99s` limits the input to 99 characters so there is room for the terminating `'\0'` in the 100-character array. `scanf("%s", ...)` stops at whitespace; to read a whole line, use `fgets()`.

Individual characters can be accessed using the `[]` operator. Use `strlen()` from `<string.h>` to get the length of a C string, not counting the terminating `'\0'`.

```c
char name[] = "Alex";
char surname[] = "Black";

printf("First letter of name %s is %c\n", name, name[0]);
printf("This name has %zu letters\n", strlen(name));
```

Output:

```text
First letter of name Alex is A
This name has 4 letters
```

Unlike C++ `std::string`, C character arrays cannot be concatenated with `+`. Use `snprintf()` to combine strings safely into a destination array:

```c
char full[100];

snprintf(full, sizeof full, "%s %s", name, surname);
printf("Full name is: %s\n", full);
```

Output:

```text
Full name is: Alex Black
```

To copy a string into another character array, use `snprintf()` or carefully use a function such as `strncpy()`. A simple and bounded example is:

```c
char copy_of_name[sizeof name];

snprintf(copy_of_name, sizeof copy_of_name, "%s", name);
```

Do not use assignment (`=`) to copy the contents of one character array into another after declaration. For example, `copy_of_name = name;` is not valid C.

---

## 2. Structure basics

A **structure** (`struct`) groups related data elements under one type name. Its members can have different data types.

```c
struct TypeName {
    int member1;
    double member2;
    char member3[20];
};
```

- `TypeName` is the structure tag.
- Each member has its own type and name.
- The semicolon after the closing brace is required.

For example:

```c
struct Pet {
    char name[20];
    int age;
    double weight;
};
```

This declares a structure type called `struct Pet` with three members: `name`, `age`, and `weight`.

### Declaring structure variables

In C, use the `struct` keyword when declaring variables unless you create a `typedef` alias:

```c
struct Pet dog;
struct Pet cat;
```

You can also declare a convenient alias with `typedef`:

```c
typedef struct {
    char name[20];
    int age;
    double weight;
} Pet;

Pet dog;
Pet cat;
```

The rest of this tutorial uses the `typedef` form for brevity.

### Accessing members

Use the dot operator (`.`) to access a member of a structure variable:

```c
dog.age = 5;
dog.weight = 3.4;
snprintf(dog.name, sizeof dog.name, "%s", "Mr. Puss");

printf("%s\n", dog.name);
printf("%d\n", dog.age);
printf("%.1f\n", dog.weight);
```

Each member has the data type declared in the structure. For example, `dog.age` is an `int`, and `dog.weight` is a `double`.

### Initializing and printing a structure

```c
#include <stdio.h>

typedef struct {
    char name[20];
    int age;
    double weight;
} Pet;

void print_pet(const Pet *pet)
{
    printf("Name: %s\n", pet->name);
    printf("Age: %d\n", pet->age);
    printf("Weight: %.1f\n", pet->weight);
}

int main(void)
{
    Pet dog = {"Henry", 2, 0.5};
    Pet cat = {"Meow", 2, 1.5};

    printf("Details about my dog:\n");
    print_pet(&dog);

    printf("Details about my cat:\n");
    print_pet(&cat);

    Pet copycat = cat;

    printf("Details about my cat's copy:\n");
    print_pet(&copycat);

    return 0;
}
```

Example output:

```text
Details about my dog:
Name: Henry
Age: 2
Weight: 0.5
Details about my cat:
Name: Meow
Age: 2
Weight: 1.5
Details about my cat's copy:
Name: Meow
Age: 2
Weight: 1.5
```

A structure can be copied using `=`. This copies each member; character-array members are copied as part of the structure assignment. However, assigning one character array to another directly is not allowed.

---

## 3. Pointers to structures

C does not have C++ references. Instead, a function can receive a pointer to a structure.

```c
typedef struct {
    char name[20];
    int age;
    double weight;
} Pet;

Pet dog = {"Henry", 2, 0.5};
Pet *dog_pointer = &dog;
```

- `&dog` means “the address of `dog`”.
- `Pet *dog_pointer` declares a pointer to a `Pet`.
- `dog_pointer->age` accesses the `age` member through the pointer.

The arrow operator (`->`) is shorthand for dereferencing a pointer and then using the dot operator:

```c
dog_pointer->age
(*dog_pointer).age
```

These two expressions refer to the same member.

A pointer is useful when a function needs to access a structure without making a copy. Use `const Pet *` if the function should not modify the structure through that pointer.

```c
void print_pet(const Pet *pet)
{
    printf("Name: %s\n", pet->name);
    printf("Age: %d\n", pet->age);
    printf("Weight: %.1f\n", pet->weight);
}
```

Call the function by passing the address:

```c
print_pet(&dog);
```

---

## 4. Returning structures and storing multiple structures

A C function can return a structure by value:

```c
#include <stdio.h>

typedef struct {
    char name[50];
    int age;
    double weight;
} Person;

Person read_person(void)
{
    Person person;

    printf("Enter one-word name: ");
    if (scanf("%49s", person.name) != 1) {
        person.name[0] = '\0';
        person.age = 0;
        person.weight = 0.0;
        return person;
    }

    printf("Enter age: ");
    if (scanf("%d", &person.age) != 1) {
        person.name[0] = '\0';
        person.age = 0;
        person.weight = 0.0;
        return person;
    }

    printf("Enter weight: ");
    if (scanf("%lf", &person.weight) != 1) {
        person.name[0] = '\0';
        person.age = 0;
        person.weight = 0.0;
    }

    return person;
}
```

The `&` is required for `scanf()` when reading an `int` or `double`, because `scanf()` needs the address where it should store the value. For a character array such as `person.name`, the array name already converts to a pointer to its first element.

Unlike C++ `std::vector`, C has no built-in growable array. If the number of records is known in advance, use an ordinary array:

```c
Person people[3];

for (int i = 0; i < 3; i++) {
    people[i] = read_person();
}
```

Print the records by passing each element's address:

```c
void print_person(const Person *person)
{
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Weight: %.1f\n", person->weight);
}

/* Example use, after people has been filled in: */
for (int i = 0; i < 3; i++) {
    print_person(&people[i]);
}
```

For a variable-sized collection, C programs can allocate memory dynamically using `malloc()` or `realloc()` and release it using `free()`. Dynamic memory requires careful size checking and memory management.

---

## 5. Nested structures

A structure can contain another structure as one of its members.

```c
typedef struct {
    char name[20];
    int age;
    double weight;
} Pet;

typedef struct {
    char name[50];
    char email[100];
    Pet favourite_pet;
} Friend;
```

You can access members of the nested structure by chaining the dot operator:

```c
Friend friend1 = {
    "Gordon",
    "gordon@example.com",
    {"Mittens", 4, 3.2}
};

printf("%s\n", friend1.name);
printf("%s\n", friend1.email);
printf("%s\n", friend1.favourite_pet.name);
printf("%d\n", friend1.favourite_pet.age);
printf("%.1f\n", friend1.favourite_pet.weight);
```

Here, `friend1.favourite_pet` is a `Pet` structure, so its members can be accessed with another `.`.

---

## 6. Splitting C code into header and source files

A larger C program can be split into:

- **Header file (`.h`)**: structure declarations and function prototypes.
- **Source file (`.c`)**: function definitions.
- **Main source file (`main.c`)**: program entry point and the code that uses those functions.

In C, a common header guard uses `#ifndef`, `#define`, and `#endif`. This prevents the header's declarations from being processed multiple times in one translation unit.

### `Pet.h`

```c
#ifndef PET_H
#define PET_H

typedef struct {
    char name[20];
    int age;
    double weight;
} Pet;

void print_pet(const Pet *pet);

#endif
```

### `Pet.c`

```c
#include "Pet.h"
#include <stdio.h>

void print_pet(const Pet *pet)
{
    printf("Name: %s\n", pet->name);
    printf("Age: %d\n", pet->age);
    printf("Weight: %.1f\n", pet->weight);
}
```

### `main.c`

```c
#include "Pet.h"

int main(void)
{
    Pet my_pet = {"Mr. Puss", 5, 3.4};

    print_pet(&my_pet);

    return 0;
}
```

Compile the files together from the same directory:

```bash
cc -Wall -Wextra main.c Pet.c -o pet
./pet
```

Do not include a `.c` file with `#include`. Include the header (`.h`) and compile the source files together.

### Functions that process arrays of structures

In C, an array is commonly passed to a function together with its element count, because the function parameter does not retain the full array length.

For example, calculate the average weight:

```c
double average_weight(const Person people[], size_t count)
{
    double total = 0.0;

    if (count == 0) {
        return 0.0;
    }

    for (size_t i = 0; i < count; i++) {
        total += people[i].weight;
    }

    return total / count;
}
```

Include `<stddef.h>` if you use `size_t` in a source file that does not already define it through another included header.

The `const` means this function promises not to modify the elements through `people`. The `count` argument tells it how many elements are available.

A function can also return a structure, or return a pointer to an element. If returning a pointer, ensure that the pointed-to object remains valid after the function returns.

---

## 7. Sorting arrays of structures

C does not have C++'s `std::sort`. One standard C option is `qsort()` from `<stdlib.h>`. You provide a comparison function that tells `qsort()` how two elements should be ordered.

For example, sort people by age in ascending order:

```c
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
    double weight;
} Person;

int compare_people_by_age(const void *a, const void *b)
{
    const Person *person_a = a;
    const Person *person_b = b;

    if (person_a->age < person_b->age) {
        return -1;
    }
    if (person_a->age > person_b->age) {
        return 1;
    }
    return 0;
}

/* Example use:
   Person people[3] = { ... };
   qsort(people, 3, sizeof people[0], compare_people_by_age);
*/
```

`qsort()` receives:

1. The array to sort.
2. The number of elements.
3. The size of each element.
4. A comparison function.

The comparison function returns a negative value when the first element should come before the second, zero when they compare equal, and a positive value when the first should come after the second.

Avoid implementing comparisons by subtracting arbitrary integer fields, such as `return person_a->age - person_b->age;`, because integer subtraction can overflow for sufficiently large values.

---

## Summary

- A `struct` groups related values, potentially of different types, into one record.
- Use `.` to access a member of a structure variable.
- Use `->` to access a member through a pointer to a structure.
- C strings are character arrays ending in `'\0'`; use functions such as `strlen()` and `snprintf()` to work with them.
- C functions can accept pointers to structures and return structures by value.
- C arrays have a fixed size. Pass the element count when a function processes an array.
- Use header files (`.h`) for declarations and source files (`.c`) for definitions.
- Use `qsort()` with a comparison function to sort an array of structures.
