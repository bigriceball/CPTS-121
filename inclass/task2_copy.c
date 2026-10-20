#include <stdio.h>

struct Student {
    char name[50];
    int id;
    float gpa;
    int age;
};

int main(void) {
    struct Student s1 = {"Alice", 1001, 3.8, 20};
    struct Student s2 = {"Bob", 1002, 3.5, 21};

    printf("Name: %s\n", s1.name);
    printf("GPA: %.2f\n", s1.gpa);

    printf("Name: %s\n", s2.name);
    printf("GPA: %.2f\n", s2.gpa);

    return 0;
}