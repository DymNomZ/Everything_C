#include <iostream>
#include "stack.h"
#include "queue.h"

using namespace std;

void demo_stack();
void demo_queue();

int main(){

    int e;
    while(e != 65){
        cout << "Choose demo: ";
        cin >> e;
        switch(e){
            case 1:
            demo_stack();
            break;
            
            case 2:
            demo_queue();
            break;
        }
    }
}

void demo_queue(){
    cout << "Now demonstrating Queue..." << endl;
    Queue* queue = new Queue();
    int e, i;
    Node* temp;
    while(e != 65){
        cout << "Enter operation: ";
        cin >> e;
        switch(e){
            case 1:
            cout << "Enqueue: ";
            cin >> i;
            queue->enqueue(i);
            break;

            case 2:
            temp = queue->dequeue();
            cout << "Dequeued node: " << temp->data << endl;
            break;

            case 3:
            cout << queue->peak_head() << " at head" << endl;
            break;

            case 4:
            cout << queue->peak_tail() << " at tail" << endl;
            break;

            case 5:
            queue->print();
            break;

            default:
            cout << "Invalid operation" << endl;
        }
    }
}

void demo_stack(){
    cout << "Now demonstrating stack..." << endl;
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