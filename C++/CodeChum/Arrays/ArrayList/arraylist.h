#include <iostream>
#include <cstdlib>
#include <math.h>
#include "list.h"
using namespace std;

class ArrayList : public List {
    double* array;
    int size;
    int capacity = 5;

    public:
    // constructor
    ArrayList() {
        array = (double*) calloc( capacity, sizeof(double) );
        size = 0;
    }

    void add(double num) {
    if(size >= capacity){
            capacity *= 2;
            array = (double*)realloc(array, capacity * sizeof(double));
        }
        array[size++] = num;
    }

    int remove(double num) {
        // TODO implement remove with dynamic array
        int ret = 0;
        int found = 0;
        int check = capacity / 2;
        for(int i = 0; i < size; i++){
            if(array[i] == num){
            found = 1;
            ret = i+1;
                for(int j = i; j < size; j++){
                    array[j] = array[j+1];
                }
                size--;
                break;
            }
        }
        if(size <= check){
            capacity = ceil(capacity * 0.70);
            if(capacity <= 5) capacity = 5;
            array = (double*)realloc(array, capacity * sizeof(double));
        }
        if(found == 1) return ret;
        else return -1;
    }

    double get(int pos) {
        return array[pos-1];
    }

    void print() {
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