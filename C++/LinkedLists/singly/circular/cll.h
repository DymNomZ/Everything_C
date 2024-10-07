#include <iostream>
#include "node.h"

using namespace std;

class CLL {
    node* head;
    node* tail;
    int size = 0;

    public:
    CLL(){
        head = NULL;
        tail = NULL;
    }

    void add_first(int num){
        node* n = (node*)calloc(1, sizeof(node));
        n->val = num;
        if(size == 0){
            head = n;
            tail = n;
        }else{
            n->next = head;
            head = n;
        }
        size++;
    }

    void add_last(int num){
        node* n = (node*)calloc(1, sizeof(node));
        n->val = num;
        if(head == 0){
            head = n;
        }else{
            tail->next = n;
        }
        tail = n;
        tail->next = head;
        size++;
    }

    void add(int num){
        if(size == 0){
            add_first(num);
        }else{
            add_last(num);
        }
    }

    void remove_head(){
        node* store = head;
        head = head->next;
        tail->next = head;
        free(store);
        size--;
    }

    void remove_tail(){
        node* curr = head;
        while(curr->next != tail) curr = curr->next;
        free(tail);
        tail = curr;
        curr->next = head;
        size--;
    }

    void remove_node(node* curr){
        node* store = curr->next->next;
        free(curr->next);
        curr->next = store;
        size--;
    }

    void remove(int num){
        if(size == 0){
            cout << "List empty" << endl;
            return;
        }
        if(head->val == num){
            remove_head();
            return;
        }
        if(tail->val == num){
            remove_tail();
            return;
        }
        node* curr = head;
        while(curr->next){
            if(curr->next->val = num){
                remove_node(curr);
                break;
            }
            curr = curr->next;
        }
        if(curr->next == NULL) cout << "Number not found" << endl;
    }

    void rotate(int shift){
        cout << "Rotating list by: " << shift << endl;
        while(shift != 0){
            head = head->next;
            tail = tail->next;
            shift--;
        }
    }

    void print(){
        if(size == 0) cout << "List is empty" << endl;
        else{
            node* curr = head;
            do{
                cout << curr->val << "->";
                curr = curr->next;
            }while(curr != head);
            cout << endl;
        }
    }

};