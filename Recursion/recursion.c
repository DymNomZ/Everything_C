#include <stdio.h>

int printNatural(int number){
    if(number <= 50) {
        printf("%d ", number);
        printNatural(number+1);
    }
}

int recursionSum(int number){
    int res;
    if (number == 1) 
    {
        return (1);
    } else 
    {
        res = number + recursionSum(number - 1);
    }
    return (res);
}

int fibonacci(int previous, int current, int term){
    static int i = 1;
    int next;

    if(i == term) return 1;
    else {
        printf("%d ", current);
        next = current + previous;
        previous = current;
        ++i;
        fibonacci(previous, next, term);
    }
}

void arrayPrinter(int array[], int index, int size){
    if(index >= size) return;

    printf("%d ", array[index]);

    arrayPrinter(array, index+1, size);
}