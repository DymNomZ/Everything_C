// Warning: Do not modify this file.
// Create the list's and linkedlist.h's removeAt method

#include <iostream>
#include "linkedlist.h"

int main() {
	LinkedList* list = new LinkedList();
    int input, num, pos, left, right, res;
    char op;
    do {
    	cout << "Enter op: ";
    	cin >> op;
    	switch (op) {
    		case 'a' :
		    	cin >> input;
		    	list->add(input);
		    	break;
            case '@':
                cin >> num >> pos;
                list->addAt(num, pos);
                break;
            case 'r':
                cin >> pos;
                cout << "Removed " << list->removeAt(pos) << endl;
                break;
            case 'R':
		    	cin >> input;
                cout << "Removed position " << list->remove(input) << endl;
		    	break;
            case 'c':
                cin >> left;
                cin >> right;
                cout << "Removed " << list->corner(left, right) << " element/s" << endl;
                break;
		    case 's':
		    	cout << "Size: " << list->_size() << endl;
		    	break;
		    case '=':
                cin >> input;
                cout << "Removed " << list->retain(input) << " element/s" << endl;
                break;
            case 'g':
		    	cin >> input;
                res = list->get(input);
                if (res == -1) {
                    cout << "Invalid position: " << input << endl;
                } else {
                    cout << "Element at position " << input << " is " << res << endl;
                }
		    	break;
		    case 'p':
		    	list->print();
		    	break;
		    case 'x':
		    	cout << "Exiting";
		    	break;
		}
	} while (op != 'x');
    return 0;
}