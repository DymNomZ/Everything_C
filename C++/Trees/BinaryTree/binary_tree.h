#include <iostream>
#include "node.h"

using namespace std;

class BinaryTree {

    node* root;
    int size;

    public:
    BinaryTree(){
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
        if(root){
            throw logic_error("Already has root " + to_string(root->elem));
        }
        root = new node();
        root->elem = num;
        size++;
        return root;
    }

    node* addLeft(node* nod, int num){
        if(nod->left){
            throw logic_error("Already has left " + to_string(nod->left->elem));
        }
        nod->left = createNode(num, nod);
        size++;
        return nod->left;
    }

    node* addRight(node* nod, int num){
        if(nod->right){
            throw logic_error("Already has right " + to_string(nod->right->elem));
        }
        nod->right = createNode(num, nod);
        size++;
        return nod->right;
    }

    node* left(node* nod){
        if(!nod->left){
            return NULL;
        }
        return nod->left;
    }

    node* right(node* nod){
        if(!nod->right){
            return NULL;
        }
        return nod->right;
    }

    node* sibling(node* nod){
        if(nod == root){
            return NULL;
        }
        else if(left(nod->parent) == nod){
            return right(nod->parent);
        }
        else{
            return left(nod->parent);
        }
    }

    node* parent(node* nod){
        if(nod == root){
            return NULL;
        }
        return nod->parent;
    }

    int remove(node* nod){
        if(left(nod) && right(nod)) throw logic_error("Cannot remove nod for it has 2 children");
        //has either one child
        else if(left(nod) || right(nod)){
            //check if it has a parent, if so, assign the appropriate child to grand parent
            if(parent(nod)){
                if(left(nod)){
                    nod->left->parent = nod->parent;
                    if(left(parent(nod)) == nod){
                        nod->parent->left = nod->left;
                    }else{
                        nod->parent->right = nod->left;
                    }
                }else{
                    nod->right->parent = nod->parent;
                    if(left(parent(nod)) == nod){
                        nod->parent->left = nod->right;
                    }else{
                        nod->parent->right = nod->right;
                    }
                }
            }
            //no parent means the node is a root, therefore assign new root
            else{
                if(left(nod)) root = nod->left;
                else root = nod->right;
                root->parent = NULL;
            }
        }
        else{
            //a leaf!
            //check which child is it if it has a parent
            if(parent(nod)){
                if(left(parent(nod)) == nod){
                    nod->parent->left = NULL;
                }else if(right(parent(nod)) == nod){
                    nod->parent->right = NULL;
                }
            }
            //no parent and no children means this is a root
            else{
                root = NULL;
            }
        }
        int store = nod->elem;
        delete nod;
        size--;
        return store;
    }

};