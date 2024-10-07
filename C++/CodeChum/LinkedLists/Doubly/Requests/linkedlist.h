#include "node.h"

class LinkedList {
	node* head;
	node* tail;
	node* senior;
	int size;

	public:
	LinkedList() {
		head = new node;
		tail = new node;
		head->next = tail;
		tail->prev = head;
		senior = head;
		size = 0;
	}
	
	node* add_between(Person* p, node* pred, node* succ){
	    node* n = new node;
	    n->person = p;
	    n->prev = pred;
	    n->next = succ;
	    pred->next = n;
	    succ->prev = n;
	    size++;
	    return n;
	}

	// TODO add a person
	void add(Person* p) {
	    if(p->age >= 60){
	        senior = add_between(p, senior, senior->next);
	    }else{
	        add_between(p, tail->prev, tail);
	    }
	}
	
	void remove(node* curr){
	    node* pred = curr->prev;
	    node* succ = curr->next;
	    pred->next = succ;
	    succ->prev = pred;
	    size--;
	    if(curr == senior){
	        senior = pred;
	    }
	    free(curr);
	}

	// TODO serve the request
	Person* serveRequest(char ch) {
	    int index = 0;
	    if(ch == 'B') index = 0;
	    else if(ch == 'M') index = 1;
	    else if(ch == 'C') index = 2;
	    else if(ch == 'D') index = 3;
	    
	    Person* p = NULL;
	    node* curr = head->next;
	    while(curr != tail){
	        if(curr->person->requests[index] == 1){
	            p = curr->person;
	            curr->person->requests[index] = 0;
	            if(p->get_num() == 0){
	                remove(curr);
	            }
	            break;
	        }
	        curr = curr->next;
	    }
	    return p;
	}

	// TODO serve the request
	Person* fastLane() {
	    node* curr = head->next;
	    Person* p = NULL;
	    while(curr != tail){
	        if(curr->person->get_num() == 1){
	            p = curr->person;
	            remove(curr);
	            return p;
	       }
	       if(curr->person->get_num() == 0){;
	            remove(curr);
	       }
	        curr = curr->next;
	    }
	    return p;
	}

	// TODO print
	void print() {
		cout << "Counter: " << size << endl;
		node* curr = head->next;
		int idx = 1;
		cout << "From First: " << endl;
		while(curr != tail){
		    cout << idx << ". " << curr->person->firstName << " " << curr->person->lastName 
		    << " (" << curr->person->age << ") - req: ";
		    for(int i = 0; i < 4; i++){
		        if(curr->person->requests[i] && i == 0) cout << "B ";
		        else if(curr->person->requests[i] && i == 1) cout << "M ";
		        else if(curr->person->requests[i] && i == 2) cout << "C ";
		        else if(curr->person->requests[i] && i == 3) cout << "D ";
		    }
		    cout << endl;
		    idx++;
		    curr = curr->next;
		}
		idx--;
		curr = tail->prev;
		cout << "From Last: " << endl;
		while(curr != head){
		    cout << idx << ". " << curr->person->firstName << " " << curr->person->lastName 
		    << " (" << curr->person->age << ") - req: ";
		    for(int i = 0; i < 4; i++){
		        if(curr->person->requests[i] && i == 0) cout << "B ";
		        else if(curr->person->requests[i] && i == 1) cout << "M ";
		        else if(curr->person->requests[i] && i == 2) cout << "C ";
		        else if(curr->person->requests[i] && i == 3) cout << "D ";
		    }
		    cout << endl;
		    idx--;
		    curr = curr->prev;
		}
	}
};