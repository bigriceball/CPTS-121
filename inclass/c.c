
#include <stdio.h>

struct Vehicle {
    char brand[50];
    char model[50];
    int year;
    float mileage;
};

int main(void) {

    struct Vehicle v1 = {"Toyota", "Camry", 2020, 35000.5};
    struct Vehicle v2 = {"Honda", "Civic", 2022, 18000.0};

    printf("Vehicle 1:\n");
    printf("Brand: %s\n", v1.brand);
    printf("Model: %s\n", v1.model);
    printf("Year: %d\n", v1.year);
    printf("Mileage: %.1f\n\n", v1.mileage);

    printf("Vehicle 2:\n");
    printf("Brand: %s\n", v2.brand);
    printf("Model: %s\n", v2.model);
    printf("Year: %d\n", v2.year);
    printf("Mileage: %.1f\n", v2.mileage);

    return 0;
}
