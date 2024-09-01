#include <iostream>
#include "min_heap.h"
#include "max_heap.h"

using namespace std;

void demo_min_heap();
void demo_max_heap();

int main(){
    int c;
    do{
        cout << "Choose demo: 1 for Min Heap  2: for Max Heap  65: to exit program" << endl;
        cin >> c;
        switch(c){
            case 1:
            demo_min_heap();
            break;

            case 2:
            demo_max_heap();
            break;

            default:
            cout << "Invalid input" << endl;
        }
    }while(c != 65);

}

void demo_max_heap(){

    Max_Heap* maxH = new Max_Heap();
    int e, x;
    do{
         cout << "Enter operation: 1 insert  2 remove  3 print  4 n elements  5 capacity  6 peek  7 remove n  65 exit demo" << endl;
        cin >> e;
        switch(e){
            case 1:
            cout << "Insert: ";
            cin >> x;
            maxH->insert(x);
            break;

            case 2:
            cout << "Removed: " << maxH->remove() << endl;
            break;

            case 3:
            maxH->print();
            break;

            case 4:
            cout << "Number of elements: " << maxH->get_size() << endl;
            break;

            case 5:
            cout << "Current capacity: " << maxH->get_cap() << endl;
            break;

            case 6:
            cout << "Peeking... min is: " << maxH->peek() << endl;
            break;

            case 7:
            cout << "Remove: ";
            cin >> x;
            cout << "Removed: " << maxH->remove_x(x) << endl;
            break;

            default:
            cout << "Invalid input" <<  endl;
        }
    }while(e != 65);

    cout << endl << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}

void demo_min_heap(){
    int size;
    cout << "Size: ";
    cin >> size;
    int* arr = (int*)calloc(size, 4);
    cout << "Array Elements: ";
    for (int i = 0; i < size; i++) cin >> *(arr + i);

    Min_Heap* minH = new Min_Heap(arr, size);
    int e, x;
    do{
        cout << "Enter operation: 1 insert  2 remove  3 print  4 n elements  5 capacity  6 peek  65 exit demo" << endl;
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