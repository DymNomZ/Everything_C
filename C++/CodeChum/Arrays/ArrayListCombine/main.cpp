#include <iostream>
#include "arraylist.h"
using namespace std;

int main() {
    List* list1 = new ArrayList();
    List* list2 = new ArrayList();
    List* curr = list1;
    char ch;
    int num, pos;
    cout << "Currently on list1" << endl;
    do {
        cout << "Op: ";
        cin >> ch;
        switch (ch) {
            case 'a':
                cin >> num;
                curr->add(num);
                break;
            case 'z':
                cin >> num >> pos;
                curr->addAt(num, pos);
                break;
            case 's':
                if (curr == list1) {
                    cout << "Switching to list2" << endl;
                    curr = list2;
                } else {
                    cout << "Switching to list1" << endl;
                    curr = list1;
                }
                break;
            case 'c':
                curr->combine(curr == list1 ? list2 : list1);
                cout << "Lists combined" << endl;
                break;
            case 'r':
                cin >> num;
                cout << "Removed " << num << " at pos " << curr->remove(num) << endl;
                break;
            case 'p':
                curr->print();
                break;
            case 'x':
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid operation" << endl;
        }
    } while (ch != 'x');
    return 0;
}