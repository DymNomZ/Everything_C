#include "student.h"
#include <iostream>
#include <math.h>

using namespace std;

class Class_List{
    Student** students;
    int size = 0;
    int capacity = 5;

    public:
    Class_List(){
        students = (Student**)malloc(5 * sizeof(Student*));
    }

    void add(Student* s){
        if(size >= capacity){
            cout << "Oops, list is full! Resizing...." << endl;
            cout << "Old capacity: " << capacity;
            capacity *= 2;
            students = (Student**)realloc(students, capacity * sizeof(Student*));
            cout << "   New capacity: " << capacity << endl;

        }
        *(students + size) = s;
            size++;
    }

    Student* remove(string name){
        Student* ret = nullptr;
        for(int i = 0; i < size; i++){
            if(students[i]->name == name){
                ret = students[i];
                for(int j = i; j < size-1; j++){
                    students[j] = students[j+1];
                }
                size--;
                break;
            }   
        }
        if(size <= capacity / 2){
            cout << "Shrinking list..." << endl;
            cout << "Old capacity: " << capacity;
            capacity = floor(capacity / 2);
            if(capacity <= 5) capacity = 5;
            cout << "   New capacity: " << capacity << endl;
            students = (Student**)realloc(students, capacity * sizeof(Student*));
        }
        return ret;
    }

    void print(){
        for(int i = 0; i < size; i++){
            students[i]->talk();
        }
        for(int i = size; i < capacity; i++){
            cout << "Empty ???" << endl;
        }
    }
};