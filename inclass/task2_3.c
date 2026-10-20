
#include <stdio.h>

// Define the Student structure
struct Student {
    char name[50];
    int id;
    float gpa;
    int age;
};

int main(void) {

    // Initialize three students
    struct Student s1 = {"Alice", 1001, 3.8, 20};
    struct Student s2 = {"Bob", 1002, 3.5, 21};
    struct Student s3 = {"David", 1004, 3.7, 22};

    // Display all students
    printf("Student 1:\n");
    printf("Name: %s\n", s1.name);
    printf("ID: %d\n", s1.id);
    printf("GPA: %.2f\n", s1.gpa);
    printf("Age: %d\n\n", s1.age);

    printf("Student 2:\n");
    printf("Name: %s\n", s2.name);
    printf("ID: %d\n", s2.id);
    printf("GPA: %.2f\n", s2.gpa);
    printf("Age: %d\n\n", s2.age);

    printf("Student 3:\n");
    printf("Name: %s\n", s3.name);
    printf("ID: %d\n", s3.id);
    printf("GPA: %.2f\n", s3.gpa);
    printf("Age: %d\n\n", s3.age);

    // Modify David's GPA
    s3.gpa = 3.95;

    // Display updated GPA
    printf("David's updated GPA: %.2f\n", s3.gpa);

    return 0;
}
