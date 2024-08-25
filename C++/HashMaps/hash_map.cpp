#include <iostream>
#include <string>
#include "hash_map.h"

using namespace std;

Hash_Map::Hash_Map(){
    arr_int = (int*)calloc(13, 4);
    arr_str = (string*)calloc(13, sizeof(string));
    for(int i = 0; i < curr_size; i++) *(arr_str + i) = "0";
}

int* Hash_Map::resize_int_arr(int* arr, int* size){
    int* temp = (int*)calloc(*size*2, 4);
    for(int i = 0; i < *size; i++) *(temp + i) = *(arr + i);
    *size *= 2;
    f_size *= 2;
    return temp;
}

string* Hash_Map::resize_str_arr(string* arr, int* size){
    string* temp = (string*)calloc(*size*2, sizeof(string));
    for(int i = 0; i < *size; i++) *(temp + i) = *(arr + i);
    *size *= 2;
    f_size *= 2;
    return temp;
}

int Hash_Map::hash_func(int key){
    return key % curr_size;
}

int Hash_Map::hash_func(string key){
    int hash = 0;
    for(int i = 0; i < key.length()-1; i++) hash += key[i];
    return hash = hash % curr_size;
}

void Hash_Map::arr_checker(int hash, int val){
    if(*(arr_int + hash) != 0) cout << "Collision at idx: " << hash << " val: " << val << endl;
    else{
        *(arr_int + hash) = val;
        count++;
    }
}

void Hash_Map::arr_checker(int hash, string val){
    if(*(arr_str + hash) != "0") cout << "Collision at idx: " << hash << " val: " << val << endl;
    else{
        *(arr_str + hash) = val;
        count++;
    }
}

void Hash_Map::add(int key, int val){
    if((count / f_size) >= 0.75){
        resize_int_arr(arr_int, &curr_size);
    }else arr_checker(hash_func(key), val);
}

void Hash_Map::add(string key, string val){
    if((count / f_size) >= 0.75){
        resize_str_arr(arr_str, &curr_size);
    }else arr_checker(hash_func(key), val);
}

void Hash_Map::remove(int key){
    *(arr_int + hash_func(key)) = 0;
    count--;
}

void Hash_Map::remove(string key){
    *(arr_str + hash_func(key)) = "0";
    count--;
}

void Hash_Map::remove_by_idx_int(int idx){
    *(arr_int + idx) = 0;
    count--;
}

void Hash_Map::remove_by_idx_str(int idx){
    *(arr_str + idx) = "0";
    count--;
}

void Hash_Map::replace(int key, int val){
    *(arr_int + hash_func(key)) = val;
}

void Hash_Map::replace(string key, string val){
    *(arr_str + hash_func(key)) = val;
}

int Hash_Map::retrieve_int(int key){
    return *(arr_int + hash_func(key));
}

string Hash_Map::retrieve_str(string key){
    return *(arr_str + hash_func(key));
}

int Hash_Map::retrieve_by_idx_int(int idx){
    return *(arr_int + idx);
}

string Hash_Map::retrieve_by_idx_str(int idx){
    return *(arr_str + idx);
}

void Hash_Map::print(int i){
    switch(i){
        case 1:
        cout << "Printing int array..." << endl;
        for(int i = 0; i < curr_size; i++){
            if(*(arr_int + i) != 0) cout << i << ": " << *(arr_int + i) << endl;
        }
        break;

        case 2:
        cout << "Printing string array..." << endl;
        for(int i = 0; i < curr_size; i++){
            if(*(arr_str + i) != "0") cout << i << ": " << *(arr_str + i) << endl;
        }
        cout << endl;
        break;
    }
}