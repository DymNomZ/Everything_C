#include <iostream>
#include "stack.h"
#include "queue.h"
#include "list.h"

using namespace std;

void demo_stack();
void demo_queue();
void demo_single_list();

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

            case 3:
            demo_single_list();
            break;

            case 65:
            cout << "Exiting program..." << endl;
            break;

            default:
            cout << "Invalid demo option" << endl;

        }
    }
}

void demo_single_list(){
    cout << "Now demonstrating singly list..." << endl;
    List* list = new List();
    int e, x, i;
    Node* temp;
    while(e != 65){
        cout << "Enter operation: ";
        cin >> e;
        switch(e){
            case 1:
            cout << "Find: ";
            cin >> x;
            cout << "Found at: " << list->find_element(x) << endl;;
            break;

            case 2:
            cout << "Add: ";
            cin >> x;
            list->add(x);
            break;

            case 3:
            temp = list->subtract();
            cout << temp->data << " removed" << endl;
            break;

            case 4:
            cout << "Remove: ";
            cin >> x;
            temp = list->remove(x);
            cout << temp->data << " removed" << endl;
            break;

            case 5:
            cout << "Insert e and i: ";
            cin >> x >> i;
            list->insert(x, i);
            break;

            case 6:
            cout << "Add at start: ";
            cin >> x;
            list->append_start(x);
            break;

            case 7:
            list->remove_start();
            break;

            case 8:
            cout << list->get_count() << " elements" << endl;
            break;

            case 9:
            list->print();
            break;

            case 65:
            cout << "Exiting demo..." << endl;
            break;

            default:
            cout << "Invalid operation" << endl;
        }
    }
    free(temp);
    free(list);
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

            case 65:
            cout << "Exiting demo..." << endl;
            break;

            default:
            cout << "Invalid operation" << endl;
        }
    }
    free(temp);
    free(queue);
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

            case 65:
            cout << "Exiting demo..." << endl;
            break;

            default:
            cout << "Invalid operation" << endl;
        }
    }
    free(temp);
    free(stack);
}