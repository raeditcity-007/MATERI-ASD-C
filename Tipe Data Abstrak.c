#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//Tipe data abstrak :
typedef int angka;
typedef char huruf;
//typedef float umur;
int main()
{
    angka umur;
    huruf nama[10];
        printf("Masukkan Umur = ");
        scanf("%d", &umur);
        printf("Umur yang dimasukkan adalah %d\n", umur);

        printf("\nMasukkan Nama = ");
        scanf("%s", &nama);
        printf("Nama yang dimasukkan adalah %s", nama);

    return 0;
}
