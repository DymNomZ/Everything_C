#include <iostream>
#include "min_heap.h"

using namespace std;

Min_Heap::Min_Heap(int* arr, int size){
    heap_size = size;
    heap_cap = size;
    heap_e = arr;
    sort();
}

int Min_Heap::peek(){
    return *(heap_e);
}

int Min_Heap::get_cap(){
    return heap_cap;
}

int Min_Heap::get_size(){
    return heap_size;
}

//tried to integrate sir's tree print code
void Min_Heap::print_tree(string prefix, int n, bool isLeft) {
    cout << prefix;
    cout << (isLeft ? "+--L: " : "+--R: " );
    cout << heap_e[n] << endl;
    if (get_leftChildIdx(n) < heap_size) {
        print_tree(prefix + "|   ", get_leftChildIdx(n), true);
    }
    if (get_rightChildIdx(n) < heap_size) {
        print_tree(prefix + "|   ", get_rightChildIdx(n), false);
    }
}

void Min_Heap::print_heap(){
    cout << "Printing..." << endl;
    for(int i = 0; i < heap_size; i++) cout << *(heap_e + i) << " ";
    cout << "Tree Visual: " << endl;
    print_tree(" ", 0, false);
}

void Min_Heap::sort(){
    for(int i = 0; i < heap_size-1; i++){
        for(int j = 0; j < heap_size-1-i; j++){
            if(get_element(j) > get_element(j+1)){
                swap(j, j+1);
            }
        }
    }
}

void Min_Heap::grow(){
    cout << "Growing..." << endl;
    heap_cap *= 1.5;
    heap_e = (int*)realloc(heap_e, heap_cap*4);
}

void Min_Heap::shrink(){
    cout << endl << "Shrinking..." << endl;
    heap_cap *= 0.5;
    heap_e = (int*)realloc(heap_e, heap_cap*4);
}

void Min_Heap::swap(int a, int b){
    *(heap_e + a) = *(heap_e + a) ^ *(heap_e + b);
    *(heap_e + b) = *(heap_e + a) ^ *(heap_e + b);
    *(heap_e + a) = *(heap_e + a) ^ *(heap_e + b);
}

int Min_Heap::get_parentIdx(int i){
    return (i - 1) / 2;
}

int Min_Heap::get_leftChildIdx(int i){
    return 2*i + 1;
}

int Min_Heap::get_rightChildIdx(int i){
    return 2*i + 2;
}

bool Min_Heap::has_parent(int i){
    if(*(heap_e + get_parentIdx(i)) >= 0) return true;
    else return false;
}

bool Min_Heap::has_left_child(int i){
    if(*(heap_e + get_leftChildIdx(i)) < heap_size) return true;
    else return false;
}

bool Min_Heap::has_right_child(int i){
    if(*(heap_e + get_rightChildIdx(i)) < heap_size) return true;
    else return false;
}

int Min_Heap::get_parent(int i){
    return *(heap_e + get_parentIdx(i));
}

int Min_Heap::get_left_child(int i){
    return *(heap_e + get_leftChildIdx(i));
}

int Min_Heap::get_right_child(int i){
    return *(heap_e + get_rightChildIdx(i));
}

int Min_Heap::get_element(int i){
    return *(heap_e + i);
}

void Min_Heap::heapify_up(int i){
    if(has_parent(i) && get_parent(i) > get_element(i)){
        swap(get_parentIdx(i), i);
        heapify_up(get_parentIdx(i));
    }
}

void Min_Heap::heapify_down(int i){
    //Integrated CodeChum version where right child is priority and comapares to left child
    if(has_right_child(i) && get_element(i) > get_right_child(i) && get_right_child(i) < get_left_child(i)){
        swap(get_rightChildIdx(i), i);
        heapify_down(get_rightChildIdx(i));
    }
    else if(has_left_child(i) && get_element(i) > get_left_child(i)){
        swap(get_leftChildIdx(i), i);
        heapify_down(get_leftChildIdx(i));
    }
    
}

void Min_Heap::insert(int e){
    if(heap_size >= heap_cap) grow();
    else cout << "Capacity is good!" << endl;
    *(heap_e + heap_size) = e;
    heap_size++;
    cout << "New heap elements: " << endl;
    print_heap();
    heapify_up(heap_size-1);
}

int Min_Heap::remove(){
    int temp = *(heap_e);
    if(heap_size == 0) cout << "Heap is empty" << endl;
    else{
        *(heap_e) = *(heap_e + heap_size-1);
        heap_size--;
        if(heap_size <= heap_cap * 0.5) shrink();
        heapify_down(0);
    }
    return temp;
}