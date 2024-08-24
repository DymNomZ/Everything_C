#include <iostream>
#include "queue.h"

using namespace std;

Queue::Queue(){
    head = NULL;
    tail = NULL;
}

void Queue::enqueue(int val){
    if(head == NULL){
        head = (Node*)calloc(1, sizeof(Node));
        tail = (Node*)calloc(1, sizeof(Node));
        //tail = (Node*)calloc(1, sizeof(Node));
        tail->data = val;
        head = tail;
        tail->next = head;
    }else{
        head->next = (Node*)calloc(1, sizeof(Node));
        head->next->data = val;
        head->next->next = NULL;
        head = head->next;
    }
}

Node* Queue::dequeue(){
    Node* pck = (Node*)calloc(1, sizeof(Node));
    Node* ptr = tail;
    if(ptr == NULL){
        cout << "Queue empty, returning -1..." << endl;
        pck->data = -1;
        return pck;
    }
    if(tail->next == NULL){
        cout << 1;
        pck = ptr;
        tail = NULL;
        head = NULL;
        return pck;
    }
    else{
        cout << 2;
        tail = tail->next;
        pck = ptr;
        ptr = NULL;
        return pck;
    }


}

int Queue::peak_head(){
    cout << "Peeking head..." << endl;
    if(head == NULL) return -1;
    else return head->data;
}

int Queue::peak_tail(){
    cout << "Peeking tail..." << endl;
    if(tail == NULL) return -1;
    else return tail->data;
}

void Queue::print(){
    if(tail == NULL) cout << "Queue empty" << endl;
    else{
        Node* ptr = tail;
        while(ptr != NULL){
            cout << ptr->data << " ";
            ptr = ptr->next;
            if(head == tail) ptr = NULL; //check if tail and head meet, meaning only one node
        }
        cout << endl;
    }

}