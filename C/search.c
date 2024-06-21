#include <stdio.h>

//LINEAR SEARCH
int look(int array[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int size, target;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size];
    printf("Enter the array elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter the target value: ");
    scanf("%d", &target);

    int result = look(array, size, target);

    if (result == -1) {
        printf("Target value not found in the array.\n");
    } else {
        printf("Target value found at index %d.\n", result);
    }

    return 0;
}

// BINARY SEARCH
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n, target;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target value: ");
    scanf("%d", &target);

    int result = binarySearch(arr, 0, n - 1, target);

    if (result == -1) {
        printf("Target value not found in the array.");
    } else {
        printf("Target value found at index %d.", result);
    }
    return 0;
}

// "BINARY SEARCH" (MINE, BUT WRONG)
#include <stdio.h>
int result(int array[], int, int);

int main()
{
    int size, target;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size];
    printf("Enter the array elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter the target value: ");
    scanf("%d", &target);

    int ans = result(array, size, target);

    if (ans == -1) {
        printf("Target value not found in the array.\n");
    } else {
        printf("Target value found at index %d.\n", ans);
    }
    
    return 0;
}

int result(int array[], int size, int target)
{
    int mid = size/2, min = 0;
    if(target==array[mid])
    {
        return mid;
    }
    else if(target>array[mid])
    {
        min = mid+1;
        for (int i = min; i < size; i++)
        {
            if (array[i] == target)
            {
                return i;
            }
        }
    }
    else if(target<array[mid])
    {
        for (int i = 0; i < mid; i++)
        {
            if (array[i] == target)
            {
                return i;
            }
        }
    }
        return -1;
}