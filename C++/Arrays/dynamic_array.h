

class Dynamic_Array{

    int* arr;
    int init_size;
    int curr_size;
    int count_size;
    int* resize(int*, int*);

    public:
        Dynamic_Array(int);
        int get_size();
        int get_element_at_index(int);
        int find_element(int);
        void remove(int);
        void remove_at(int);
        void insert(int, int);
        void append_at_start(int);
        void append_at_end(int);
        void remove_at_start();
        void remove_at_end();
        void print();
        int get_num_elements();


};