
#include <stdio.h>

struct Student {
    char name[50];
    int id;
    float gpa;
    int age;
};

int main(void) {

    struct Student students[5];
    int i;
    int maxIndex = 0;

    // TODO 1: Read information for five students
    for (i = 0; i < 5; i++) {

        printf("Enter information for student %d:\n", i + 1);

        printf("Name: ");
        scanf("%49s", students[i].name);//see explanation.md or simply use %s for this moment

        printf("ID: ");
        scanf("%d", &students[i].id);

        printf("GPA: ");
        scanf("%f", &students[i].gpa);

        printf("Age: ");
        scanf("%d", &students[i].age);

        printf("\n");
    }

    // TODO 2: Display all student records
    printf("Student Records:\n");

    for (i = 0; i < 5; i++) {
        printf("%s - %d - %.2f - %d\n",
               students[i].name,
               students[i].id,
               students[i].gpa,
               students[i].age);
    }

    // TODO 3: Find the student with the highest GPA
    for (i = 1; i < 5; i++) {

        if (students[i].gpa > students[maxIndex].gpa) {
            maxIndex = i;
        }
    }

    // Display the student with highest GPA
    printf("\nStudent with Highest GPA:\n");
    printf("%s - %.2f\n",
           students[maxIndex].name,
           students[maxIndex].gpa);

    return 0;
}
