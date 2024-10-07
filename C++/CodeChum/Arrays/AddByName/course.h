#include <iostream>
#include <math.h>
#include "student.h"
using namespace std;
class Course {
	string topic;
	Student** students;
	int size;
	int capacity;
	Student** final;

	public:
	// TODO constructor
	Course(string topic) {
	    this->topic = topic;
	    size = 0;
	    capacity = 5;
	    students = (Student**)malloc(capacity * sizeof(Student*));
	}
	
	void sort(){
	Student* s;
	    for(int i = 0; i < size; i++){
	        for(int j = 0; j < size-1; j++){
	            if(students[j]->name.compare(students[j+1]->name) >= 0){
	                s = students[j];
	                students[j] = students[j+1];
	                students[j+1] = s;
	            }
	        }
	    }
	}

	// TODO add student
	void addStudent(Student* s) {
	    if(size >= capacity){
	        capacity = ceil(capacity * 1.5);
	        students = (Student**)realloc(students, capacity * sizeof(Student));
	    }
	    *(students + size) = s;
	    size++;
	    sort();
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