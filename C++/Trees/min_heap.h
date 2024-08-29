struct MinHeap{
    int heap_size;
    int heap_cap;
    int* heap_e;

    int get_parent(int);
    int get_left_child(int);
    int get_right_child(int);
    int get_element(int);

    int get_parentIdx(int);
    int get_leftChildIdx(int);
    int get_rightChildIdx(int);

    bool has_parent(int);
    bool has_left_child(int);
    bool has_right_child(int);

    void swap(int, int);

    void heapify_up(int);
    void heapify_down(int);

    public:
        MinHeap(int*, int);
        int get_size();
        int get_cap();
        void check_cap();
        void print_heap();
        void insert(int);
        int remove();
        
};