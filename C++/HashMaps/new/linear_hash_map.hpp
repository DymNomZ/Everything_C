#include <iostream>
#include <math.h>

using namespace std;

class LinearHashMap {

    int size, capacity;
    int* map;

    int hash_function(int n){
        return compress_hash_code(n);
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
            if(isPrime(i) && i >= (capacity * 2)) return i;
        }
        return 13; // lol
    }

    int compress_hash_code(int code){
        //MAD method (Multiply-Add-Divide)
        return (((3*code + 7) % findNextPrime()) % capacity);
    }

    public:
        LinearHashMap(int capacity){
            size = 0;
            this->capacity = capacity;
            map = (int*)calloc(capacity, 4);
        }

        int insert(int s){
            if(size >= capacity){
                cout << "map full" << endl;
                return -1;
            }
            int i = hash_function(s);
            if(!map[i]){
                map[i] = s;
                size++;
                return i;
            }
            //find vacant
            else{
                int idx = ++i;
                for(int i = 0; i < capacity; i++){
                    //meaning it reaches end of map, loop back to start
                    if(idx % capacity == 0) idx = 0;
                    if(map[idx] == s){
                        size++;
                        return idx;
                    }
                }
                return -1;
            }
        }

        int remove(int s){
            if(size == 0){
                cout << "map empty" << endl;
                return -1;
            }
            for(int i = 0; i < capacity; i++){
                if(map[i] == s){
                    map[i] = -1;
                    size--;
                    return i;
                }
            }
            return -1;
        }

        bool search(int s){
            if(size == 0){
                cout << "map empty" << endl;
                return false;
            }
            for(int i = 0; i < capacity; i++){
                if(map[i] == s) return true;
            }
            return false;
        }

        void print(){
            if(size == 0){
                cout << "map empty" << endl;
                return;
            }
            for(int i = 0; i < capacity; i++){
                cout << "[" << map[i] << "]";
            }
        }
};