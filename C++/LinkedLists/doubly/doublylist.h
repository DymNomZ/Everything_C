#include <iostream>
#include "node.h"

using namespace std;

class doublylist {
    node* head;
    node* tail;
    int size = 0;

    public:
    doublylist(){
        head = (node*)calloc(1, sizeof(node));
        tail = (node*)calloc(1, sizeof(node));
    }

    void addhead(int num){
        node* n = (node*)calloc(1, sizeof(node));
        n->val = num;
        if(size == 0){
            n->next = head->next;
            n->prev = NULL;
            tail = n;
        }else{
            n->next = head;
            n->prev = NULL;
            head->prev = n;
        }
        head = n;
        size++;
    }

    void addtail(int num){
        node* n = (node*)calloc(1, sizeof(node));
        n->val = num;
        n->next = NULL;
        n->prev = tail;
        tail->next = n;
        tail = n;
        size++;
    }

    void add(int num){
        if(size == 0){
            addhead(num);
        }else{
            addtail(num);
        }
    }

    void removehead(){
        node* store = head;
        cout << "Removed " << head->val << endl;
        head = head->next;
        if(size == 1){
            head = (node*)calloc(1, sizeof(node));
            tail = head;
        }else{
            head->prev = NULL;
        }
        free(store);
        size--;
    }

    void removetail(){
        node* store = tail;
        cout << "Removed " << tail->val << endl;
        tail = tail->prev;
        free(store);
        tail->next = NULL;
        size--;
    }

    bool sorting = false;

    void remove(int num){
        if(size == 0){
            cout << "Nothing to remove!" << endl;
            return;
        }
        if(num == head->val){
            removehead();
            return;
        }else if(num == tail->val && !sorting){
            removetail();
            return;
        }

        node* curr = head;
        while(curr->val != num){
            curr = curr->next;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        cout << "Removed " << curr->val << endl;
        free(curr);
        size--;
    }

    void removedupe(int num){
        if(size == 0){
            cout << "Nothing to remove" << endl;
            return;
        }
        node* curr = head;
        bool found = false;
        while(curr){
            if(curr->val == num){
                remove(curr->val);
                curr = curr->prev;
                found = true;
            }
            curr = curr->next;
        }
        if(!found){
            cout << "Number not found" << endl;
        }

    }

    void removeall(){
        if(size == 0){
            cout << "List empty" << endl;
            return;
        }
        while(size != 0){
            removehead();
        }
    }

    void sort(){
        sorting = true;
        int t_size = size;
        node* curr = head;
        int comp = curr->val;
        int idx = 0;
        while(t_size != 0){
            while(idx < t_size){
                if(curr->val < comp){
                    comp = curr->val;
                }
                curr = curr->next;
                idx++;
            }
            addtail(comp);
            remove(comp);
            curr = head;
            comp = curr->val;
            idx = 0;
            t_size--;
        }
        sorting = false;
    }

    void print(){
        if(size == 0){
            cout << "Nothing to print" << endl;
            return;
        }
        node* curr = head;
        while(curr){
            cout << curr->val << "->";
            curr = curr->next;
        }
        cout << endl;
    }

    void print_rev(){
        if(size == 0){
            cout << "Nothing to print" << endl;
            return;
        }
        node* curr = tail;
        while(curr){
            cout << curr->val << "<-";
            curr = curr->prev;
        }
        cout << endl;
    }
};