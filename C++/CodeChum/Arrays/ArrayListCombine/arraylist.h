#include <iostream>
#include <cstdlib>
#include <math.h>
#include "list.h"
using namespace std;

class ArrayList : public List {
    int* array;
    int size;
    int capacity = 5;

    public:
    // constructor
    ArrayList() {
    	array = (int*) calloc( capacity, sizeof(int) );
        size = 0;
    }

    void grow(){
        capacity = ceil(capacity * 1.5);
        array = (int*)realloc(array, capacity * sizeof(int));
    }

    // TODO add
    void add(int num) {
        if(size >= capacity){
            grow();
        }
        array[size++] = num;

    }

    void addAt(int num, int pos){
        if(pos > size){
            cout << "Throws logic_error"<< endl;
            return;
        }

        if(size + 1 > capacity){
            grow();
        }

        int p = pos-1;

        for(int i = size-1; i >= p; i--){
            array[i+1] = array[i];
        }

        array[p] = num;
        size++; 
    }

    // TODO remove
    int remove(int num) {
        int rem = 0;
        for(int i = 0; i < size; i++){
            if(array[i] == num){
            rem = i+1;
                for(int j = i; j < size-1; j++){
                    array[j] = array[j+1];
                }
                break;
            }
        }
        size--;
        if(size <= (capacity * 2) / 3){
            capacity -= floor(capacity * 0.25);
            if(capacity <= 5) capacity = 5;
            array = (int*)realloc(array, capacity * sizeof(int));
        }
        return rem;
    }

    bool isEmpty() {
        return size == 0;
    }

    int get(int pos) {
        return array[pos-1];
    }

    // TODO perform combine
    void combine(List* list) {
        while(!list->isEmpty()){
            add(list->removeAt(0));
        }
        capacity = size + ceil(size * 0.25);
        if(capacity <= 5) capacity = 5;
        array = (int*)realloc(array, capacity * sizeof(4));
            
        
    }

    // OPTIONAL add method removeAt here
    int removeAt(int pos) {
        int rem = array[pos];
        remove(array[pos]);
        return rem;
    }

    // DO NOT CHANGE
    void print() {
        cout << "Size: " << size << "/" << capacity << endl;
        int i;
        for (i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        for (; i < capacity; i++) {
            cout << "? ";
        }
        cout << endl;
    }
};