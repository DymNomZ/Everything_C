#include <stdio.h>

void rightTriangle(int size) {
    for(int row = 0; row < size; row++) {
        for(int star = 0; star <= row; star++) {
            printf("*");
        }
        printf("\n");
    }
}

void leftRightTriangle(int size) {
    for(int row = 0; row < size; row++) {
        for(int space = 0; space < size-row; space++) {
            printf(" ");
        }
        for(int k = 0; k <= row; k++){
            printf("*");
        }
        printf("\n");
    }
}

void invertedRightTriangle(int size) {
    for(int row = 0; row < size; row++){
        for(int star = 0; star < size-row; star++){
            printf("*");
        }
        printf("\n");
    }
}

void invertedLeftRightTriangle(int size){
    for(int row = 0; row < size; row++){
        for(int space = 0; space <= row; space++){
            printf(" ");
        }
        for(int star = 0; star < size-row; star++){
            printf("*");
        }
        printf("\n");
    }
}