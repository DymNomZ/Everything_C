#include <stdio.h>

int main()
{
    int num1, num2;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    if(num1 == num2)
    {
        printf("EQUIVALENT");
    }
    else
    {
        printf("NOT EQUIVALENT");
    }

    return 0;
}