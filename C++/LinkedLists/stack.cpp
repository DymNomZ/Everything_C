#include <iostream>
#include "stack.h"

using namespace std;

Stack::Stack(){
    head = NULL;
}

int Stack::peak(){
    cout << "Peeking..." << endl;
    if(head == NULL){
        cout << "No values yet" << endl;
        return -1;
    }
    return curr->data;

}

void Stack::push(int val){
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

Node* Stack::pop(){
    Node* ptr = head;
    Node* pck = (Node*)calloc(1, sizeof(Node));
    if(head == NULL){
        cout << "Stack is empty, returning -1..." << endl;
        pck->data = -1;
        return pck;
    }
    //Loops until next node is current and makes sure itself is not the last node
    while(ptr->next != curr && ptr != curr){
        ptr = ptr->next;
    }
    //if null meaning its the last node, makes head NULL after popping
    if(ptr->next == NULL){
        pck = ptr;
        head = NULL;
        return pck;
    }//Makes the popped node NULL
    else{
        pck = ptr->next;
        ptr->next = NULL;
        curr = ptr;
        return pck;
    }
    free(ptr);
    free(pck);

}

void Stack::print(){
    Node* ptr = head;
    if(head == NULL) cout << "No values yet" << endl;
    else {
        while(ptr != NULL){
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
    free(ptr);
}