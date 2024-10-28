#include <algorithm>

using namespace std;

struct node {
    int elem;
    node* left;
    node* right;
    node* parent;

    int height(){
        if(!left && !right) return 0;
        if(!left) return 1 + right->height();
        else if(!right) return 1 + left->height();
        else return 1 + max(left->height(), right->height());
    }

    int depth(){
        if(!parent) return 0;
        else return 1 + parent->depth();
    }
};