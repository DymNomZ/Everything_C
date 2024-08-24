#include <iostream>
#include "stack.h"

using namespace std;

int main(){

    Stack* stack = new Stack();

    int e, i;
    Node* temp;

    while(e != 65){
        cout << "Enter operation: ";
        cin >> e;
        switch(e){
            case 1:
            cout << stack->peak() << " top element" << endl;
            break;

            case 2:
            cout << "Push element: ";
            cin >> i;
            stack->push(i);
            break;

            case 3:
            temp = stack->pop();
            cout << "Popped Node: " << temp->data << endl;
            break;

            case 4:
            stack->print();
            break;

            default:
            cout << "Invalid operation" << endl;
        }
    }
}