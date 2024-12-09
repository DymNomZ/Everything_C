class Max_Heap{
    int* heap_e;
    int size, cap;

    void swap(int, int);
    void grow();
    void shrink();
    void heapify(int);
    int get_parent(int i);
    int get_left_child(int i);
    int get_right_child(int i);
    int get_element(int i);
    int get_parentIdx(int i);
    int get_leftChildIdx(int i);
    int get_rightChildIdx(int i);

    public:
        Max_Heap();
        int get_size();
        int get_cap();
        void print();
        void insert(int);
        int remove();
        int remove_x(int);
        int peek();
};