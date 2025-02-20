#include <iostream>
#include "chain_hash_map.hpp"
#include "linear_hash_map.hpp"

using namespace std;

void chainDemo(){

    char op;

    int cap;
    string value;

    cout << "Input map size: " << endl;
    cin >> cap;

    ChainHashMap* map = new ChainHashMap(cap);

    while(op != 'x'){
        cout << "1. insert, 2. remove, 3. search, 4. print" << endl;
        cout << "Choice: ";
        cin >> op;

        switch(op){
            case '1':
                cin >> value;
                cout << "Inserted at " << map->insert(value) << endl;
            break;

            case '2':
                cin >> value;
                cout << "Removed at " << map->remove(value) << endl;
            break;

            case '3':
                cin >> value;
                if(map->search(value)) cout << "found!" << endl;
                else cout << "not found..." << endl;
            break;

            case '4':
                map->print();
            break;
        }
    }
}

void linearDemo(){

    char op;

    int cap;
    int value;

    cout << "Input map size: " << endl;
    cin >> cap;

    LinearHashMap* map = new LinearHashMap(cap);

    while(op != 'x'){
        cout << "1. insert, 2. remove, 3. search, 4. print" << endl;
        cout << "Choice: ";
        cin >> op;

        switch(op){
            case '1':
                cin >> value;
                cout << "Inserted at " << map->insert(value) << endl;
            break;

            case '2':
                cin >> value;
                cout << "Removed at " << map->remove(value) << endl;
            break;

            case '3':
                cin >> value;
                if(map->search(value)) cout << "found!" << endl;
                else cout << "not found..." << endl;
            break;

            case '4':
                map->print();
            break;
        }
    }
}

int main(){

    char op;
    while(op != 'x'){
        cout << "choose: 1 for chain 2 for linear" << endl;
        cout << "Choice: ";
        cin >> op;
        
        switch(op){
            case '1':
                chainDemo();
            break;
            case '2':
                linearDemo();
            break;
            default:
                cout << "Wrong choice lmao" << endl;
        }
    }

}