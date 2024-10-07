#include <iostream>
#include "dynamic_array.h"

using namespace std;

int main(){
    Dynamic_Array* d_arr = new Dynamic_Array(5);
    int e, x, i, res;
    //e = 65
    while(e != 65){
        cout << "Enter option: ";
        cin >> e;
        switch(e){
            case 0:
            res = d_arr->remove_all();
            cout << "Removed " << res << " items" << endl;
            break;

            case 1:
            cout << "Size is: " << d_arr->get_size() << endl;
            break;

            case 2:
            cout << "Enter idx: ";
            cin >> i;
            cout << "Element is: " << d_arr->get_element_at_index(i) << endl;
            break;

            case 3:
            cout << "Search for: ";
            cin >> x;
            cout << "Element found at " << d_arr->find_element(x) << endl;
            break;

            case 4:
            cout << "Remove: ";
            cin >> x;
            d_arr->remove(x);
            break;

            case 5:
            cout << "Remove at idx: ";
            cin >> i;
            d_arr->remove_at(i);
            break;

            case 6:
            cout << "Element and idx: ";
            cin >> e >> i;
            d_arr->insert(e, i);
            break;

            case 7:
            cout << "Append: ";
            cin >> x;
            d_arr->append_at_start(x);
            break;

            case 8:
            cout << "Append: ";
            cin >> x;
            d_arr->append_at_end(x);
            break;

            case 9:
            d_arr->remove_at_start();
            break;

            case 10:
            d_arr->remove_at_end();
            break;

            case 11:
            d_arr->print();
            break;

            case 12:
            cout << d_arr->get_num_elements() << " elements" << endl;
            break;

            default:
            cout << "Invalid value" << endl;
        }
    }
}