
#include <stdio.h>

int main(void) {
    char name1[] = "Alice";
    int id1 = 1001;
    float gpa1 = 3.8;
    int age1 = 20;

    char name2[] = "Bob";
    int id2 = 1002;
    float gpa2 = 3.5;
    int age2 = 21;

    char name3[] = "Carol";
    int id3 = 1003;
    float gpa3 = 3.9;
    int age3 = 19;
    //task 1: Display the information of each student using printf statements
    // Display student 1
    printf("Name: %s\n", name1);
    printf("ID: %d\n", id1);
    printf("GPA: %.2f\n", gpa1);
    printf("Age: %d\n\n", age1);

    // Display student 2
    printf("Name: %s\n", name2);
    printf("ID: %d\n", id2);
    printf("GPA: %.2f\n", gpa2);
    printf("Age: %d\n\n", age2);

    // Display student 3
    printf("Name: %s\n", name3);
    printf("ID: %d\n", id3);
    printf("GPA: %.2f\n", gpa3);
    printf("Age: %d\n", age3);

    return 0;
}
