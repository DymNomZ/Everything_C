#include "binary_tree.h"

class BST {
	BinaryTree* tree = new BinaryTree();
    int* arr;
    int curr = 0;

	public:
    //convert functions are one time use only as per their design, so after using, restart the program to perform further operations
    void toMinHeap() {
	    int size = tree->_size();
	    arr = (int*)calloc(size, 4);
	    
	    inorder(tree->getRoot());
	    curr = 0;
	    preorder(tree->getRoot());
	}

    void toMaxHeap() {
	    int size = tree->_size();
	    arr = (int*)calloc(size, 4);
	    
	    inorder(tree->getRoot());
	    curr = 0;
	    postorder(tree->getRoot());
	}
	
	void inorder(node* n){
	    if(tree->left(n)) inorder(tree->left(n));
	    arr[curr] = n->elem;
	    curr++;
	    if(tree->right(n)) inorder(tree->right(n));
	}

	void preorder(node* n){
	    n->elem = arr[curr];
	    curr++;
	    if(tree->left(n)) preorder(tree->left(n));
	    if(tree->right(n)) preorder(tree->right(n));
	}

    void postorder(node* n){
	    if(tree->left(n)) postorder(tree->left(n));
	    if(tree->right(n)) postorder(tree->right(n));
        n->elem = arr[curr];
	    curr++;
	}
	
	void swap(int a, int b){
	    arr[a] = arr[a] ^ arr[b];
	    arr[b] = arr[a] ^ arr[b];
	    arr[a] = arr[a] ^ arr[b];
	}

	bool search(int num) {
	    node* n = tree->getRoot();
        
        return searching(num, n);
	}
	
	bool searching(int num, node* n){
	    
	    if(!n) return false;
	    if(n->elem == num) return true;
	    else{
            if(num < n->elem){
                //search left first
                return searching(num, n->left);
            }
            //if not found, then right
            else return searching(num, n->right);
        }
	}

	bool insert(int num) {
	    node* n = tree->getRoot();
        if(!n){
            tree->addRoot(num);
            return true;
        }
        //make sure the number to be added does not exist yet
        if(!searching(num, n)){
            return ins(num, n);
        }else{
            return false;
        }
	}
	
	bool ins(int num, node* n){
	    
        //if less than, insert left
	    if(num < n->elem){
            //reach leaf, so add
	        if(!n->left){
	            tree->addLeft(n, num);
	            return true;
	        }
            //look for the leaf if not
            else{
	            return ins(num, n->left);
	        }
	    }
        //else insert right
        else{
            //same idea
	        if(!n->right){
	            tree->addRight(n, num);
	            return true;
	        }else{
	            return ins(num, n->right);
	        }
	    }
	    
	}
	
	node* createNode(int num, node* parent){
	    node* c = new node;
        c->elem = num;
        c->left = NULL;
        c->right = NULL;
        c->parent = parent;
        
        return c;
	}

    bool remove(int num) {
        return removeBySearch(num, tree->getRoot());
    }
    
    bool removeBySearch(int num, node* n){
	    
	    if(!n) return false;
	    if(n->elem == num){
	        if(n->left && n->right){
	            node* check = n->right;
	            while(check->left){
	                check = check->left;
	            }
	            n->elem = check->elem;
	            tree->remove(check);
	        }else{
	            tree->remove(n);
	        }
	        return true;
	    }
	    if(num > n->elem){
	        return removeBySearch(num, n->right);
	    }
	    else{
            return removeBySearch(num, n->left);
        }
	}

    node* searchAndGet(int num, node* n){
	    
	    if(n->elem == num) return n;
	    else{
            if(num < n->elem){
                //search left first
                return searchAndGet(num, n->left);
            }
            //if not found, then right
            else return searchAndGet(num, n->right);
        }
	}

    int getNum(node* n, int type){

        if(type == 1){
            //if leaf then return, its the next largest
            if(!n->left) return n->elem;
            else return getNum(n->left, type);
        }
        else{
            //if leaf then return, its the next smallest
            if(!n->right) return n->elem;
            else return getNum(n->left, type);
        }
	}

    int childCheck(node* c, int type){
        //if parent is null then we reached the root, therefore no predecessor
        if(!c->parent) return -1;

        if(type == 1){
            //found!
            if(c->parent->right == c) return c->parent->elem;
            //move up
            else return childCheck(c->parent, type);
        }
        else{
            if(c->parent->left == c) return c->parent->elem;
            else return childCheck(c->parent, type);
        }
    }

    int predecessor(int num){
        //check if num is in the tree for less hassle if not
        if(search(num)){
            node* n = searchAndGet(num, tree->getRoot());

            //checks
            //if node has left child, predecessor is the right most child of its left child
            if(n->left){
                return getNum(n->left, 2);
            }
            //if node has no left child, predecessor is the parent where the node is the right child of the parent
            else{
                return childCheck(n, 1);
            }
        }
        else return -1;
    }

    int successor(int num){
        //just the same idea with predecessor but right then left instead of left then right
        if(search(num)){
            node* n = searchAndGet(num, tree->getRoot());

            //checks
            if(n->right){
                return getNum(n->right, 1);
            }
            else{
                return childCheck(n, 2);
            }
        }
        else return -1;
    }

    //fun functions!!!
    void whatValidOrder(){
        int n;
        cout << "Enter number of elements: ";
        cin >> n;
        int arr[n];

        cout << "Enter order to check: ";
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        verifyPre(arr, n);
        cout << endl;
        verifyPost(arr, n);
        cout << endl;
        verifyIn(arr, n);
        cout << endl;
    }

    void verifyPre(int arr[], int n){

        //creds zillion
        for(int i = 0; i < n; i++){
            bool check = false;
            for(int j = i + 1; j < n; j++){
                if(check){
                    if(arr[j] < arr[i]){
                        cout << "INVALID PRE-ORDER!";
                        return;
                    }
                    
                }else{
                    if(arr[j] > arr[i]){
                        check = true;
                    }
                    
                }
            }
        }

        cout << "VALID PRE-ORDER!";
    }

    void verifyPost(int arr[], int n){

        //same idea to zillion's algo only this time its flipped, start from the right
        for(int i = n-1; i >= 0; i--){
            bool check = false;
            for(int j = i - 1; j >= 0; j--){
                if(check){
                    if(arr[j] > arr[i]){
                        cout << "INVALID POST-ORDER";
                        return;
                    }
                    
                }else{
                    if(arr[j] < arr[i]){
                        check = true;
                    }
                    
                }
            }
        }

        cout << "VALID POST-ORDER";
    }

    void verifyIn(int arr[], int n){

        //just simple check if not sorted LOL
        for(int i = 0; i < n-1; i++){
            if(arr[i] > arr[i+1]){
                cout << "INVALID IN-ORDER";
                return;
            }
        }

        cout << "VALID IN-ORDER";
    }

	void print() {
		tree->print();
	}
};