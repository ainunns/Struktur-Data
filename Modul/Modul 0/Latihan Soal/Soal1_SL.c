#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_t {
    int data;
    struct node_t *next;
} SListNode;

typedef struct list_t {
    int _size;
    SListNode *head;
} SinglyList;

void init(SinglyList *list){
    list->head = NULL;
}

bool isEmpty(SinglyList *list){
    return (list->head == NULL);
}

void push_back(SinglyList *list, int val){
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if(newNode) {
        list->_size++;
        newNode->data = val;
        newNode->next = NULL;
        if(isEmpty(list)){
            list->head = newNode;
        } else {
            SListNode *tmp = list->head;
            while(tmp->next != NULL)
                tmp = tmp->next;
            tmp->next = newNode;
        }
    }
}

void push_front(SinglyList *list, int val){
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if(newNode){
        list->_size++;
        newNode->data = val;

        if(isEmpty(list))
            newNode->next = NULL;
        else 
            newNode->next = list->head;
        list->head = newNode;
    }
}

void insertAt(SinglyList *list, int index, int val){
    if(index == 0){
        push_front(list, val);
        return;
    }
    if(isEmpty(list) || index >= list->_size){
        push_back(list, val);
        return;
    }
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if(newNode){
        SListNode *tmp = list->head;
        int i = 0;
        
        while(tmp->next != NULL && i < index-1){
            tmp = tmp->next;
            i++;
        }

        newNode->data = val;
        newNode->next = tmp->next;
        tmp->next = newNode;
        list->_size++;
    }
}

int back(SinglyList *list){
    if(!isEmpty(list)){
        SListNode *tmp = list->head;
        while(tmp->next != NULL)
            tmp = tmp->next;
        return tmp->data;
    }
    return 0;
}

int front(SinglyList *list){
    if(!isEmpty(list)){
        return list->head->data;
    }
    return 0;
}

int getAt(SinglyList *list, int index){
    if(!isEmpty(list)){
        SListNode *tmp = list->head;
        int i = 0;
        while(tmp->next != NULL && i < index){
            tmp = tmp->next;
            i++;
        }
        return tmp->data;
    }
    return 0;
}

void pop_back(SinglyList *list){
    if(!isEmpty(list)){
        SListNode *curNode = list->head;
        SListNode *nxtNode = curNode->next;

        if(nxtNode == NULL){
            free(curNode);
            list->head = NULL;
            return;
        }

        while(nxtNode->next != NULL){
            curNode = nxtNode;
            nxtNode = curNode->next;
        }

        curNode->next = NULL;
        free(nxtNode);
        list->_size--;
    }
}

void pop_front(SinglyList *list){
    if(!isEmpty(list)){
        SListNode *tmp = list->head;
        list->head = list->head->next;
        free(tmp);
        list->_size--;
    }
}

void removeAt(SinglyList *list, int val){
    if(!isEmpty(list)){
        SListNode *tmp = list->head, *prev;

        if(tmp->data == val){
            pop_front(list);
            return;
        }

        while(tmp != NULL && tmp->data != val){
            prev = tmp;
            tmp = tmp->next;
        }

        if(tmp == NULL)
            return;
        prev->next = tmp->next;
        free(tmp);
        list->_size--;
    }
}

void printElement(SListNode *elem){
    printf("%d\n", elem->data);
}

void multiply2(SListNode *elem){
    elem->data *= 2;
}

void reverseEach(SListNode *elem){
    int temp = elem->data, res = 0;
    while(temp){
        res = (10*res) + temp%10;
        temp /= 10;
    }
    elem->data = res;
}

void sumDigit(SListNode *elem){
    int temp = elem->data, res = 0;
    while(temp){
        res += temp%10;
        temp /= 10;
    }
    elem->data = res;
}

void forEachElement(SinglyList *list, void (*func)(SListNode *)){
    if(!isEmpty(list)){
        SListNode *tmp = list->head;

        while(tmp != NULL){
            func(tmp);
            tmp = tmp->next;
        }
    }
}

int main(){
    SinglyList sl;
    init(&sl);
    for(int i = 102; i < 112; i++){
        push_back(&sl, i);
    }
    
    pop_back(&sl);
    pop_front(&sl);

    removeAt(&sl, 2);
    insertAt(&sl, 4, 7832);

    forEachElement(&sl, printElement);
    forEachElement(&sl, reverseEach);
    forEachElement(&sl, printElement);
    forEachElement(&sl, sumDigit);
    forEachElement(&sl, printElement);
}