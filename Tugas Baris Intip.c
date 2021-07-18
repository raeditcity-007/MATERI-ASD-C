#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
//Radithya Airlangga-672019007
//Soal D
//Deklarasi Struck
typedef struct pqueueNode_t{
    int data, n;
    struct pqueueNode_t *next;
}PQueueNode;
typedef struct pqueue_t{
    PQueueNode *_top;
    unsigned _size;
}PriorityQueue;
//Deklarasi Fungsi
void pqueue_init(PriorityQueue *pqueue);
bool pqueue_isEmpty(PriorityQueue *pqueue);
int pqueue_push(PriorityQueue *pqueue, int value);
void pqueue_pop(PriorityQueue *pqueue);
int pqueue_top(PriorityQueue *pqueue);

void pqueue_init(PriorityQueue *pqueue){
    pqueue->_top = NULL;
    pqueue->_size = 0;
}
bool pqueue_isEmpty(PriorityQueue *pqueue){
    return(pqueue->_top == NULL);
}
int pqueue_push(PriorityQueue *pqueue, int value){
    PQueueNode *newNode = (PQueueNode*)malloc(sizeof(PQueueNode));
    newNode->data = value;
    newNode->next = NULL;
    newNode->n = 1;

    if(pqueue_isEmpty(pqueue)){
        pqueue->_top = newNode;
        return 1;
    }
    newNode->next = pqueue->_top;
    pqueue->_top = newNode;
    PQueueNode *temp = pqueue->_top;
    int count = 1;

    while(true){
        if(temp->next->data <= value){
            newNode->n += temp->next->n;
            temp = temp->next;
        }else{
            pqueue->_top->next = temp->next;
            break;
        }
        if(temp->next == NULL){
            pqueue->_top->next = NULL;
            break;
        }
    }
    return newNode->n;
}
void pqueue_pop(PriorityQueue *pqueue){
    if(!pqueue_isEmpty(pqueue)){
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}
int pqueue_top(PriorityQueue *pqueue){
    if(!pqueue_isEmpty(pqueue))
        return pqueue->_top->data;
    else return 0;
}
int main(int argc, char const *argv[]){
    PriorityQueue myPque;
    pqueue_init(&myPque);

    int n, inp, temp;
    long long int result = 0;
    printf("Masukkan Angka : ");
    scanf("%d", &n);
    while(n--){
        scanf("%d", &inp);
        temp = pqueue_push(&myPque, inp);
        result += temp;
    }
    printf("Hasilnya : ");
    printf("%lld\n", result);
    return 0;
}
