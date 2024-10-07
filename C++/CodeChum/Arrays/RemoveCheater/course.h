#include <iostream>
#include <math.h>
#include "student.h"
//#include "hidden.h"
using namespace std;
class Course {
	string topic;
	Student** students;
	int size;
	int capacity;
	string removed = "";
	int remove_year = 0;

	public:
	Course(string topic) {
		//students = hidden_init(topic, &this->topic, &size, &capacity);
	}

    // TODO fix this to exclude blocked students
	int addStudent(Student* s) {
	    if(s->program == removed && s->year == remove_year){
	        //cout << removed << " " << remove_year << " is blocked" << endl;
	        return 0;
	   }
	    else{
	    if(size >= capacity){
	        int added = ceil(capacity * 1.5);
	        capacity = added;
	        students = (Student**)realloc(students, capacity * sizeof(Student*));
	    }
	    //students = hidden_addStudent(s, &size, &capacity, students);
	    return 1;
	    }
	}

	// TODO remove a cheater and their classmates
	int removeCheater(string name) {
	int count = 0;
        
        //get program to be removed
	    for(int i = 0; i < size; i++){
	        if(students[i]->name == name){
	            removed = students[i]->program;
	            remove_year = students[i]->year;
	            //cout << removed << endl;
	            break;
	       }
	    }
	    
	    for(int i = 0; i < size; i++){
	        if(students[i]->program == removed && students[i]->year == remove_year){
	        //cout << students[i]->name << endl;
	        delete students[i];
	            for(int j = i; j < size; j++){
	                students[j] = students[j+1];
	            }
	            count++;
	            i--;
	            size--;
	        }
	    }
	   
	    if(size <= (capacity * 2)/3){
	        int reduce = capacity * 0.25;
	        capacity = floor(capacity - reduce);
	        if(capacity <= 5) capacity = 5;
	        students = (Student**)realloc(students, capacity * sizeof(Student*));
	    }
        return count;
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