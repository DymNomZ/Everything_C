#include <iostream>
#include "list.h"

using namespace std;

List::List(){
    head = NULL;
    tail = NULL;
}

int List::find_element(int e){
    if(head == NULL) return -1;
    else{
        Node* ptr = head;
        int count = 0;
        while(ptr->data != e){
            count++;
            ptr = ptr->next;
        }
        free(ptr);
        return e;
    }
}

void List::add(int e){
    if(head == NULL){
        head = (Node*)calloc(1, sizeof(Node));
        tail = (Node*)calloc(1, sizeof(Node));
        head->data = e;
        head->next = NULL;
        tail = head;
        //cout << head->data << endl;
    }
    else{
        Node* pck = (Node*)calloc(1, sizeof(Node));
        pck->data = e;
        pck->next = NULL;
        tail->next = pck;
        tail = pck;
    }
}

Node* List::subtract(){
    Node* pck = (Node*)calloc(1, sizeof(Node));
    if(tail == NULL){
        cout << "List is empty, returning -1..." << endl;
        pck->data = -1;
        return pck;
    }
    if(tail->next == NULL){
        pck->data = tail->data;
        tail = NULL;
        head = NULL;
        return pck;
    }
    else{
        Node* ptr = head;
        while(ptr->next != tail){
            ptr = ptr->next;
        }
        pck = ptr->next;
        //free(ptr->next);
        ptr->next = NULL;
        tail = ptr;
        //free(ptr);
        return pck;
    }
}

Node* List::remove(int e){
    Node* pck = (Node*)calloc(1, sizeof(Node));
    if(head == NULL){
        cout << "List is empty, returning -1..." << endl;
        pck->data = -1;
        return pck;
    }else{
        Node* ptr = head;
        while(ptr->next->data != e){
            ptr = ptr->next;
        }
        pck = ptr->next;
        ptr->next = NULL;
        ptr->next = pck->next;
        
        //free(ptr);
        return pck;
    }
}

void List::insert(int e, int n){
    if(head == NULL) cout << "List is empty" << endl;
    else{
        int count = 0;
        Node* ptr = head;
        while(count != n-1 && ptr->next != NULL){
            ptr = ptr->next;
        }
        Node* pck = (Node*)calloc(1, sizeof(Node));
        pck->data = e;
        pck->next = ptr->next;
        ptr->next = pck;
        free(ptr);
    }
}

void List::append_start(int e){
    if(head == NULL) cout << "List is empty" << endl;
    else{
        Node* pck = (Node*)calloc(1, sizeof(Node));
        pck->data = e;
        pck->next = head;
        head = pck;
    }
}

void List::remove_start(){
    if(head == NULL) cout << "List is empty" << endl;
    else{
        Node* ptr = head;
        head = head->next;
        free(ptr);
    }
}

int List::get_count(){
    if(head == NULL) return 0;
    else{
        int count = 0;
        Node* ptr = head;
        while(ptr != NULL){
            count++;
            ptr = ptr->next;
        }
        return count;
    }
}

void List::print(){
    if(head == NULL) cout << "List is empty" << endl;
    else{
        Node* ptr = head;
        while(ptr != NULL){
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
}