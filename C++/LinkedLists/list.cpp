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
        //free(ptr);
        return count;
    }
}

void List::add(int e){
    if(head == NULL){
        head = (Node*)calloc(1, sizeof(Node));
        head->data = e;
        head->next = NULL;
    }
    else if(tail == NULL){
        tail = (Node*)calloc(1, sizeof(Node));
        tail->data = e;
        tail->next = NULL;
        head->next = tail;
    }
    else{
        tail->next = (Node*)calloc(1, sizeof(Node));
        tail->next->data = e;
        tail->next->next = NULL;
        tail = tail->next;
    }
}

Node* List::subtract(){
    Node* pck = (Node*)calloc(1, sizeof(Node));
    pck->data = -1;
    pck->next = NULL;
    Node* ptr = head;
    if(tail == NULL){
        cout << "List is empty, returning -1..." << endl;
        return pck;
    }
    else if(ptr->next != NULL){
        while(ptr->next != tail){ //check if ptr is not the only node
            ptr = ptr->next;
        }
        pck = ptr->next;
        ptr->next = NULL;
        tail = ptr;
        return pck;
    }
    else{
        pck = tail;
        tail = NULL;
        head = NULL;
        return pck;
    }
}

Node* List::remove(int e){
    Node* pck = (Node*)calloc(1, sizeof(Node));
    pck->data = -1;
    pck->next = NULL;
    Node* ptr = head;
    if(head == NULL){
        cout << "List is empty, returning -1..." << endl;
        return pck;
    }else if(ptr->data != e){
        while(ptr->next->data != e && ptr->next != NULL){
            ptr = ptr->next;
        }
        if(ptr->next == NULL){
            cout << "Element not found, returning -1..." << endl;
            return pck;
        }else{
            pck = ptr->next;
            ptr->next = ptr->next->next;
            if(ptr->next == NULL) tail = ptr;
            return pck;
        }
    }else{
        pck = head;
        head = head->next;
        if(head == NULL) tail = NULL;
        return pck;
    }
}

void List::insert(int e, int n){
    Node* pck = (Node*)calloc(1, sizeof(Node));
    pck->data = -1;
    pck->next = NULL;
    Node* ptr = head;
    if(head == NULL) cout << "List is empty" << endl;
    else if(n == 0) append_start(e);
    else{
        int count = 1;
        while(count <= n-1 && ptr != NULL){
            ptr = ptr->next;
            count++;
        }
        if(ptr == NULL) cout << "Invalid idx" << endl;
        else{
            pck->data = e;
            pck->next = ptr->next;
            ptr->next = pck;
        }
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
        if(head->next != NULL)head = head->next;
        else{
            head = NULL;
            tail = NULL;
        }
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