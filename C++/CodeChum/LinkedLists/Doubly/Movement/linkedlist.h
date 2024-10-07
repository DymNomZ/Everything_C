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
	    while(!(curr->person->lastName == name || curr->person->firstName == name)){
	        curr = curr->next;
	    }
	    
	    while(forward != 0 && curr->prev != head){
	        swap(curr, curr->prev);
	        forward--;
	    }
	}


	// TODO delay
	void delay(string name, int back) {
	    node* curr = head->next;
	    while(!(curr->person->lastName == name || curr->person->firstName == name)){
	        curr = curr->next;
	    }
	    
	    node* toswap = curr;
	    
	    while(back != 0 && curr->next != tail){
	        toswap = toswap->next;
	        swap(curr, toswap);
	        back--;
	    }
	    
    
	}
	
	void swap(node* curr, node* source){
	    if(curr->next == source){
	        curr->next = source->next;
	        source->prev = curr->prev;
	        source->next = curr;
	        curr->prev = source;
	        
	        source->next->prev = source;
	        source->prev->next = source;
	        
	        curr->next->prev = curr;
	        curr->prev->next = curr;
	        return;
	    }else if(curr->prev == source){
	        source->next = curr->next;
	        curr->prev = source->prev;
	        curr->next = source;
	        source->prev = curr;
	    
	        source->next->prev = source;
	        source->prev->next = source;
	        
	        curr->next->prev = curr;
	        curr->prev->next = curr;
	        return;
	    }
	    
	    node* curr_n = curr->next;
	    node* curr_p = curr->prev;
	    node* source_n = source->next;
	    node* source_p = source->prev;
	    
	    curr_p->next = source;
	    curr_n->prev = source;
	    source->next = curr_n;
	    source->prev = curr_p;
	    
	    source_p->next = curr;
	    source_n->prev = curr;
	    curr->next = source_n;
	    curr->prev = source_p;
	    
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