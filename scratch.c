#include <stdio.h>
void look(int array[], int size, int target);

int main()
{
    int size, target;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size];
    printf("Enter the array elements: ");
    for(int i = 0; i<size; i++)
    {
        scanf("%d", array[i]);
    }

    printf("\nEnter the target value: ");
    scanf("%d", &target);

    look(array, size, target);
    
    return 0;
}

void look(int array[], int size, int target)
{
    for(int i = 0; i<size; i++)
    {
        if(array[i]==target)
        {
            printf("Target value found at index %d.", i);
            break;
        }
    }
    printf("Target value not found in the array.");
}
/*
#include <stdio.h>


int fun1(int s){
    if(s%2==0){
        s -=1;
        return s;
    }else{
        s = fun2(s);
        return s;
    }
}

int fun2(int y){
    if(y%2!=0){
        y +=1;
        return y;
    }else{
        fun1(y);
        return y;
    }
}

int main()
{
    int num[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int select, result;

    for(int z = 0; z<10; z++){
        select = num[z];
        result = fun1(select);
        printf("%d ", result);
    }
}*/