#include <stdio.h>
#include <math.h>

int main(){

    float r, h;
    printf("Please enter radius:");
    scanf("%f", &r);
    printf("Please enter height:");
    scanf("%f", &h);
    printf("\n");

    printf("The perimeter of the circle is:%.2f\n", 2 * 3.14 * r);
    printf("The area of the circle is:%.2f\n", 3.14 * pow(r, 2));
    printf("The surface area of sphere is:%.2f\n", 4 * 3.14 * pow(r, 2));
    printf("The volume of sphere is:%.2f\n", (4 / 3) * 3.14 * pow(r, 3));
    printf("The volume of the cylinder is:%.2f\n", 3.14 * pow(r, 2) * h);
    
    return 0;
}