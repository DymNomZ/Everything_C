#include <stdio.h>
#include "recursion.h"

int main(){
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    int array[] = {1, 2, 3, 4, 5};

    //printNatural(number);

    /*int sum;
    sum = recursionSum(number);
    printf("%d", sum);

    int previous = 0, current = 1;
    fibonacci(previous, current, number);*/

    arrayPrinter(array, 0, number);

    return 0;
}