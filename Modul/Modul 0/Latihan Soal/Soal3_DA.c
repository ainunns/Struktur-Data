#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct dynamicArr_t {
    char **_arr;
    int _size, _capacity;
} DynamicArray;

void init(DynamicArray *dArr){
    dArr->_capacity = 2;
    dArr->_size = 0;
    dArr->_arr = (char**) malloc(sizeof(char*) * 2);
    for(int i = 0; i < 2; i++)    
        dArr->_arr[i] = (char*) malloc(sizeof(char) * 101);
}

bool isEmpty(DynamicArray *dArr){
    return (dArr->_size == 0);
}

void push_back(DynamicArray *dArr, char* val){
    if(dArr->_size + 1 > dArr->_capacity){
        dArr->_capacity *= 2;
        char **newArr = (char**) malloc(sizeof(char*) * dArr->_capacity);
        for(int i = 0; i < dArr->_capacity; i++)
            newArr[i] = (char*) malloc(sizeof(char) * 101);
        for(int i = 0; i < dArr->_size; i++){
            strcpy(newArr[i], dArr->_arr[i]);
        }
        char **oldArr = dArr->_arr;
        dArr->_arr = newArr;
        for(int i = 0; i < dArr->_capacity; i++)
            free(newArr[i]);
        free(oldArr);
    }
    strcpy(dArr->_arr[dArr->_size++], val);
}

void pop_back(DynamicArray *dArr){
    if(!isEmpty(dArr))
        dArr->_size--;
}

char* back(DynamicArray *dArr){
    if(!isEmpty(dArr))
        return dArr->_arr[dArr->_size-1];
    return NULL;
}

char* front(DynamicArray *dArr){
    if(!isEmpty(dArr))
        return dArr->_arr[0];
    return NULL;
}

void setAt(DynamicArray *dArr, int index, char *val){
    if(!isEmpty(dArr)){
        if(index >= dArr->_size)
            strcpy(dArr->_arr[dArr->_size-1], val);
        else 
            strcpy(dArr->_arr[index], val);
    }
}

char* getAt(DynamicArray *dArr, int index){
    if(!isEmpty(dArr)){
        if(index >= dArr->_size)
            return dArr->_arr[dArr->_size-1];
        else 
            return dArr->_arr[index];
    }
    return NULL;
}

int main(){
    DynamicArray a;
    init(&a);
    push_back(&a, "apel");
    printf("%s\n", back(&a));
    push_back(&a, "bebek");
    printf("%s\n", back(&a));
    while(!isEmpty(&a)){
        printf("%s\n", back(&a));
        pop_back(&a);
    }   
}  