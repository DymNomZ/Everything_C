#include <iostream>
#include "list.h"

using namespace std;

int main(){

    list* l = new list();

    int num, pos;
    char c;
    while(c != 'x'){
        cout << "Enter operation: ";
        cin >> c;
        switch (c){
            case 'p':
            l->print();
            break;

            case 'a':
            cin >> num;
            l->add(num);
            break;

            case 'A':
            cin >> pos >> num;
            l->add_at(pos, num);
            break;

            case 'r':
            cin >> num;
            l->remove(num);
            break;

            case 'R':
            cin >> pos;
            l->remove_at(pos);
            break;

            case '$':
            cin >> num;
            l->remove_dupe(num);
            break;

            case '#':
            l->remove_all();
            break;

            case 'y':
            l->reverse();
            break;

            case 's':
            l->sort();
            break;
            
        }
    }

    return 0;
}