#include <stdio.h>
void inputs(int array[], int);
void display (int* array, int);
int findMin(int* array, int);
int findMax(int* array, int);
int findSum(int* array, int);
float findMean(int* array, int);
void contains(int* array, int, int);
void isThereANegative(int* array, int);
void isThereAPrimeNumber(int* array, int);
void PrimeNumber(int* array, int);
void isPrime(int);
void isSorted(int* array, int);
void reverse(int array [], int);

int main()
{
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);

    int array[size];
    inputs(array, size);
    display(array, size);

    printf("\nThe min is %d", findMin(array, size));
    printf("\nThe Max is %d", findMax(array, size));
    printf("\nThe sum of the array is %d", findSum(array, size));
    printf("\nThe mean of the array is %.2f", findMean(array, size));

    int check;
    printf("\nCheck number: ");
    scanf("%d", &check);
    printf("\nDoes it contain %d ? ", check);
    contains(array, size, check);
    printf("\nIs there a negative? ");
    isThereANegative(array, size);

    printf("\nIs there a prime number? ");
    isThereAPrimeNumber(array, size);
    PrimeNumber(array, size);

    isSorted(array, size);

    reverse(array, size);
    display(array, size);

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

int findMin(int* array, int n)
{
    int min = array[0];
    for (int i=1; i < n; i++) {
        if(array[i]<min)
        {
            min = array[i];
        }
    }
    return min;
}

int findMax(int* array, int n)
{
    int max = array[0];
    for (int i=1; i < n; i++) {
        if(array[i]>max)
        {
            max = array[i];
        }
    }
    return max;
}

int findSum(int* array, int n)
{
    int sum = 0;
    for(int i = 0; i<n; i++)
    {
        sum += array[i];
    }
    return sum;
}

float findMean(int* array, int n)
{
    float mean, sum = 0;
    for(int i = 0; i<n; i++)
    {
        sum += array[i];
    }
    mean = sum/n;
    return mean;
}

void contains(int* array, int n, int x)
{
    int j = 0;
    for(int i = 0; i<n; i++)
    {
        if(array[i]==x)
        {
            printf("Yes");
            break;
        }
        j++;
    }
    if(j==n)
    {
        printf("No");
    }
}

void isThereANegative(int* array, int n)
{
    int j = 0, zero = 0;
    for(int i = 0; i<n; i++)
    {
        if(array[i]<zero)
        {
            printf("Yes");
            break;
        }
        j++;
    }
    if(j==n)
    {
        printf("No");
    }
}

void isThereAPrimeNumber(int* array, int n)
{
    int j = 0;
    for(int i = 0; i<n; i++)
    {
        if(array[i]==2||array[i]==3)
        {
            printf("Yes");
            break;
        }
        else if(array[i]%2!=0 && array[i]%3!=0 && array[i]!=1)
        {
            printf("Yes");
            break;
        }
        j++;
    }
    if(j==n)
    {
        printf("No");
    }
}

void PrimeNumber(int* array, int n)
{
    for(int i = 0; i<n; i++)
    {
        isPrime(array[i]);
    }
}

void isPrime(int n)
{
    if(n==2||n==3)
    {
        printf("\n%d is Prime", n);
    }
    else if(n%2!=0 && n%3!=0 && n!=1)
    {
        printf("\n%d is Prime", n);
    }
    else if(n==1||n==0)
    {
        printf("\n%d is Not Prime", n);
    }
    else
    {
        printf("\n%d is Not Prime", n);
    }
}

void isSorted(int* array, int n)
{
    int counter = 1;
    for(int i = 1; i<n; i++)
    {
        if(array[i]>array[i-1])
        {
        counter++;
        }
    }
    if(counter==n)
    {
        printf("\nIt is sorted!");
    }
    else
    {
        printf("\nIt is not sorted");
    }
}

void reverse(int array[], int n)
{
    int revarray[n];
    for(int i = 0; i<n; i++)
    {
       revarray[i] = array[n-1-i];
    }
    for (int i = 0; i < n; i++) {
        array[i] = revarray[i];
    }
}