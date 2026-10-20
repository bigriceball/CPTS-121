# Introduction to Structures in C

## 1. Structure Definition

Let's start by looking at the following code:

```c
struct Student {
    char name[50];
    int id;
    float gpa;
    int age;
};
```

This is called a **Structure Definition**.

A structure is a user-defined data type in C that allows us to group related information together, even when the information has different data types.

In this example, we define a structure called `Student`.

Each student has four members:

- `name`: A character array that stores the student's name.
- `id`: An integer that stores the student ID.
- `gpa`: A floating-point number that stores the student's GPA.
- `age`: An integer that stores the student's age.

**Key Point:** The structure definition describes what information a student record contains. It does not create an actual student variable.

## 2. Structure Variable Declaration and Initialization

Now let's create a student using our structure.

```c
struct Student s1 = {"Alice", 1001, 3.8, 20};
```

This is called **Structure Variable Declaration and Initialization**.

Here:

- `struct Student` is the structure type.
- `s1` is the name of our structure variable.
- `"Alice"` is the student's name.
- `1001` is the student ID.
- `3.8` is the GPA.
- `20` is the age.

We have now created a student record containing all four pieces of information.

**Key Point:** A structure definition describes a type, while a structure variable represents an actual record.

## 3. Accessing Structure Members — Dot Operator

How can we access a specific piece of information from a student?

For example:

```c
s1.gpa
```

The `.` symbol is called the **Dot Operator**, also known as the member access operator.

It allows us to access an individual member of a structure variable.

For example:

```c
printf("Name: %s\n", s1.name);
printf("ID: %d\n", s1.id);
printf("GPA: %.2f\n", s1.gpa);
printf("Age: %d\n", s1.age);
```

Expected output:

```text
Name: Alice
ID: 1001
GPA: 3.80
Age: 20
```

**Key Point:** We use the dot operator to access members of a structure.

## 4. Modifying Structure Members

We can also change the value of a structure member after initialization.

For example, suppose we have a third student:

```c
struct Student s3 = {"David", 1004, 3.7, 22};
```

Now, let's update David's GPA:

```c
s3.gpa = 3.95;
```

This statement changes the GPA of `s3` from `3.7` to `3.95`.

We can display the updated GPA:

```c
printf("Updated GPA: %.2f\n", s3.gpa);
```

Expected output:

```text
Updated GPA: 3.95
```

**Key Point:** Structure members can be accessed and modified independently using the dot operator.

## 5. Class Discussion

**Question:**

"If we want to add a fourth student, do we need to redefine the Student structure?"

**Answer: No.**

We only need to declare another variable using the existing structure type.

For example:

```c
struct Student s4 = {"Emma", 1005, 3.9, 21};
```

We can create as many student variables as needed using the same structure definition.

Each variable has its own independent set of members.

For example:

```c
s1.gpa = 3.8;
s3.gpa = 3.95;
s4.gpa = 3.9;
```

Changing one student's GPA does not affect the other students.
