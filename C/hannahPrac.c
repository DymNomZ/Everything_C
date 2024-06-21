#include <stdio.h>
#include <math.h>

void reverseNum(int *num){
    int dig = *num;
    int reverse = 0;
    int count = 0;
    
    while (dig != 0 ) {
        dig /= 10;
        count++;
    }
    printf("%d\n", count);
    int constant = pow(10, count-1);
    dig = *num;
    do {
        int temp = dig%10;
        temp *= constant;
        reverse += temp;
        constant /= 10;
        dig /= 10;
    }while(constant != 0);
    printf("%d", reverse);
}

int main(){

    int num = 1234567;

    reverseNum(&num);

    return 0;

}