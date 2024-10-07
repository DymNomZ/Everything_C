#include <iostream>
#include "course.h"
using namespace std;

int main(int argc, char** argv) {
	Course* csit = new Course("CSIT221");
	char op;
	Student* s;
	int res;
	string name;
	while (true) {
		cout <<"Op: ";
		cin >> op;
		switch (op){
			case 'a':
				s = new Student;
				cout << "Name: ";
				cin >> s->name;
				cout << "Program and Year: ";
				cin >> s->program >> s->year;
				res = csit->addStudent(s);
				if (res == 0) {
				    cout << s->program << " " << s->year << " is blocked" << endl;
				}
				break;
			case 'c':
			    cout << "Who cheated? ";
			    cin >> name;
			    cout << "Removed " << csit->removeCheater(name) << " student/s" << endl;
				break;
			case 'p':
				csit->print();
				break;
			case 'x':
			    cout << "Exiting" << endl;
				return 0;
		}
	}
	return 0;
}