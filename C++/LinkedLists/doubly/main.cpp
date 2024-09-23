#include <iostream>
#include "doublylist.h"

using namespace std;

int main(){

    doublylist* dl = new doublylist();
    int x;
    char choice;

    while(choice != 'x'){
        cout << "Enter operation: ";
        cin >> choice;
        switch(choice){
            case 'a':
            cin >> x;
            dl->add(x);
            break;

            case 'p':
            dl->print();
            break;

            case 'P':
            dl->print_rev();
            break;

            case 'r':
            cin >> x;
            dl->remove(x);
            break;

            case 'R':
            cin >> x;
            dl->removedupe(x);
            break;

            case '@':
            dl->removeall();
            break;

            case 's':
            dl->sort();
            break;
        }
    }
}