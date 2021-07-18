#include<stdio.h>
#include<string.h>
#include<math.h>
//Radithya Airlangga-672019007
//Soal C
int Data[1002], jumlah[1002], top = -1, a, nBilangan, nilai, temp, b;
void Add(int x, int y){
    int jAdd = 0;
    top++;
    Data[top] = x;
    jumlah[top] = y;
    for(a=0; a<=top; a++){
        jAdd += jumlah[a];
    }
    printf("%d\n",jAdd);
}
void Del(int x){
    printf("%d\n", Data[top]);
    for(a=top; a>=0; a--){
        temp = jumlah[a];
        jumlah[a] -= x;
        if(jumlah[a] <= 0){
            jumlah[a] == 0;
            top--;
            x-= temp;
        }else if (jumlah[a]>0){
            break;
        }
    }
}
void Adx(int x){
    for(a=0; a<=top; a++) Data[a] += x;
}
void Dex(int x){
    for(a=0; a<=top; a++) Data[a] -= x;
}
int main(){
    int TC;
    scanf("%d", &TC);
    char perintah[12];

    while(TC--){
        scanf("%s %d", &perintah, &nilai);
        if(strcmp(perintah, "add")==0){
            scanf("%d", &nBilangan);
            Add(nilai, nBilangan);
        }
        else if(strcmp(perintah, "del")==0) Del(nilai);
        else if(strcmp(perintah, "adx")==0) Adx(nilai);
        else if(strcmp(perintah, "dex")==0) Dex(nilai);
    }
    return 0;
}
