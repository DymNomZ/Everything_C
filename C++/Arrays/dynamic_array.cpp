#include <iostream>
#include "dynamic_array.h"

using namespace std;

Dynamic_Array::Dynamic_Array(int size){
    init_size = size;
    curr_size = size;
    count_size = 0;
    arr = (int*)calloc(size, 4);
}

int Dynamic_Array::get_size(){
    return curr_size;
}

int Dynamic_Array::get_num_elements(){
    return count_size;
}

int Dynamic_Array::get_element_at_index(int idx){
    if(idx >= count_size) return -1;
    else return *(arr + idx);
}

int Dynamic_Array::find_element(int e){
    for(int i = 0; i < count_size; i++){
        if(e == *(arr + i)){
            return i;
        }
    }
    return -1;
}

void Dynamic_Array::remove(int e){
    for(int i = 0; i < count_size; i++){
        if(e == *(arr + i)){
            for(int j = i; j < count_size-1; j++){
                *(arr + j) = *(arr + j+1);
            }
            *(arr + count_size) = 0;
            if(count_size > 0) count_size--;
            cout << "Removed element" << endl;
        }
    }
}

void Dynamic_Array::remove_at(int idx){
    if(idx >= count_size) cout << "Inavlid idx" << endl;
    else{
        for(int j = idx; j < count_size-1; j++){
            *(arr + j) = *(arr + j+1);
        }
        *(arr + count_size) = 0;
        if(count_size > 0) count_size--;
        cout << "Removed element at idx " << idx << endl;
    }

}

void Dynamic_Array::insert(int e, int idx){
    if(count_size + 1 >= curr_size){
        arr = resize(arr, &curr_size);
    }
    if(count_size == 0) {
        cout << "First ever element, inserted at beginning" << endl;
        *(arr) = e;
        count_size++;
    }
    else if(idx < count_size){
        for(int j = count_size; j > idx; j--){
            *(arr + j) = *(arr + j-1);
        }
        *(arr + idx) = e;
        count_size++;
        cout << "Inserted element at idx " << idx << endl;
    }else cout << "Inavlid idx" << endl;

}

int* Dynamic_Array::resize(int* arr, int* curr_size){
    cout << "Resizing...." << endl;
    int *temp = (int*)calloc(*curr_size*2, 4);
    for(int i = 0; i < *curr_size; i++){
        *(temp + i) = *(arr + i);
    }
    *curr_size *= 2;
    cout << "Resizing complete!" << endl;
    return temp;
}

void Dynamic_Array::append_at_start(int e){
    if(count_size + 1 >= curr_size){
        arr = resize(arr, &curr_size);
    }
    for(int j = count_size; j > 0; j--){
        *(arr + j) = *(arr + j-1);
    }
    *(arr) = e;
    count_size++;
    cout << "Appended element at start" << endl;
}

void Dynamic_Array::append_at_end(int e){
    if(count_size + 1 >= curr_size){
        arr = resize(arr, &curr_size);
    }
    *(arr + count_size) = e;
    count_size++;   
    cout << "Appended element at end" << endl;
}

void Dynamic_Array::remove_at_start(){
    for(int j = 0; j < count_size-1; j++){
        *(arr + j) = *(arr + j+1);
    }
    *(arr + count_size) = 0;
    if(count_size > 0) count_size--;
    cout << "Removed element at start" << endl;
}

void Dynamic_Array::remove_at_end(){
    *(arr + count_size) = 0;
    if(count_size > 0) count_size--;
    cout << "Removed element at end" << endl;
}

void Dynamic_Array::print(){
    for(int i = 0; i < curr_size; i++){
        cout << *(arr + i) << " " ;
    }
    cout << endl;
}