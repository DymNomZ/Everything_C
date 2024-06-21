/*
Author: RAMOS, Jeremiah T.
Description: Problem 53
Date: October 4, 2023
Version: 1.0a
*/

#include <stdio.h>

void readScore();
char grade(int a, int b, int c);
void results(char grade);

int a, b, c; // Global variables

int main() {
    readScore();
    results(grade(a, b, c));
    return 0;
}

void readScore() {
    printf("Enter test scores: ");
    scanf(" %d%d%d", &a, &b, &c);
}

char grade(int a, int b, int c) {
    int avg = (a + b + c) / 3;
    char grade;
    if (avg >= 90) grade = 'A';
    else if (avg < 90 && avg >= 70)
        if (c > 90) grade = 'A'; else grade = 'B';
    else if (avg < 70 && avg >= 50)
        if ((b + c) / 2 > 70) grade = 'C'; else grade = 'D';
    else grade = 'F';
    return grade;
}

void results(char grade) {
    printf("Final Grade: %c", grade);
}
