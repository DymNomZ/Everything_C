#include <iostream>
#include <vector>
#include "binary_tree.h"

using namespace std;

void printVector(vector<node*> nodes){
    for(node* n : nodes){
        cout << n->elem << " ";
    }
    cout << endl;
    for(int i = 0; i < nodes.size(); i++){
        cout << "[" << i << "] ";
    }
    cout << endl;
}

void selectNode(int* select, vector<node*> nodes){
    cout << "Select node: " << endl;
    printVector(nodes);
    cout << "Node number: ";
    cin >> *select;
}

int main(){

    BinaryTree* t = new BinaryTree();
    int input, select;
    char op;
    vector<node*> nodes, candidates;

    while(op != 'x'){
        cout << "Enter operation: ";
        cin >> op;

        switch(op){

            case '@':
                try {
                    cout << "Input root num: ";
                    cin >> input;
                    node* res = t->addRoot(input);
                    cout << "Root added: " << res->elem << endl;
                    nodes.push_back(res);
                } catch (exception const& e) {
                    cout << e.what() << endl;
                }
                
            break;

            case 'L':
                try {

                    if(nodes.size() == 0){
                        cout << "No root!" << endl;
                    }else{
                        node* res;
                        cout << "Input number: ";
                        cin >> input;  

                        selectNode(&select, nodes);
                        if(select >= nodes.size()){
                            cout << "Invalid choice" << endl;
                        }else{
                            res = t->addLeft(nodes.at(select), input);
                            cout << "Left added: " << res->elem << endl;
                            cout << "Parent: " << res->parent->elem << endl;
                            nodes.push_back(res);
                        }
                    }
                    
                } catch (exception const& e) {
                    cout << e.what() << endl;
                }
            break;

            case 'R':
                try {

                    if(nodes.size() == 0){
                        cout << "No root!" << endl;
                    }else{
                        node* res;
                        cout << "Input number: ";
                        cin >> input;  

                        selectNode(&select, nodes);
                        if(select >= nodes.size()){
                            cout << "Invalid choice" << endl;
                        }else{
                            res = t->addRight(nodes.at(select), input);
                            cout << "Right added: " << res->elem << endl;
                            cout << "Parent: " << res->parent->elem << endl;
                            nodes.push_back(res);
                        }
                    }

                } catch (exception const& e) {
                    cout << e.what() << endl;
                }
            break;

            case 'l':

                if(nodes.size() == 0){
                    cout << "No root!" << endl;
                }else{
                    node* res;

                    selectNode(&select, nodes);
                    if(select >= nodes.size()){
                        cout << "Invalid choice" << endl;
                    }
                    else{
                        res = t->left(nodes.at(select));
                        if(res){
                            cout << "Left of " << nodes.at(select)->elem << " is: " << res->elem << endl;
                            cout << "Parent: " << res->parent->elem << endl;
                        }else{
                            cout << "Has no left!" << endl;
                        }
                    }
                }

            break;

             case 'r':

                if(nodes.size() == 0){
                    cout << "No root!" << endl;
                }else{
                    node* res;

                    selectNode(&select, nodes);
                    if(select >= nodes.size()){
                        cout << "Invalid choice" << endl;
                    }
                    else{
                        res = t->right(nodes.at(select));
                        if(res){
                            cout << "Right of " << nodes.at(select)->elem << " is: " << res->elem << endl;
                            cout << "Parent: " << res->parent->elem << endl;
                        }else{
                            cout << "Has no right!" << endl;
                        }
                    }
                }
                
            break;

            case 'S':
                cout << "Tree Size: " << t->_size() << endl;
            break;

            case 's':
                if(nodes.size() == 0){
                    cout << "No root!" << endl;
                }else{
                    node* res;

                    selectNode(&select, nodes);
                    if(select >= nodes.size()){
                        cout << "Invalid choice" << endl;
                    }else{
                        res = t->sibling(nodes.at(select));
                        if(res){
                            cout << "Sibling of " << nodes.at(select)->elem << " is: " << res->elem << endl;
                            cout << "Parent: " << res->parent->elem << endl;
                        }else{
                            cout << "Has no sibling!" << endl;
                        }
                    }
                }
            break;

            case 'h':
                if(nodes.size() == 0){
                    cout << "No root!"<< endl;
                }else{
                    selectNode(&select, nodes);
                    if(select >= nodes.size()){
                        cout << "Invalid choice" << endl;
                    }else{
                        node* selected = nodes.at(select);
                        cout << "Height of " << selected->elem << " is: " << selected->height() << endl;
                    }
                }
            break;

            case 'd':
                if(nodes.size() == 0){
                    cout << "No root!" << endl;
                }else{
                    selectNode(&select, nodes);
                    if(select >= nodes.size()){
                        cout << "Invalid choice" << endl;
                    }else{
                        node* selected = nodes.at(select);
                        cout << "Depth of " << selected->elem << " is: " << selected->depth() << endl;
                    }
                }
            break;

            case 'p':
                if(nodes.size() == 0){
                    cout << "No root!" << endl;
                }else{
                    selectNode(&select, nodes);
                    if(select >= nodes.size()){
                        cout << "Invalid choice" << endl;
                    }else{
                        node* selected = nodes.at(select);
                        node* res = t->parent(selected);
                        if(res){
                            cout << "Parent of " << selected->elem << " is: " << t->parent(selected)->elem << endl;
                        }else cout << "Nod is root, no parent!" << endl;
                    }
                }
            break;

            case 'P':
                if(nodes.size() < 2){
                    cout << "No path can be made, nned at least two elements!" << endl;
                }else{
                    //clear previous list, smh
                    candidates.clear();
                    
                    cout << "Construct potential path, enter invalid index to end selection and validate your path" << endl;
                    do{
                        selectNode(&select, nodes);
                        if(select >= nodes.size() || select < 0) break;
                        else candidates.push_back(nodes.at(select));

                    }while(select < nodes.size() && select >= 0);

                    cout << "Now validating..." << endl;

                    if(t->checkIfPath(candidates)) cout << "It is a valid path!";
                    else cout << "It is not a valid path";
                    cout << endl;
                }

            break;

            case 'e':
                if(nodes.size() < 2){
                    cout << "No edging, must have at least two elements!" << endl;
                }else{
                    cout << "Select edgers" << endl;
                    selectNode(&select, nodes);
                    if(select >= nodes.size()){
                        cout << "Invalid choice" << endl;
                    }else{
                        node* u = nodes.at(select);

                        selectNode(&select, nodes);
                        if(select >= nodes.size()){
                            cout << "Invalid choice" << endl;
                        }else{

                            node* v = nodes.at(select);

                            if(!t->checkIfEdge(u, v)) cout << u->elem << " and " << v->elem << " are not edging";
                            else cout << u->elem << " and " << v->elem << " are edging!";
                            cout << endl;
                        }
                    
                    }
                }
            break;

            case '!':
                if(nodes.size() == 0){
                    cout << "Nothing to remove, tree is empty!" << endl;
                }else{
                    selectNode(&select, nodes);
                    if(select >= nodes.size()){
                        cout << "Invalid choice" << endl;
                    }else{
                        try{
                            int res = t->remove(nodes.at(select));
                            cout << "Removed: " << res << endl;
                            nodes.erase(nodes.begin() + select);
                        } catch (exception const& e){
                            cout << e.what() << endl;
                        }
                    }
                }
            break;

            case 'J':
            if(nodes.size() == 0){
                cout << "Can't print, tree is empty!" << endl;
            }else{
                cout << "Prints ancestors of a node" << endl;
                selectNode(&select, nodes);
                if(select >= nodes.size()){
                    cout << "Invalid choice" << endl;
                }else{
                    nodes.at(select)->ancestors();
                    cout << endl;
                }
            }
            break;

            case 'K':
            if(nodes.size() == 0){
                cout << "Can't print, tree is empty!" << endl;
            }else{
                cout << "Prints descendants of a node" << endl;
                selectNode(&select, nodes);
                if(select >= nodes.size()){
                    cout << "Invalid choice" << endl;
                }else{
                    nodes.at(select)->descendants();
                    cout << endl;
                }
            }
            break;

            case 'D':
            if(nodes.size() == 0){
                cout << "Can't check, tree is empty!" << endl;
            }else{
                cout << "Select potential descendant" << endl;
                selectNode(&select, nodes);
                if(select >= nodes.size()){
                    cout << "Invalid choice" << endl;
                }else{
                    node* v = nodes.at(select);

                    cout << "Select ancestor" << endl;
                    selectNode(&select, nodes);

                    if(select >= nodes.size()){
                        cout << "Invalid choice" << endl;
                    }else{

                        node* u = nodes.at(select);

                        if(t->checkIfDesecendant(v, u)) cout << v->elem << " is a descendant of " << u->elem;
                        else cout << v->elem << " is not a descendant of " << u->elem;
                        cout << endl;
                    }
                    
                }
            }
            break;

            case 'A':
            if(nodes.size() == 0){
                cout << "Can't check, tree is empty!" << endl;
            }else{
                cout << "Select potential ancestor" << endl;
                selectNode(&select, nodes);
                if(select >= nodes.size()){
                    cout << "Invalid choice" << endl;
                }else{
                    node* u = nodes.at(select);

                    cout << "Select base node" << endl;
                    selectNode(&select, nodes);

                    if(select >= nodes.size()){
                        cout << "Invalid choice" << endl;
                    }else{

                        node* v = nodes.at(select);

                        if(t->checkIfAncestor(u, v)) cout << u->elem << " is an ancestor of " << v->elem;
                        else cout << u->elem << " is not an ancestor of " << v->elem;
                        cout << endl;
                    }
                    
                }
            }
            break;

            case 'c':
            if(nodes.size() == 0){
                cout << "Can't check, tree is empty!" << endl;
            }else{
                node* n = nodes.at(0);
                cout << "Collecting root-to-leaf paths..." << endl;

                vector<vector<int>> paths = t->allPaths(n);

                cout << "Paths collected! Printing..." << endl;
                
                for(int i = 0; i < paths.size(); i++){
                    vector<int> path = paths.at(i);
                    for(int j = 0; j < path.size(); j++){
                        cout << path.at(j) << " ";
                    }
                    cout << endl;
                }
            }
            break;
        }
    }

    return 0;
}