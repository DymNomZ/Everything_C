#include "node.h"

class List{
    Node* head;
    Node* tail;

    public:
        List();
        int find_element(int);
        void add(int);
        Node* subtract();
        Node* remove(int);
        void insert(int, int);
        void append_start(int);
        void remove_start();
        int get_count();
        void print();
};