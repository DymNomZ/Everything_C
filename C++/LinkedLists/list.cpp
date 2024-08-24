#include <iostream>
#include "list.h"

using namespace std;

List::List(){
    head = NULL;
}

int List::peak(){
    cout << "Peeking..." << endl;
    if(head == NULL){
        cout << "No values yet" << endl;
        return -1;
    }
    return curr->data;

}

void List::push(int val){
    if(head == NULL){
        head = (Node*)calloc(1, sizeof(Node));
        curr = head;
        head->data = val;
    }else{
        curr->next = (Node*)calloc(1, sizeof(Node));
        curr->next->data = val;
        curr->next->next = NULL;
        curr = curr->next;
        
    }
    
}

Node List::pop(){
    Node* ptr = head;
    Node pck;
    while(ptr->next != curr){
        ptr = ptr->next;
    }
    pck = *curr;
    curr = ptr;
    ptr->next = NULL;
    return pck;
}

void List::print(){
    Node* ptr = head;
    if(head == NULL) cout << "No values yet" << endl;
    else {
        while(ptr != NULL){
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
    
}