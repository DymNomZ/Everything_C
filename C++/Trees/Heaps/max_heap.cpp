#include <iostream>
#include "max_heap.h"

using namespace std;

Max_Heap::Max_Heap(){
    size = 0;
    cap = 5;
    heap_e = (int*)calloc(cap, 4);
}

void Max_Heap::swap(int i, int j){
    *(heap_e + i) = *(heap_e + i) ^ *(heap_e + j);
    *(heap_e + j) = *(heap_e + i) ^ *(heap_e + j);
    *(heap_e + i) = *(heap_e + i) ^ *(heap_e + j);
}

int Max_Heap::get_cap(){
    return cap;
}

int Max_Heap::get_size(){
    return size;
}

int Max_Heap::peek(){
    cout << "Peeking..." << endl;
    return *(heap_e);
}

void Max_Heap::grow(){
    cout << "Growing..." << endl;
    cap *= 1.5;
    heap_e = (int*)realloc(heap_e, cap*4);
}

void Max_Heap::shrink(){
    cout << "Shrinking..." << endl;
    cap *= 0.5;
    heap_e = (int*)realloc(heap_e, cap*4);
}

void Max_Heap::print(){
    if(size == 0) cout << "Nothing to print..." << endl;
    else{
        cout << "Printing..." << endl;
        for(int i = 0; i < size; i++){
            cout << *(heap_e + i) << " ";
        }
        cout << endl;
    }
}

void Max_Heap::heapify(int i){
    int x = i;
    int left_idx = 2*i+1;
    int right_idx = 2*i+2;
    
    if(left_idx < size && *(heap_e + left_idx) > *(heap_e + x)) x = left_idx;
    if(right_idx < size && *(heap_e + right_idx) > *(heap_e + x)) x = right_idx;
    if(x != i){
        swap(x, i);
        heapify(x);
    }
}

void Max_Heap::insert(int n){
    int old_size = size;
    if(size == 0){
        *(heap_e) = n;
        size++;
    }
    else{
        if(size >= cap) grow();
        *(heap_e + size) = n;
        //haven't understood this algorithm yet
        size++;
        for(int i = size / 2 - 1; i >= 0; i--) heapify(i);
    }
}

int Max_Heap::remove_x(int x){
    int ans = -1;
    if(size == 0) cout << "Heap is empty!" << endl;
    for(int i = 0; i < size; i++){
        if(*(heap_e + i) == x){
            ans = *(heap_e + i);
            swap(i, size-1);
            size--;
            break;
        }
    }
    if(size <= cap * 0.5) shrink();
    heapify(0);
    return ans;
}

int Max_Heap::remove(){
    int ans = -1;
    if(size == 0) cout << "heap is empty!" << endl;
    else{
        ans = *(heap_e);
        remove_x(*(heap_e));
    }
    return ans;
}