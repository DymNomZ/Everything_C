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

void pyramid(int size){
    int star;
    for(int row = 0; row < size; row++){
        for(int space = 0; space < size-row; space++){
            printf(" ");
        }
        for(int star = 1; star <= (row+1)*2-1; star++){
            printf("*");
        }
        printf("\n");
    }
}

void invertedPyramid(int size){
    for(int row = 0; row < size; row++){
        for(int space = 0; space < row; space++){
            printf(" ");
        }
        for(int star = 1; star < size*2 - row*2; star++){
            printf("*");
        }
        printf("\n");
    }
}

void rhombus(int size){
    for(int rows = 0; rows < size; rows++){
        for(int space = 0; space <= rows; space++){
            printf(" ");
        }
        for(int star = 0; star < size*2; star++){
            printf("*");
        }
        printf("\n");
    }
}

void diamond(int size){
    if(size%2==0) size-1;
    for(int rows = 0; rows < (size/2)+1; rows++){
        for(int space = 0; space < size/2 - rows; space++){
            printf(" ");
        }
        for(int star = 1; star <= (rows+1)*2-1; star++){
            printf("*");
        }
        printf("\n");
    }
    for(int rows = 0; rows < (size/2); rows++){
        for(int space = 0; space <= rows; space++){
            printf(" ");
        }
        for(int star = 1; star < (size/2)*2 - rows*2; star++){
            printf("*");
        }
        printf("\n");
    }
}