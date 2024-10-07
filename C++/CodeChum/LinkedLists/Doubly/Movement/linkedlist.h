#include "node.h"

class LinkedList {
	node* head;
	node* tail;
	int size;

	public:
	LinkedList() {
		head = new node;
		tail = new node;
		head->next = tail;
		tail->prev = head;
		size = 0;
	}

	// TODO add a person
	void add(Person* p) {
	    node* n = (node*)calloc(1, sizeof(node));
    	n->person = p;
	    if(size == 0){
    	    n->next = tail;
    	    tail->prev = n;
    	    n->prev = head;
    	    head->next = n;
	    }else{
	        node* n = (node*)calloc(1, sizeof(node));
    	    n->person = p;
    	    n->next = tail;
    	    n->prev = tail->prev;
    	    n->prev->next = n;
    	    tail->prev = n;
	    }
	    size++;
	}

	// TODO advance
	void advance(string name, int forward) {
	    node* curr = head->next;
	    int idx = 1;
	    while(!(curr->person->lastName == name || curr->person->firstName == name)){
	        curr = curr->next;
	        idx++;
	    }
	    //cout << idx << endl;
	    int num = idx - 1;
	    
	    if(forward >= num){
	        curr->prev->next = curr->next;
	        curr->next->prev = curr->prev;
	        curr->prev = head;
	        curr->next = head->next;
	        head->next->prev = curr;
	        head->next = curr;
	        return;
	    }else{
	        node* f = head->next;
    	    while(forward != 0 && f != tail){
    	        f = f->next;
    	        forward--;
    	    }
    	    
    	    node* c_next = curr->next;
    	    node* c_prev = curr->prev;
    	    
    	    c_prev->next = curr->next;
    	    c_next->prev = curr->prev;
    	    
    	    curr->next = f;
    	    curr->prev = f->prev;
    	    curr->prev->next = curr;
    	    f->prev = curr;
    	    
    	    return;
    	    
	    }
	    
    
	}


	// TODO delay
	void delay(string name, int back) {
	    node* curr = head->next;
	    int idx = 1;
	    while(!(curr->person->lastName == name || curr->person->firstName == name)){
	        curr = curr->next;
	        idx++;
	    }
	    int num = size - idx;
	    if(back > num){
	        curr->prev->next = curr->next;
	        curr->next->prev = curr->prev;
	        curr->next = tail;
	        curr->prev = tail->prev;
	        tail->prev->next = curr;
	        tail->prev = curr;
	        return;
	    }
	    else if(idx != size){
	        node* b = curr;
    	    while(back != 0 && b != tail){
    	        b = b->next;
    	        back--;
    	    }
    	    
    	    curr->next = b->next;
    	    b->prev = curr->prev;
    	    b->next = curr;
    	    curr->prev = b;
    	    b->prev->next = b;
    	    curr->next->prev = curr;
    	    return;
	    }
	    
    
	}
	
	void swap(node* ns, node* nu){
	    node* ns_next = ns->next;
	    node* ns_prev = ns->prev;
	    node* nu_next = nu->next;
	    node* nu_prev = nu->prev;
	    
	    //swapping
	    nu->prev = ns_prev;
	    nu->next = ns_next;
	    ns_next->prev = nu;
	    ns_prev->next = nu;
	    
	    ns->prev = nu_prev;
	    ns->next = nu_next;
	    nu_next->prev = ns;
	    nu_prev->next = ns;
	}


	// TODO trade places
	void trade(string name1, string name2) {
	    node* curr = head->next;
	    while(!(curr->person->lastName == name1 || curr->person->firstName == name1)){
	        curr = curr->next;
	    }
	    
	    node* suss = head->next;
	    while(!(suss->person->lastName == name2 || suss->person->firstName == name2)){
	        suss = suss->next;
	    }
	    
	    swap(suss, curr);
	    
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
		        if(curr->person->requests[i] == 1 && i == 0) cout << "B ";
		        else if(curr->person->requests[i] == 1 && i == 1) cout << "M ";
		        else if(curr->person->requests[i] == 1 && i == 2) cout << "C ";
		        else if(curr->person->requests[i] == 1 && i == 3) cout << "D ";
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
		        if(curr->person->requests[i] == 1 && i == 0) cout << "B ";
		        else if(curr->person->requests[i] == 1 && i == 1) cout << "M ";
		        else if(curr->person->requests[i] == 1 && i == 2) cout << "C ";
		        else if(curr->person->requests[i] == 1 && i == 3) cout << "D ";
		    }
		    cout << endl;
		    idx--;
		    curr = curr->prev;
		}   

	}
};