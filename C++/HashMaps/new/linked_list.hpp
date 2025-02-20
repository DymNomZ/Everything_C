#include <iostream>
#include "node.hpp"

using namespace std;

class LinkedList {

    int size;
    Node* head;

    public:
        LinkedList(){
            size = 0;
            head = (Node*)calloc(1, sizeof(Node));
        }

        void add(string s){
            if(size == 0) head->val = s;
            else{
                Node* n = (Node*)calloc(1, sizeof(Node));
                n->val = s;
                n->next = head;
                head = n;
            }
            size++;
        }

        bool search(string s){
            if(size == 0){
                cout << "map empty" << endl;
                return false;
            }
            Node* n = head;
            while(n){
                if(n->val == s) return true;
            }
            return false;
        }

        void print(){
            if(size == 0){
                cout << "empty" << endl;
                return;
            }
            Node* n = head;
            while(n){
                cout << n->val << " ";
                if(n->next) cout << "-> ";
                n = n->next;
            }
            cout << endl;
        }

        bool remove(string s){
            if(size == 0){
                cout << "map empty" << endl;
                return false;
            }
            //if string is at the start
            if(head->val == s && size > 1){
                Node* store = head;
                head = head->next;
                free(store);
                size--;
                return true;
            }
            else{
                Node* n = head;

                //assure not null or garbage
                while(n->next->val != s && n->next) n = n->next;

                //assure not null or garbage
                if(n->next){
                    Node* store = n->next;
                    if(n->next->next) n->next = n->next->next;
                    free(store);
                    size--;
                    return true;
                }

                //element is not found, return
                return false;
            }
        }
};