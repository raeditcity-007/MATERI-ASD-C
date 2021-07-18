#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#define MIN(a,b)((a)<(b)?a:b)
//Radithya Airlangga-672019007
//Soal E
int main(){
    int n;
    scanf("%d", &n);
    long long a[n];
    int temp, nleft[n], nright[n];
    for(temp = 0; temp<n; temp++){
        scanf("%lld", &a[temp]);
        nleft[temp]=temp-1;
        if(temp == n-1)nright[temp] = -1;
        else nright[temp] = temp+1;
    }
    long long sum = 0;
    while(true){
        int start = 0;
        while(start!=nleft[nright[start]]){
            start++;
            if(nright[start]==-1){
                printf("%lld\n", sum);
                return 0;
            }
        }
        for(temp=start; nright[temp]!=-1; temp=nright[temp]){
            if((nleft[temp]==-1)&&(a[temp]<=a[nright[temp]])){
                sum=sum+a[nright[temp]];
                nleft[nright[temp]]=-1;
            }else if((a[temp]<=a[nleft[temp]])&&(a[temp]<=a[nright[temp]])&&(nleft[temp]!=-1)){
                sum=sum+MIN(a[nleft[temp]], a[nright[temp]]);
                nright[nleft[temp]]=nright[temp];
                nleft[nright[temp]]=nleft[temp];
            }
        }
        if((a[temp]<=a[nleft[temp]])&&(nleft[temp]!=-1)){
            sum=sum+a[nleft[temp]];
            nright[nleft[temp]]=-1;
        }
    }
}
