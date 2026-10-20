
#include <stdio.h>

struct Product {
    char name[50];
    int id;
    float price;
    int quantity;
};

int main(void) {

    struct Product p1 = {"Laptop", 101, 899.99, 10};
    struct Product p2 = {"Mouse", 102, 25.50, 50};

    printf("Product 1:\n");
    printf("Name: %s\n", p1.name);
    printf("ID: %d\n", p1.id);
    printf("Price: $%.2f\n", p1.price);
    printf("Quantity: %d\n\n", p1.quantity);

    printf("Product 2:\n");
    printf("Name: %s\n", p2.name);
    printf("ID: %d\n", p2.id);
    printf("Price: $%.2f\n", p2.price);
    printf("Quantity: %d\n", p2.quantity);

    return 0;
}
