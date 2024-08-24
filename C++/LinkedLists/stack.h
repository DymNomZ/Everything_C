
class Node {
    public:
    int data;
    Node* next;
};

class Stack{
    Node* head;
    Node* curr = head;

    public:
        Stack();
        int peak();
        void push(int);
        Node* pop();
        void print();
        

};