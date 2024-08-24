#include "node.h"

class Queue{
    Node* head;
    Node* tail;

    public:
        Queue();
        void enqueue(int);
        Node* dequeue();
        int peak_head();
        int peak_tail();
        void print();
};