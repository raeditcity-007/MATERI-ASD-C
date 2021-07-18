#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
//Radithya Airlangga-672019007
//Soal A
//Deklarasi Struct
typedef struct dnode_t{
    int data;
    struct dnode_t *next, *prev;
} DListNode;
typedef struct deque_t{
    DListNode *_head, *_tail;
    unsigned _size;
}Deque;
//Deklarasi Fungsi
DListNode* __dlist_createNode(int value);
void deq_init(Deque *deque);
bool deq_isEmpty(Deque *deque);
void deq_pushFront(Deque *deque, int value);
void deq_pushBack(Deque *deque, int value);
int deq_front(Deque *deque);
int deq_back(Deque *deque);
void deq_popFront(Deque *deque);
void deq_popBack(Deque *deque);

DListNode* __dlist_createNode(int value){
    DListNode *newNode = (DListNode*)malloc(sizeof(DListNode));

    if(!newNode) return NULL;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return(DListNode*)newNode;
}
void deq_init(Deque *deque){
    deque->_head = deque->_tail = NULL;
    deque->_size = (unsigned) 0;
}
bool deq_isEmpty(Deque *deque){
    return(deque->_head == NULL && deque->_tail == NULL);
}
void deq_pushFront(Deque *deque, int value){
    DListNode *newNode = __dlist_createNode(value);
    if(newNode){
        deque->_size++;
        if(deq_isEmpty(deque)){
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }
        newNode->next = deque->_head;
        deque->_head->prev = newNode;
        deque->_head = newNode;
    }
}
void deq_pushBack(Deque *deque, int value){
    DListNode *newNode = __dlist_createNode(value);
    if(newNode){
        deque->_size++;
        if(deq_isEmpty(deque)){
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }
        deque->_tail->next = newNode;
        newNode->prev = deque->_tail;
        deque->_tail = newNode;
    }
}
int deq_front(Deque *deque){
    if(!deq_isEmpty(deque)){
        return(deque->_head->data);
    }
    return 0;
}
int deq_back(Deque *deque){
    if(!deq_isEmpty(deque)){
        return(deque->_tail->data);
    }
    return 0;
}
void deq_popFront(Deque *deque){
    if(!deq_isEmpty(deque)){
       DListNode *temp = deque->_head;
       if(deque->_head == deque->_tail){
        deque->_head = NULL;
        deque->_tail = NULL;
        free(temp);
       }else{
        deque->_head = deque->_head->next;
        deque->_head->prev = NULL;
        free(temp);
       }
       deque->_size--;
    }
}
void deq_popBack(Deque *deque){
    if(!deq_isEmpty(deque)){
       DListNode *temp;
       if(deque->_head == deque->_tail){
        temp = deque->_head;
        deque->_head = NULL;
        deque->_tail = NULL;
        free(temp);
       }else{
        temp = deque->_tail;
        deque->_tail = deque->_tail->prev;
        deque->_tail->next = NULL;
        free(temp);
       }
       deque->_size--;
    }
}
int main(int argc, char const *argv[]){
    Deque mydata;
    deq_init(&mydata);

    int x, a, nomor;
    char abjad[20];
    scanf("%d", &a);
    for(x=1; x<=a; x++){
        scanf("%s %d", abjad, &nomor);
        if(strcmp(abjad, "push_back")==0)
            deq_pushBack(&mydata, nomor);
        else if(strcmp(abjad, "push_front"==0))
            deq_pushFront(&mydata, nomor);
        else if(strcmp(abjad, "pop_front")==0)
            deq_popFront(&mydata);
        else if(strcmp(abjad, "pop_back")==0)
            deq_popBack(&mydata);
    }
    while(!deq_isEmpty(&mydata)){
        printf("%d\n", deq_front(&mydata));
        deq_popFront(&mydata);
    }
    puts("");
    return 0;
}
