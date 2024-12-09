#include <iostream>
#include "bst.h"
using namespace std;

int main(void) {
	BST* bst = new BST();
	char op;
	int input, res;
	do {
		cout << "Op: ";
		cin >> op;
		switch (op) {
			case 's':
				cin >> input;
				cout << "Is there " << input << "? " << bst->search(input) << endl;
				break;
			case 'i':
				cin >> input;
				bst->insert(input);
				break;
            case 'r':
				cin >> input;
				bst->remove(input);
				break;
			case 'p':
				bst->print();
				break;
			case 'x':
				cout << "Exiting" << endl;
				break;
            case '?':
                bst->whatValidOrder();
                break;
            case 'P':
                cin >> input;
                res = bst->predecessor(input);
                if(res == -1) cout << "No predecessor" << endl;
                else cout << "Predecessor is: " << res << endl;
                break;
            case 'S':
                cin >> input;
                res = bst->successor(input);
                if(res == -1) cout << "No successor" << endl;
                else cout << "Successor is: " << res << endl;
                break;
			case 'h':
				bst->toMinHeap();
				break;
			case 'H':
				bst->toMaxHeap();
				break;
			default:
				cout << "Invalid operation" << endl;
		}
	} while (op != 'x');

	return 0;
}