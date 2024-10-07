#include <iostream>
using namespace std;

struct Person {
	string firstName;
	string lastName;
	int age;
	int requests[4];

	void print_name() {
		cout << firstName << " " << lastName << endl;
	}
	
	int get_num(){
	    int count = 0;
	    for(int i = 0; i < 4; i++){
	        if(requests[i] == 1) count++;
	    }
	    return count;
	}
};