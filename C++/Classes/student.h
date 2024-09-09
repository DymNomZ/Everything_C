#pragma once
#include "human.h"
#include <string>
#include <iostream>

using namespace std;

class Student : Human{

    public:
    string name;
    Student(){
    }

    void talk(){
        cout << "Hello my name is " << name << endl;
    }
};