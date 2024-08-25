#include <iostream>
#include "hash_map.h"

using namespace std;

int main()
{
    Hash_Map *hm = new Hash_Map();
    int key_int, val_int, i, e, x = -1;
    string key_str, val_str;

    do
    {
        cout << "Press 1 for int operations" << endl;
        cout << "Press 2 for str operations" << endl;
        cout << "Press 0 to end program" << endl;
        cin >> e;
        switch (e)
        {
        case 1:
            while (x != 0)
            {
                cout << "1:add 2:remove 3:remove_idx 4:replace 5:retrieve 6:retrieve_idx 0:end" << endl;
                cin >> x;
                switch (x)
                {
                case 1:
                    cout << "Key and val: ";
                    cin >> key_int >> val_int;
                    hm->add(key_int, val_int);
                    break;

                case 2:
                    cout << "Key: ";
                    cin >> key_int;
                    hm->remove(key_int);
                    break;

                case 3:
                    cout << "Idx: ";
                    cin >> i;
                    hm->remove_by_idx_int(i);
                    break;

                case 4:
                    cout << "Key and val: ";
                    cin >> key_int >> val_int;
                    hm->replace(key_int, val_int);
                    break;

                case 5:
                    cout << "Key: ";
                    cin >> key_int;
                    hm->retrieve_int(key_int);
                    break;

                case 6:
                    cout << "Idx: ";
                    cin >> i;
                    hm->remove_by_idx_int(i);
                    break;

                case 7:
                    hm->print(1);
                    break;

                default:
                    cout << "Invalid operation" << endl;
                }
            }
            break;

        case 2:
            while (x != 0)
            {
                cout << "1:add 2:remove 3:remove_idx 4:replace 5:retrieve 6:retrieve_idx 0:end" << endl;
                cin >> x;
                switch (x)
                {
                case 1:
                    cout << "Key and val: ";
                    cin >> key_str >> val_str;
                    hm->add(key_str, val_str);
                    break;

                case 2:
                    cout << "Key: ";
                    cin >> key_str;
                    hm->remove(key_str);
                    break;

                case 3:
                    cout << "Idx: ";
                    cin >> i;
                    hm->remove_by_idx_str(i);
                    break;

                case 4:
                    cout << "Key and val: ";
                    cin >> key_str >> val_str;
                    hm->replace(key_str, val_str);
                    break;

                case 5:
                    cout << "Key: ";
                    cin >> key_str;
                    hm->retrieve_str(key_str);
                    break;

                case 6:
                    cout << "Idx: ";
                    cin >> i;
                    hm->remove_by_idx_str(i);
                    break;

                case 7:
                    hm->print(2);
                    break;

                default:
                    cout << "Invalid operation" << endl;
                }
            }
            break;

        default:
            cout << "Invalid operation" << endl;
        }
    } while (e != 0);

    return 0;
}
