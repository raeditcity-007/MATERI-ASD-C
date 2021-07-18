#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
//Radithya Airlangga-672019007
//Soal B
//Deklarasi Struct
typedef struct data{
    int bil;
    struct data *next, *prev;
}node;
int main(){
    int x,y,n,i,j,tot=0,sem;
    char p[5];
    node *baru, *head=NULL, *tail, *temp;
    scanf("%d", &n);
    while(n>0){
        fflush(stdin);
        scanf("%s", &p);
        if(strcmp(p,"add")==0){
            scanf("%d %d", &x, &y);
            tot+=y;
            printf("%d\n", tot);
            for(i=0;i<y;i++){
                baru = (node*)malloc(sizeof(node));
                baru->next = NULL;
                baru->prev = NULL;
                baru->bil = x;
                if(head==NULL){
                    head = baru;
                    tail = baru;
                }else{
                    tail->next = baru;
                    baru->prev = tail;
                    tail = baru;
                }
            }
        }else if(strcmp(p, "del")==0){
            scanf("%d", &x);
            tot-=x;
            for(i=0;i<x;i++){
                if(i==0)
                    printf("%d\n",head->bil);
                baru = head;
                head = head->next;
                if(head !=NULL)
                    head->prev=NULL;
                free(baru);
            }
        }else if(strcmp(p, "rev")==0){
            temp = head;
            baru = tail;
            for(i=0;i<tot/2;i++){
                sem = temp->bil;
                temp->bil = baru->bil;
                baru->bil = sem;
                temp = temp->next;
                baru = baru->prev;
            }
        }
        n--;
    }
}

