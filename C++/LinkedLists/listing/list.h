#include <iostream>
#include "node.h"

using namespace std;

class list {
    node* head;
    node* tail;
    int size = 0;

    public:
    list(){
        //head = (node*)calloc(1, sizeof(node));
        //tail = (node*)calloc(1, sizeof(node));
    }

    void remove_head(){
        cout << "Removed " << head->val << " from Head" << endl;
        node* store = head;
        head = head->next;
        free(store);
        size--;
    }

    void remove(int num){
        if(size == 0){
            cout << "Nothing to remove" << endl;
            return;
        }
        node* track = head;
        //if num is at head
        if(track->val == num){
            remove_head();
            return;
        }
        while(track->next){
            if(track->next->val == num){
                cout << "Removed " << track->next->val << endl;
                //check if track is tail
                if(track->next == tail){
                    tail = track;
                    free(track->next);
                    track->next = NULL;
                }else{
                    //any other number
                     //store removed_node+1
                    node* store = track->next->next;
                    free(track->next);
                    track->next = store;
                }
                size--;
                return;
            }
            track = track->next;
        }
        if(track->next == NULL){
            cout << "Number not found" << endl;
            return;
        }
    }

    void remove_at(int pos){
        if(pos > size){
            cout << "Invalid position" << endl;
            return;
        }
        int i = 1;
        node* track = head;
        while(track){
            if(pos == i){
                cout << "Removed " << track->val << " at pos: " << i << endl;
                remove(track->val);
                return;
            }
            i++;
            track = track->next;
        }
    }

    void remove_dupe(int num){
        node* track = head;
        node* prev = head;
        bool found = false;
        while(track){
            if(track->val == num){
                found = true;
                remove(track->val);
                //print();
                track = prev;
            }
            prev = track;
            track = track->next;
        }
        if(!found){
            cout << "Number not found" << endl;
        }
    }

    void remove_all(){
        if(size == 0){
            cout << "Nothing to remove" << endl;
        }
        while(size){
            remove_head();
        }
    }

    void reverse(){
        node* curr = head;
        node* prev = head;
        node* next = head->next;
        curr = head->next;
        // 1 2 3 4 5
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        tail = head;
        head = prev;
        tail->next = NULL;
    }

    void add_head(int num){
        node* n = (node*)calloc(1, sizeof(node));
        n->val = num;
        if(size == 0){
            head =(node*)calloc(1, sizeof(node));
            tail = (node*)calloc(1, sizeof(node));
            n->next = head->next;
            head = n;
            tail = n;
        }else{
            n->next = head;
            head = n;
        }
        size++;
        return;
    }

    void add_tail(int num){
        node* n = (node*)calloc(1, sizeof(node));
        n->val = num;
        n->next = NULL;
        tail->next = n;
        tail = n;
        size++;
    }

    void add(int num){
        if(size == 0){
            add_head(num);
        }else{
            add_tail(num);
        }
        //sort();
    }

    void add_at(int pos, int num){
        if(size == 0){
            cout << "List is empty" << endl;
            return;
        }
        if(pos == 1){
            add_head(num);
            return;
        }
        if(pos > size){
            add_tail(num);
            return;
        }
        //neither of the two so we start at second node
        int i = 2;
        node* track = head;
        while(track){
            if(pos == i){
                node* n = (node*)calloc(1, sizeof(node));
                n->val = num;
                n->next = track->next;
                track->next = n;
                size++;
                return;
            }
            track = track->next;
            i++;
        }
    }

    void sort(){
        int temp = size;
        node* curr = head;
        node* smallest = curr;
        int i = 0;
        while(temp != 0){
            while(i != temp){
                if(curr->val < smallest->val){
                    smallest = curr;
                }
                curr = curr->next;
                i++;
            }
            add_tail(smallest->val);
            remove(smallest->val);
            print();
            curr = head;
            smallest = curr;
            temp--;
            i = 0;
        }
    }

    void print(){
        if(size == 0){
            cout << "List is empty" << endl;
            return;
        }
        node* track = head;
        while(track){
            cout << track->val << "->" ;
            track = track->next;
        }
        cout << endl << "Total: " << size << endl;
        free(track);
    }
};