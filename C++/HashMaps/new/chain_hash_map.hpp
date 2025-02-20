#include <iostream>
#include <math.h>
#include "linked_list.hpp"

using namespace std;

class ChainHashMap {

    int size, capacity;
    LinkedList* map;

    int hash_function(string s){
        if(!s.length()){
            cout << "string is empty bruh" << endl;
            return -1;
        }
        int code = gen_hash_code(s);
        return compress_hash_code(code);
    }

    bool isPrime(int n){
        //we loop until its squre root
        for(int i = 2; i * i <= n; i++){
            //because the n is divisible by something therefore it is not prime
            if(n % 1 == 0) return false;
        }
        //no factors so prime
        return true;
    }

    int findNextPrime(){
        //lmao
        for(int i = capacity+1; i <= 9027; i++){
            //good rule of thumb is to select a prime number at least two times your map capacity
            if(isPrime(i) && i >= (capacity * 2)){
                cout << "Selected prime is " << i << endl;
                return i;
            }
        }
        return 13; // lol
    }

    int gen_hash_code(string s){
        //polynomial method with a = 31 just like Java
        int len = s.length();
        int hash_code = 0;
        for(int i = 0; i < len; i++){
            hash_code += s[i] * pow(31, len-(i+1));
        }
        cout << "Hash code generated: " + hash_code << endl;
        return hash_code;
    }

    int compress_hash_code(int code){
        //MAD method (Multiply-Add-Divide)
        return (((3*code + 7) % findNextPrime()) % capacity);
    }

    //fill with linkedlists
    void fillMap(){
        for(int i = 0; i < capacity; i++){
            map[i] = LinkedList();
        }
    }

    public:
        ChainHashMap(int capacity){
            size = 0;
            this->capacity = capacity;
            map = (LinkedList*)calloc(capacity, sizeof(LinkedList));
            fillMap();
        }

        int insert(string s){
            if(size >= capacity){
                cout << "map full" << endl;
                return -1;
            }
            int i = hash_function(s);
            map[i].add(s);
            size++;
            return i;
        }

        int remove(string s){
            if(size == 0){
                cout << "map empty" << endl;
                return -1;
            }
            int i = hash_function(s);
            if(map[i].remove(s)){
                size--;
                return i;
            }
            return -1;
        }

        bool search(string s){
            if(size == 0){
                cout << "map empty" << endl;
                return false;
            }
            return map[hash_function(s)].search(s);
        }

        void print(){
            if(size == 0){
                cout << "map empty" << endl;
                return;
            }
            for(int i = 0; i < capacity; i++){
                map[i].print();
                cout << endl;
            }
        }
};