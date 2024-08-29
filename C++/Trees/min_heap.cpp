#include <iostream>
#include "min_heap.h"

using namespace std;

MinHeap::MinHeap(int* arr, int size){
    heap_size = size;
    heap_cap = size;
    heap_e = arr;
}

int MinHeap::get_cap(){
    return heap_cap;
}

int MinHeap::get_size(){
    return heap_size;
}

void MinHeap::print_heap(){
    cout << "Printing..." << endl;
    for(int i = 0; i < heap_size; i++) cout << *(heap_e + i) << " ";
    cout << endl;
}

void MinHeap::check_cap(){
    if(heap_cap != heap_size) cout << "Capacity is good!" << endl;
    else{
        int* temp = (int*)calloc(heap_cap*2, 4);
        for(int i = 0; i < heap_size; i++) *(temp + i) = *(heap_e + i);
        heap_cap *= 2;
        *heap_e = *temp;
        cout << "New heap elements: " << endl;
        print_heap();
    }
}

void MinHeap::swap(int a, int b){
    *(heap_e + a) = *(heap_e + a) ^ *(heap_e + b);
    *(heap_e + b) = *(heap_e + a) ^ *(heap_e + b);
    *(heap_e + a) = *(heap_e + a) ^ *(heap_e + b);
}

int MinHeap::get_parentIdx(int i){
    return (i - 1) / 2;
}

int MinHeap::get_leftChildIdx(int i){
    return 2*i + 1;
}

int MinHeap::get_rightChildIdx(int i){
    return 2*i + 2;
}

bool MinHeap::has_parent(int i){
    if(*(heap_e + get_parentIdx(i)) >= 0) return true;
    else return false;
}

bool MinHeap::has_left_child(int i){
    if(*(heap_e + get_leftChildIdx(i)) < heap_size) return true;
    else return false;
}

bool MinHeap::has_right_child(int i){
    if(*(heap_e + get_rightChildIdx(i)) < heap_size) return true;
    else return false;
}

int MinHeap::get_parent(int i){
    return *(heap_e + get_parentIdx(i));
}

int MinHeap::get_left_child(int i){
    return *(heap_e + get_leftChildIdx(i));
}

int MinHeap::get_right_child(int i){
    return *(heap_e + get_rightChildIdx(i));
}

int MinHeap::get_element(int i){
    return *(heap_e + i);
}

void MinHeap::heapify_up(int i){
    if(has_parent(i) && get_parent(i) > get_element(i)){
        swap(get_parentIdx(i), i);
        heapify_up(get_parentIdx(i));
    }
}

void MinHeap::heapify_down(int i){
    if(has_left_child(i) && get_left_child(i) < get_element(i)){
        swap(get_leftChildIdx(i), i);
        heapify_down(get_leftChildIdx(i));
    }
    if(has_right_child(i) && get_right_child(i) < get_element(i)){
        swap(get_rightChildIdx(i), i);
        heapify_down(get_rightChildIdx(i));
    }
}

void MinHeap::insert(int e){
    check_cap();
    *(heap_e + heap_size) = e;
    heap_size++;
    heapify_up(heap_size);
}

int MinHeap::remove(){
    if(heap_size == 0) cout << "Heap is empty" << endl;
    else{
        *(heap_e) = *(heap_e + heap_size);
        heap_size--;
        heapify_down(0);
    }
}