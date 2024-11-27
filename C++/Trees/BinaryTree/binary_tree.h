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

    bool checkIfPath(vector<node*> candidates){
        for(int i = 0; i < candidates.size() - 1; i++){
            if(!checkIfEdge(candidates[i], candidates[i+1])) return false;
        }
        return true;
    }

    void collectPaths(node *node, vector<int> &candidate_path, vector<vector<int>> &paths) {
    if (node == NULL) return;

    //By default push to candidate_path vector
    candidate_path.push_back(node->elem);

    // If it's a leaf node, store the path
    if (node->left == NULL && node->right == NULL) {
        paths.push_back(candidate_path);
    }
    else {
        // if not, try both subtrees
        collectPaths(node->left, candidate_path, paths);
        collectPaths(node->right, candidate_path, paths);
    }

    //remove last element
    candidate_path.pop_back();
}

    vector<vector<int>> allPaths(node *root) {
        //Note that this is only root-to-leaf
        vector<vector<int>> paths;
        vector<int> candidate_path;

        collectPaths(root, candidate_path, paths);
        
        return paths;
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