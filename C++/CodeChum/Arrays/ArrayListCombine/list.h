class List {
    public:
    virtual void add(int) = 0;
    virtual int get(int pos) = 0;
    virtual int remove(int num) = 0;
    virtual void print() = 0;
    virtual bool isEmpty() = 0;
    virtual int removeAt(int) = 0;
    virtual void combine(List*) = 0;
};