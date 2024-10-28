class Max_Heap{
    int* heap_e;
    int size, cap;

    void swap(int, int);
    void grow();
    void shrink();
    void heapify(int);

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