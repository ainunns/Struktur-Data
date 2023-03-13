#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_t {
    int data;
    struct node_t *next, *prev;
} DListNode;

typedef struct list_t {
    int _size;
    DListNode *head, *tail;
} DoublyList;

DListNode *createNode(int val){
    DListNode *newNode = (DListNode*) malloc(sizeof(DListNode));

    if(!newNode)
        return NULL;
    
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    return (DListNode*) newNode;
}

void init(DoublyList *list){
    list->head = list->tail = NULL;
    list->_size = 0;
}

bool isEmpty(DoublyList *list){
    return (list->head == NULL && list->tail == NULL);
}

void push_front(DoublyList *list, int val){
    DListNode *newNode = createNode(val);
    if(newNode){
        list->_size++;
        if(isEmpty(list)){
            list->head = newNode;
            list->tail = newNode;
            return;
        }
        
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
}

void push_back(DoublyList *list, int val){
    DListNode *newNode = createNode(val);
    if(newNode) {
        list->_size++;
        if(isEmpty(list)){
            list->head = list->tail = newNode;
            return;
        }
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
}

void insertAt(DoublyList *list, int index, int val){
    if(index == 0){
        push_front(list, val);
        return;
    }
    if(index >= list->_size){
        push_back(list, val);
        return;
    }
    DListNode *newNode = createNode(val);
    if(newNode){
        if(isEmpty(list)){
            list->head = list->tail = newNode;
            return;
        }

        DListNode *tmp = list->head;
        int i = 0;
        
        while(tmp->next != NULL && i < index-1){
            tmp = tmp->next;
            i++;
        }

        newNode->next = tmp->next;
        newNode->prev = tmp;

        if(tmp->next)
            tmp->next->prev = newNode;
        
        tmp->next = newNode;
        list->_size++;
    }
}

int back(DoublyList *list){
    if(!isEmpty(list)){
        return list->tail->data;
    }
    return 0;
}

int front(DoublyList *list){
    if(!isEmpty(list)){
        return list->head->data;
    }
    return 0;
}

void pop_front(DoublyList *list){
    if(!isEmpty(list)){
        DListNode *tmp = list->head;
        if(list->head == list->tail){
            list->head = list->tail = NULL;
        } else {
            list->head = list->head->next;
            list->head->prev= NULL;
        }
        free(tmp);
        list->_size--;
    }
}

void pop_back(DoublyList *list){
    if(!isEmpty(list)){
        DListNode *tmp;
        if(list->head == list->tail){
            tmp = list->head;
            list->head = list->tail = NULL;
            free(tmp);
        } else {
            tmp = list->tail;
            list->tail = list->tail->prev;
            list->tail->next = NULL;
            free(tmp);
        }
        list->_size--;
    }
}

int main(){
    DoublyList dl;
    init(&dl);

    push_back(&dl, 1);
    push_back(&dl, 2);
    push_back(&dl, 3);
    push_back(&dl, 4);

    push_front(&dl, 10);
    push_front(&dl, 9);
    push_front(&dl, 8);
    push_front(&dl, 7);

    pop_back(&dl);
    pop_front(&dl);

    insertAt(&dl, 6, 100);
    insertAt(&dl, 1, 13);
    
    while (!isEmpty(&dl)) {
        printf("%d ", front(&dl));
        pop_front(&dl);
    }
}