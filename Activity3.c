#include <stdio.h>

int main()
{
    int num;

    printf("Input an integer: ");
    scanf("%d", &num);

    if(num%2==0)
    {
        printf("EVEN");
    }
    else
    {
        printf("ODD");
    }

    return 0;
}