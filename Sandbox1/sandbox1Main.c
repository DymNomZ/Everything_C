#include <stdio.h>
#include "sandbox1.h"

int main(){
    int size;

    printf("Enter number of rows: ");
    scanf("%d", &size);

    /*rightTriangle(size);
    printf("\n");
    leftRightTriangle(size);
    printf("\n");
    invertedRightTriangle(size);
    printf("\n");
    invertedLeftRightTriangle(size);
    printf("\n");
    pyramid(size);
    printf("\n");
    invertedPyramid(size);
    printf("\n");
    rhombus(size);*/
    diamond(size);

    return 0;
}