#include <iostream>
#include "class_list.h"
#include "student.h"

using namespace std;

int main(){
    Student* test;
    Class_List* cl = new Class_List();
    string n;
    char c;
    while(c != 'x'){
        cout << "Enter operation: ";
        cin >> c;
        cin.ignore();
        switch(c){
            case 'a':
            test = new Student();
            cout << "Enter student name: ";
            getline(cin, test->name);
            cl->add(test);
            break;

            case 'p':
            cl->print();
            break;

            case 'r':
            cout << "Student to be removed: ";
            cin >> n;
            test = cl->remove(n);
            if(test == nullptr) cout << "Student not found!" << endl;
            else cout << "Student removed: " << test->name << endl;
            break;

            case 'x':
            return 0;

        }
    }
}