#include <iostream>
#include "node.h"

using namespace std;

class doublylist {
    node* head;
    node* tail;
    int size = 0;
    bool is_sorting = false;

    public:
    doublylist(){
        head = (node*)calloc(1, sizeof(node));
        tail = (node*)calloc(1, sizeof(node));
        head->next = tail;
        tail->prev = head;
    }

    int get_size(){
        return size;
    }

    void add_head(int num){
        node* n = (node*)calloc(1, sizeof(node));
        n->val = num;
        n->next = head->next;
        n->prev = head;
        head->next = n;
        n->next->prev = n;
        size++;
    }

    void add_tail(int num){
        node* n = (node*)calloc(1, sizeof(node));
        n->val = num;
        n->next = tail;
        n->prev = tail->prev;
        tail->prev = n;
        n->prev->next = n;
        size++;
    }

    void add_between(int num, node* curr){
        node* n = (node*)calloc(1, sizeof(node));
        n->val = num;
        n->next = curr;
        n->prev = curr->prev;
        curr->prev = n;
        n->prev->next = n;
        size++;
    }

    void add(int num){
        if(size == 0){
            add_head(num);
            return;
        }
        add_tail(num);
    }

    void add_at(int num, int pos){
        if(size == 0){
            cout << "Add elements first!" << endl;
            return;
        }
        if(pos <= 0){
            cout << "Invalid pos" << endl;
            return;
        }
        if(pos == 1){
            add_head(num);
            return;
        }
        if(pos > size){
            add_tail(num);
            return;
        }
        node* curr = head->next->next;
        int idx = 2;
        while(idx != pos){
            curr = curr->next;
            idx++;
        }
        add_between(num, curr);
    }

    void remove_head(){
        cout << "Removed (head): " << head->next->val << endl;
        node* store = head->next;
        head->next = head->next->next;
        head->next->prev = head;
        free(store);
        size--;
    }

    void remove_tail(){
        cout << "Removed (tail): " << tail->prev->val << endl;
        node* store = tail->prev;
        tail->prev = tail->prev->prev;
        tail->prev->next = tail;
        free(store);
        size--;
    }

    void remove_between(node* curr){
        cout << "Removed: " << curr->val << endl;
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        free(curr);
        size--;
    }

    void remove(int num){
        if(size == 0){
            cout << "Nothing to remove, list is empty" << endl;
            return;
        }
        if(head->next->val == num){
            remove_head();
            return;
        }
        if(tail->prev->val == num && !is_sorting){
            remove_tail();
            return;
        }
        node* curr = head->next->next;
        while(curr->val != num && curr != tail){
            curr = curr->next;
        }
        if(curr == tail){
            cout << "Element not found" << endl;
            return;
        }
        else remove_between(curr);
    }

    void remove_at(int pos){
        if(size == 0){
            cout << "Nothing to remove, list is empty" << endl;
            return;
        }
        if(pos <= 0){
            cout << "Invalid pos" << endl;
            return;
        }
        if(pos == 1){
            cout << "At index 1, ";
            remove_head();
            return;
        }
        if(pos >= size){
            cout << "At index " << size << ", ";
            remove_tail();
            return;
        }
        node* curr = head->next->next;
        int idx = 2;
        while(idx != pos){
            curr = curr->next;
            idx++;
        }
        cout << "At index " << idx << ",";
        remove_between(curr);
    }

    void remove_dupe(int num){
        if(size == 0){
            cout << "List empty" << endl;
            return;
        }
        node* curr = head->next;
        while(curr != tail){
            if(curr->val == num){
                remove_between(curr);
                curr = curr->prev;
            }
            curr = curr->next;
        }
    }

    void remove_all(){
        if(size == 0){
            cout << "List empty fam" << endl;
            return;
        }
        while(size != 0){
            remove_head();
        }
    }

    void sort(){
        is_sorting = true;
        node* curr = head->next;
        node* comp = curr;
        int border = size, idx = 0;
        while(border != 0){
            while(idx != border){
                if(curr->val < comp->val){
                    comp = curr;
                }
                curr = curr->next;
                idx++;
            }
            add_tail(comp->val);
            remove(comp->val);
            idx = 0;
            border--;
            comp = curr = head->next;
        }
        is_sorting = false;
    }

    void rotate(int places, char direction){
        tail->prev->next = head->next;
        head->next->prev = tail->prev;
        node* curr;
        if(direction == 'l'){
            curr = head->next;
            while(places != 0){
                curr = curr->next;
                places--;
            }
        }else if(direction == 'r'){
            curr = tail->prev;
            while(places != 0){
                curr = curr->prev;
                places--;
            }
        }

        head->next = curr;
        tail->prev = curr->prev;
        curr->prev = head;
        tail->prev->next = tail;
    }

    void retain(int num){
        int removed = 0;
        node* curr = head->next;
        while(curr != tail){
            if(curr->val < num){
                remove_between(curr);
                curr = curr->prev;
                removed++;
            }
            curr = curr->next;
        }
        cout << "Removed " << removed << " items, Retained " << (size+removed)-removed << endl;
    }

    void corner(int left, int right){
        if(left == 0 && right == 0){
            cout << "Corner, removed all, " << size << " items" << endl;
            remove_all();
            return;
        }
        right = (size + 1) - right;
        int count = 0;
        if(left == 0 && right > 0){
            left = 1;
            while(left != right){
                remove_head();
                count++;
                left++;
            }
            cout << "Corner, removed all left, " << count << " items" << endl;
            return;
        }
        if(right == size+1 && left > 0){
            right--;
            while(right != left){
                remove_tail();
                count++;
                right--;
            }
            cout << "Corner, removed all right, " << count << " items" << endl;
            return;
        }
        //traverse to left
        int idx = 1;
        node* curr = head->next;
        while(idx != left){
            curr = curr->next;
            idx++;
        }
        curr = curr->next;
        idx++;
        //remove up until right
        while(idx != right){
            remove_between(curr);
            count++;
            curr = curr->prev;
            curr = curr->next;
            idx++;
        }
        cout << "Corner, removed " << count << " items" << endl;
    }

    int get_at(int pos){
        if(pos > size || pos <= 0){
            cout << "Invalid pos" << endl;
            return -1;
        }
        if(pos == 1) return head->next->val;
        if(pos == size) return tail->prev->val;
        node* curr = head->next->next;
        int idx = 2;
        while(idx != pos){
            curr = curr->next;
            idx++;
        }
        return curr->val;
    }

    void merge(doublylist* d){
        int d_size = d->get_size();
        int idx = 0;
        while(idx != d_size){
            idx++;
            this->add_tail(d->get_at(idx));
        }
        d->remove_all();
        this->sort();
    }

    void print(){
        if(size == 0){
            cout << "List is empty boi" << endl;
            return;
        }
        node* curr = head->next;
        while(curr != tail){
            cout << curr->val << "->";
            curr = curr->next;
        }
        cout << endl;
    }

    void print_rev(){
        if(size == 0){
            cout << "List is empty boi" << endl;
            return;
        }
        node* curr = tail->prev;
        while(curr != head){
            cout << curr->val << "<-";
            curr = curr->prev;
        }
        cout << endl;
    }
};