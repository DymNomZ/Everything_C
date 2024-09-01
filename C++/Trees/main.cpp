#include <iostream>
#include "min_heap.h"

using namespace std;

int main(){
    int size;
    cout << "Size: ";
    cin >> size;
    int* arr = (int*)calloc(size, 4);
    cout << "Array Elements: ";
    for (int i = 0; i < size; i++) cin >> *(arr + i);

    Min_Heap* minH = new Min_Heap(arr, size);
    int e, x;
    do{
        cout << "Enter operation: ";
        cin >> e;
        switch(e){
            case 1:
            cout << "Insert: ";
            cin >> x;
            minH->insert(x);
            break;

            case 2:
            cout << "Removed: " << minH->remove() << endl;
            break;

            case 3:
            minH->print_heap();
            break;

            case 4:
            cout << "Number of elements: " << minH->get_size() << endl;
            break;

            case 5:
            cout << "Current capacity: " << minH->get_cap() << endl;
            break;

            case 6:
            cout << "Peeking... min is: " << minH->peek() << endl;
            break;

            default:
            cout << "Invalid input" <<  endl;
        }
    }while(e != 65);

    cout << endl << "Press Enter to continue...";
    cin.ignore();
    cin.get();

}