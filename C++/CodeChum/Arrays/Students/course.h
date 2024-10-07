#include <iostream>
#include <math.h>
#include "student.h"
using namespace std;
class Course {
	string topic;
	Student** students;
	int size;
	int capacity;

	public:
	// TODO constructor
	Course(string topic) {
	    this->topic = topic;
	    size = 0;
	    capacity = 5;
	    students = (Student**)malloc(capacity * sizeof(Student));
	}

	// TODO add student
	void addStudent(Student* s) {
	    if(size >= capacity){
	        capacity = ceil(capacity * 1.5);
	        students = (Student**)realloc(students, capacity * sizeof(Student));
	    }
	    if(size == 0){
	    *(students + size) = s;
	    size++;
	    }
	    else{
	    int high = 0;
	    for(int i = 0; i < size; i++){
	        if(students[i]->year < s->year){
	        high = 1;
	            for(int j = size; j > i; j--){
	                students[j] = students[j-1];
	            }
	            *(students + i) = s;
	            size++;
	            break;
	        }
	    }
	    if(high == 0){
	        *(students + size) = s;
	        size++;
	        }
	    }
	}

    string removeStudent(string name) {
	string ret;
	int found = 0;
	    for(int i = 0; i < size; i++){
	        if(students[i]->name == name){
	            ret = students[i]->program;
	            delete students[i];
	            found = 1;
	            for(int j = i; j < size-1; j++){
	                students[j] = students[j+1];
	            }
	            size--;
	            break;
	        }
	    }
	    if(size <= (capacity * 2)/3){
	        int reduce = floor(capacity * 0.25);
	        capacity -= reduce;
	        if(capacity <= 5) capacity = 5;
	        students = (Student**)realloc(students, capacity * sizeof(Student));
	    }
	    if(found) return ret;
        else return "";
	}

	// DO NOT MODIFY
	void print() {
		cout << "Title: "<< topic << endl;
		cout << "Student size: " << size << "/" << capacity << endl;
		for (int i = 0; i < capacity; i++) {
			if (i >= size) {
				cout << i+1<< ". (none)" << endl;
			} else {
			    Student* s = students[i];
				cout << i+1 << ". " << s->name << " (" << s->program << " " << s->year << ")" << endl;
			}
		}
	}
};