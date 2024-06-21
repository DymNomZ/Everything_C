#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* link;
};

void insertFront(Node** head, int num){
    Node* temp = new Node();
    temp->data = num;
    temp->link = NULL;
    if(*head != NULL) temp->link = *head;
    *head = temp;
}

void insertEnd(Node** head, int num){
    Node* temp = new Node();
    temp->data = num;
    temp->link = NULL;
    if(*head == NULL) *head = temp;
    else {
        Node* tracer = *head;
        while(tracer->link != NULL){
            tracer = tracer->link;
        }
        tracer->link = temp;
    }
}

void insertAtIdx(Node* head, int index){
    Node* temp = new Node();
    temp->data = 13;
    temp->link = NULL;
    int count = 0;
    Node* tracer = head;
    while(count != index){
        tracer = tracer->link;
    }
    Node* next = tracer->link;
    tracer->link = temp;
    temp->link = next;
}

void print(Node* head, int amt){
    cout << "These are the elements:" << endl;
    for(int i = 0; i < amt; i++){
        cout << head->data << endl;
        head = head->link;
    }
}

int main(){
    Node* head;
    head = NULL;
    int amt, num;
    cout << "How many? ";
    cin >> amt;
    cout << "Enter elements:" << endl;
    for(int i = 0; i < amt; i++){
        cin >> num;
        //insertFront(&head, num);
        insertEnd(&head, num);
    }
    print(head, amt);

    int index;
    cout << "Enter index: ";
    cin >> index;

    insertAtIdx(head, index);
    print(head, amt+1);
    return 0;
}