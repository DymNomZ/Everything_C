#include <iostream>
#include "doublylist.h"

using namespace std;

int main(){

    doublylist* dl = new doublylist();
    doublylist* d2 = new doublylist();
    doublylist* mu = dl;
    doublylist* mn = d2;
    int x, p;
    char choice, shift;

    while(choice != 'x'){
        cout << "Enter operation: ";
        cin >> choice;
        switch(choice){
            case 's':
            cout << "Size: " << mu->get_size() << endl;
            break;

            case 'a':
            cin >> x;
            mu->add(x);
            break;

            case 'A':
            cin >> x >> p;
            mu->add_at(x, p);
            break;

            case 'r':
            cin >> x;
            mu->remove(x);
            break;

            case 'R':
            cin >> p;
            mu->remove_at(p);
            break;

            case '@':
            mu->remove_all();
            break;

            case '$':
            cin >> x;
            mu->remove_dupe(x);
            break;

            case 'g':
            cin >> p;
            cout << "Ele at index " << p << " is " << mu->get_at(p) << endl;
            break;

            case 'p':
            mu->print();
            break;

            case 'P':
            mu->print_rev();
            break;

            case 'S':
            mu->sort();
            break;

            case 'z':
            cin >> x;
            mu->retain(x);
            break;

            case 'c':
            cin >> x >> p;
            mu->corner(x, p);
            break;

            case 'y':
            cin >> p >> shift;
            mu->rotate(p, shift);
            break;

            case 'm':
            if(mu == dl){
                cout << "Switching to d2..." << endl;
                mu = d2;
                mn = dl;
            }
            else{
                cout << "Switching to dl..." << endl;
                mu = dl;
                mn = d2;
            }
            break;

            case 'M':
            mu->merge(mn);
            break;
        }
    }
}