#include <stdio.h>
void inputs(int array[], int);
void display (int* array, int);
void isThereAPrimeNumber(int array[], int);
int isPrime(int* array, int);

int main()
{
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);

    int array[size];
    inputs(array, size);
    display(array, size);

    isThereAPrimeNumber(array, size);
    isPrime(array, size);

    return 0;
}

void inputs(int array[], int n)
{
    for (int i=0; i < n; i++) {
        printf("Enter value for index %d: ",i);
        scanf("%d", &array[i]);
    }
}

void display(int *array, int n)
{
    for (int i=0; i < n; i++) {
        printf("\nValue for array[%d] : %d",i, array[i]);
    }
}

void isThereAPrimeNumber(int array[], int n)
{
    int j = 0;
    for(int i = 0; i<n; i++)
    {
        if(array[i]==2||array[i]==3)
        {
            printf("\nyes");
            break;
        }
        else if(array[i]%2!=0 && array[i]%3!=0 && array[i]!=1)
        {
            printf("\nyes");
            break;
        }
        j++;
    }
    if(j==n)
    {
        printf("\nno");
    }
}

int isPrime(int* array, int n)
{
    for(int i = 0; i<n; i++)
    {
    if(array[i]==2||array[i]==3)
    {
        printf("\nPrime");
    }
    else if(array[i]%2!=0 && array[i]%3!=0 && array[i]!=1)
    {
        printf("\nPrime");
    }
    else if(array[i]==1||array[i]==0)
    {
        printf("\nNot Prime");
    }
    else
    {
        printf("\nNot Prime");
    }
    }
}