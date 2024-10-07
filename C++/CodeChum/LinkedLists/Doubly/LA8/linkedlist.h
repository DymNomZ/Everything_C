#include "list.h"
#include "node.h"
#include <iostream>
using namespace std;

class LinkedList : public List {
	node *head, *tail;
	int size;

public:
	void addFirst(int num) {
		// STEP 1: Create node n
		node* n = (node*) calloc( 1, sizeof(node) );
		n->elem = num;
		// STEP 2: Connect n to head
		n->next = head;
		if (head) {
			head->prev = n;
		}
		// STEP 3: Reassign head
		head = n;
		if (!tail) {
			tail = n;
		}
		// STEP 4: Update size
		size++;
	}
	void addLast(int num) {
		// STEP 1: Create node n
		node* n = new node;
		n->elem = num;
		n->next = NULL;
		// STEP 2: Connect tail to n
		if (tail) {
			tail->next = n;
		} else {
			head = n;
		}
		n->prev = tail;
		// STEP 3: Reassign tail
		tail = n;
		// STEP 4: Update size
		size++;
	}

	void removeFirst() {
		if (!head) {
			return;
		}
		head = head->next;
		if (head) {
			free(head->prev);
			head->prev = nullptr;
		} else {
			free(tail);
			tail = nullptr;
		}
		size--;
	}

	void removeLast() {
		if (!tail) {
			return;
		}
		tail = tail->prev;
		if (tail) {
			free(tail->next);
			tail->next = nullptr;
		} else {
			free(head);
			head = nullptr;
		}
		size--;
	}

	void add(int num) {
		addLast(num);
	}

    void addAt(int num, int pos){
        if(pos == 1){
            addFirst(num);
            return;
        }else if(pos > size){
            addLast(num);
            return;
        }
        
        int idx = 1;
        node* curr = head;
        while(idx != pos){
            curr = curr->next;
            idx++;
        }
        curr = curr->prev;
        node* n = (node*) calloc( 1, sizeof(node) );
        n->elem = num;
        n->next = curr->next;
        curr->next->prev = n;
        n->prev = curr;
        curr->next = n;
        size++;
        
    
    }

    int remove(int num) {
	    if(size == 0) return -1;
	    bool found = false;
	    if(num == head->elem){
	        removeFirst();
	        return 1;
	    }else if(num == tail->elem){
	        removeLast();
	        return size+1;
	    }
	    
	    int idx = 1;
	    node* curr = head;
	    while(curr){
	        if(curr->elem == num){
	            found = true;
	            break;
	        }
	        curr = curr->next;
	        idx++;
	    }
	    if(!found){
	        return -1;
	    }else{
	        curr->prev->next = curr->next;
    	    curr->next->prev = curr->prev;
    	    free(curr);
    	    
    	    return idx;
	    }
    
	}

    int removeAt(int pos){
        int ret;
        if(pos == 1){
            ret = head->elem;
            removeFirst();
            return ret;
        }else if(pos == size){
            ret = tail->elem;
            removeLast();
            return ret;
        }
        int idx = 1;
        node* curr = head;
        while(idx != pos){
            curr = curr->next;
            idx++;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        ret = curr->elem;
        free(curr);
        size--;
        return ret;
        
    }

    // TODO implement method int retain(int num) here
    int retain(int num){
        int count = 0;
        node* curr = head;
        while(curr){
            if(curr->elem < num){
                if(head == tail){
                    head = NULL;
                    tail == NULL;
                }else if(curr == head){
                    head = head->next;
                    head->prev = NULL;
                }else if(curr == tail){
                    tail = tail->prev;
                    tail->next = NULL;
                }else{
                    node* next = curr->next;
                    node* prev = curr->prev;
                    next->prev = prev;
                    prev->next = next;
                }
                size--;
                count++;
            }
            curr = curr->next;
        }
        return count;
    }


	int corner(int left, int right){
        int r = (size + 1) - right;
        int count = 0, idx = 1;
        node* curr = head;
        node* connect = head;
        while(curr){
            if(idx == left){
                connect = curr;
            }
            if(idx > left && idx < r){
                count++;
                size--;
            }
            if(idx == r){
                if(left == 0){
                    head = curr;
                }
                else{
                    connect->next = curr;
                    curr->prev = connect;
                }
                
                break;
            }
            curr = curr->next;
            idx++;
        }
        return count;
    }


	int get(int pos) {
	
	    if(pos > size || pos == 0){ return -1;}
	
	    int ret, head_c = 0, tail_c = 0, idx = 1;
	    node* curr = head;
	    //traverse head first
    	while (curr) {
    		if(idx == pos){
    		    ret = curr->elem;
    		    break;
    		}
    		curr = curr->next;
    		idx++;
		}
		head_c = idx;
		idx = 1;
		curr = tail;
		//traverse from tail
		while (curr) {
    		if(curr->elem == ret){
    		    break;
    		}
    		curr = curr->prev;
    		idx++;
		}
		tail_c = idx;
		
		//compare
		if(head_c <= tail_c){
		    cout << "From head, number of comparisons: " << head_c << endl;
		}else{
		    cout << "From tail, number of comparisons: " << tail_c << endl;
		}
        return ret;
	}

	int _size() {
        return size;
	}

    void print() {
    	node* curr;
    	if (size == 0) {
    		cout << "Empty" << endl;
		} else {
			cout << "From HEAD: ";
    		curr = head;
	    	while (true) {
	    		cout << curr->elem;
	    		if (curr != tail) {
	    			cout << " -> ";
				} else {
					cout << endl;
                    break;
				}
	    		curr = curr->next;
			}
			cout << "From TAIL: ";
    		curr = tail;
	    	while (true) {
	    		cout << curr->elem;
	    		if (curr != head) {
	    			cout << " <- ";
				} else {
					cout << endl;
                    break;
				}
	    		curr = curr->prev;
			}
		}
    }
};