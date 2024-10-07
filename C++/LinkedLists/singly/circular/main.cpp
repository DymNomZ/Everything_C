#include <iostream>
#include "cll.h"

using namespace std;

int main(){

    CLL* c = new CLL();
    int n;
    char choice;
    while(choice != 'x'){
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice){
            case 'a':
            cin >> n;
            c->add(n);
            break;

            case 'r':
            cin >> n;
            c->remove(n);
            break;

            case 'q':
            cin >> n;
            c->rotate(n);
            break;

            case 'p':
            c->print();
            break;

            default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

    return 0;
}