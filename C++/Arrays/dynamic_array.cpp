#include <iostream>
#include "dynamic_array.h"
#include <math.h>

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
    bool found = false;
    for(int i = 0; i < count_size; i++){
        if(e == *(arr + i)){
            found = true;
            for(int j = i; j < count_size-1; j++){
                *(arr + j) = *(arr + j+1);
            }
            *(arr + count_size-1) = 0;
            if(count_size > 0) count_size--;
            if(count_size < (curr_size / 2)) reduce();
            cout << "Removed element" << endl;
        }
    }
    if(!found) cout << "Element not found" << endl;
}

void Dynamic_Array::remove_at(int idx){
    if(idx >= count_size) cout << "Inavlid idx" << endl;
    else{
        for(int j = idx; j < count_size-1; j++){
            *(arr + j) = *(arr + j+1);
        }
        *(arr + count_size) = 0;
        if(count_size > 0) count_size--;
        if(count_size < (curr_size / 2)) reduce();
        cout << "Removed element at idx " << idx << endl;
    }

}

int Dynamic_Array::remove_all(){
    if(curr_size == 0){
        cout << "Array is empty" << endl;
        return 0;
    }else{
        int last_size = count_size;
        free(arr);
        arr = (int*)calloc(init_size, 4);
        curr_size = init_size;
        count_size = 0;
        return last_size;
    }
}

void Dynamic_Array::insert(int e, int idx){
    if(count_size + 1 >= curr_size){
        resize();
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

void Dynamic_Array::resize(){
    cout << "Resizing...." << endl;

    curr_size *= 2;
    arr = (int*)realloc(arr, curr_size*4);

    cout << "Resizing complete!" << endl;
}

void Dynamic_Array::reduce(){
    cout << "Shrinking..." << endl;

    curr_size = ceil(curr_size * 0.5);
    if(curr_size <= 5) curr_size = 5;

    arr = (int*)realloc(arr, curr_size*4);
    
    cout << "Shrinking complete!" << endl;
}

void Dynamic_Array::append_at_start(int e){
    if(count_size + 1 >= curr_size){
        resize();
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
        resize();
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
    if(curr_size == 0){
        cout << "Array is empty" << endl;
        return;
    }
    for(int i = 0; i < curr_size; i++){
        cout << *(arr + i) << " " ;
    }
    cout << endl;
}