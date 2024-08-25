#include <string>

using namespace std;


class Hash_Map{

    int* arr_int;
    string* arr_str;
    int count = 0;
    float f_size = 13;
    int curr_size = 13;

    int* resize_int_arr(int*, int*);
    string* resize_str_arr(string*, int*);
    int hash_func(int);
    int hash_func(string);
    void arr_checker(int, int);
    void arr_checker(int, string);

    public:
        Hash_Map();
        void add(int, int);
        void add(string, string);

        void remove(int);
        void remove(string);
        void remove_by_idx_int(int);
        void remove_by_idx_str(int);
        //strictly key is to be passed
        void replace(int, int);
        void replace(string, string);

        int retrieve_int(int);
        string retrieve_str(string);
        int retrieve_by_idx_int(int);
        string retrieve_by_idx_str(int);
        
        void print(int);
};