#include <iostream>
#include "node.h"

using namespace std;

class GeneralTree {

    node* root;
    int size;

    public:
    GeneralTree(){
        root = NULL;
        size = 0;
    }

    int _size(){
        return size;
    }

    node* createNode(int num, node* parent){
        node* n = new node();
        n->elem = num;
        n->parent = parent;
        return n;
    }

    node* addRoot(int num){
        if(root) return NULL;
        root = new node();
        root->elem = num;
        size++;
        return root;
    }

    node* addChild(node* p, int e) {
		if(!p->children){
		    p->children = (node**)calloc(10, sizeof(node*));
		    p->child_count = 0;
		}
	    node* n = new node();
	    n->elem = e;
	    n->parent = p;
	    p->child_count++;
	    p->children = (node**)realloc(p->children, sizeof(node*) * p->child_count);
	    p->children[p->child_count - 1] = n;
	    size++;
	    return n;
	}

    void siblings(node* nod){
        if(nod == root){
            cout << "Node has no siblings cause it is the root!" << endl;
        }
        if(nod->parent->child_count == 1){
            cout << "Node " << nod->elem << " has no sibling." << endl;
        }
        else{
            for(int i = 0; i < nod->parent->child_count; i++){
                if(nod->parent->children[i] != nod){
                    cout << nod->parent->children[i]->elem << " ";
                }
            }
            cout << endl;
        }
    }

    node* parent(node* nod){
        if(nod == root){
            return NULL;
        }
        return nod->parent;
    }

    bool checkIfAncestor(node* u, node* v){
        
        //reached above root
        if(!v) return false;

        //u == v
        if(u == v) return true;
        else return checkIfAncestor(u, v->parent);
    }

    bool checkIfDesecendant(node* v, node* u){
        return checkIfAncestor(u, v);
    }

    bool checkIfEdge(node* u, node* v){
        return u == v->parent;
    }

    int remove(node* n) {
	    //check if it has children
		if(n->child_count != 0) return -1;
		
		//no children
		//check if it has a parent
		else if(n->parent){
		    for(int i = 0; i < n->parent->child_count; i++){
		        if(n->parent->children[i] == n){
		            for(int j = i + 1; j < n->parent->child_count; j++){
		                n->parent->children[j-1] = n->parent->children[j];
		            } 
		            break;
		        }
		    }
		    n->parent->child_count--;
		}
		
		//no children and no parent means this is root
		else{
		    root = NULL;
		}
        int ret = n->elem;
		delete n;
		size--;

        return ret;
	}

};