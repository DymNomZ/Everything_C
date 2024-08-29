#include <iostream>
#include "min_heap.h"

using namespace std;

int main(){
    int size;
    cout << "Size: ";
    cin >> size;
    int* arr = (int*)calloc(size, 4);
    cout << "Array Elements: ";
    for(int i = 0; i < size; i++) cin >> *(arr + i);

    MinHeap* minH = new MinHeap(arr, size);
    minH->print_heap();

}