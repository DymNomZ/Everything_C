#include <iostream>
#include <algorithm>

using namespace std;

struct node {
    node **children;
	node *parent;
	int elem, child_count;

    int height() {
        if(child_count == 0) return 0;
        int highest = 1;
        for(int i = 0; i < child_count; i++){
            highest = max(1 + children[i]->height(), highest);
        }
        return highest;
    }

    int depth(){
        if(!parent) return 0;
        else return 1 + parent->depth();
    }

    void ancestors(){
        if(parent) {
            cout << parent->elem << " ";
            parent->ancestors();
        }
    }

    void descendants(){
        if(child_count != 0){
            for(int i = 0; i < child_count; i++){
                cout << children[i]->elem << " ";
            }
            for(int i = 0; i < child_count; i++){
                children[i]->descendants();
            }
        }
    }
};