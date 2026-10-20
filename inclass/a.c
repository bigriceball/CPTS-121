
#include <stdio.h>

struct Book {
    char title[100];
    char author[50];
    int year;
    float price;
};

int main(void) {

    struct Book book1 = {
        "The C Programming Language",
        "Kernighan and Ritchie",
        1988,
        49.99
    };

    struct Book book2 = {
        "C Programming Absolute Beginner's Guide",
        "Greg Perry",
        2013,
        29.99
    };

    printf("Book 1:\n");
    printf("Title: %s\n", book1.title);
    printf("Author: %s\n", book1.author);
    printf("Year: %d\n", book1.year);
    printf("Price: $%.2f\n\n", book1.price);

    printf("Book 2:\n");
    printf("Title: %s\n", book2.title);
    printf("Author: %s\n", book2.author);
    printf("Year: %d\n", book2.year);
    printf("Price: $%.2f\n", book2.price);

    return 0;
}
