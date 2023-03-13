#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct dynamicArr_t {
    int *_arr, _size, _capacity;
} DynamicArray;

void init(DynamicArray *dArr){
    dArr->_size = 0;
    dArr->_capacity = 2;
    dArr->_arr = (int*) malloc(sizeof(int) * 2);
}

bool isEmpty(DynamicArray *dArr){
    return (dArr->_size == 0);
}

void push_back(DynamicArray *dArr, int val){
    if(dArr->_size + 1 > dArr->_capacity){
        dArr->_capacity *= 2;
        int *newArr = (int*) malloc(sizeof(int) * dArr->_capacity);
        for(int i = 0; i < dArr->_size; i++){
            newArr[i] = dArr->_arr[i];
        }
        int *oldArr = dArr->_arr;
        dArr->_arr = newArr;
        free(oldArr);
    }
    dArr->_arr[dArr->_size++] = val;
}

void pop_back(DynamicArray *dArr){
    if(!isEmpty(dArr))
        dArr->_size--;
}

int back(DynamicArray *dArr){
    if(!isEmpty(dArr))
        return dArr->_arr[dArr->_size-1];
    return 0;
}

int front(DynamicArray *dArr){
    if(!isEmpty(dArr))
        return dArr->_arr[0];
    return 0;
}

void setAt(DynamicArray *dArr, int index, int val){
    if(!isEmpty(dArr)){
        if(index >= dArr->_size)
            dArr->_arr[dArr->_size-1] = val;
        else 
            dArr->_arr[index] = val;
    }
}

int getAt(DynamicArray *dArr, int index){
    if(!isEmpty(dArr)){
        if(index >= dArr->_size)
            return dArr->_arr[dArr->_size-1];
        else 
            return dArr->_arr[index];
    }
}

int main(){
    DynamicArray a;
    init(&a);
    for(int i = 0; i < 10; i++){
        push_back(&a, i);
    }
    while(!isEmpty(&a)){
        printf("%d\n", back(&a));
        pop_back(&a);
    }   
}  