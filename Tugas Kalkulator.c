#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
//Radithya Airlangga-672019007
//Asisten Algoritma Struktur Data H
int tambah(int a, int b)
{
    return a+b;
}

int kurang(int a, int b)
{
    return a-b;
}

int kali(int a, int b)
{
    return a*b;
}

float bagi(int a, int b)
{
    return(float) a/b;
}

int pangkat(int a, int b)
{
    return pow(a,b);
}

int faktorial(int a)
{
    if(a==0)
    {
        return 1;
    }else
    {
        return a*faktorial(a-1);
    }
}
typedef float hasil; //Tipe Data Abstrak
void main()
{
    Balik:
    printf("Tugas Asisten ASD-Kalkulator\n");
    printf("=================================================\n");
    int pilihan,a,b,c;
    c=a;
    char keluar;
    hasil jawab; //Tipe Data Abstrak
    printf("Masukkan Angka Pertama : ");
    scanf("%i",&a);
    printf("Masukkan Angka Kedua: ");
    scanf("%i",&b);
    printf("=================================================\n");
    printf("Pilih Menu Operasi\n");
    printf("=================================================\n");
    printf("1. Penjumlahan <+>\n");
    printf("2. Pengurangan <->\n");
    printf("3. Perkalian <*>\n");
    printf("4. Pembagian </>\n");
    printf("5. Pangkat <^>\n");
    printf("6. Faktorial <!>\n");
    printf("7. Reset\n");
    printf("8. Keluar\n");
    printf("=================================================\n");
    printf("Pilih Menu Operasi: ");
    scanf("%i",&pilihan);

    switch(pilihan)
    {
    case 1 :
        printf("=================================================\n");
        jawab = tambah(a,b);break;

    case 2 :
        printf("=================================================\n");
        jawab = kurang(a,b);break;

    case 3 :
        printf("=================================================\n");
        jawab = kali(a,b);break;

    case 4 :
        printf("=================================================\n");
        jawab = bagi(a,b);break;

    case 5 :
        printf("=================================================\n");
        jawab = pangkat(a,b);break;

    case 6 :
        jawab = faktorial(a);break;

    case 7 :
        a=0;
        system("cls");
        goto Balik;
        break;

    case 8 :
        do
        {
        printf("\nTerimakasih Sudah Mencoba Kalkulator\n");
        printf("\n\nRadithya Airlangga-672019007\n");
        exit(0);
        keluar=getch();
        }while(keluar='true');

    default :
        printf("Pilihan Tidak Tersedia\n");
        printf("=================================================\n");
        printf("Press Any Key To Continue\n");
        getch();
        goto Balik;
    }
    printf("=================================================\n");
    printf("Hasil = %.4f\n",jawab);
    printf("=================================================\n");
    printf("Press Any Key To Continue\n");
    getch();
    system("cls");
    goto Balik;
}
