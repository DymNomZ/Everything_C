
class Node {
    public:
    int data;
    Node* next;
};

class List{
    Node* head;
    Node* curr = head;

    public:
        List();
        int peak();
        void push(int);
        Node pop();
        void print();
        

};