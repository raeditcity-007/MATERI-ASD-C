#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
//Radithya Airlangga-672019007
//Materi Linked List(CRUD)

//Deklarasikan Fungsi
void tambah_barang();
void lihat_barang();
void cetak_barang();
void pilih_barang(char mode[50]);
int  cari_barang(char kode_barang[50]);
void update_barang();
void salin_barang();
void riwayat_barang();
void hapus_barang();
//Deklarasi Struct
struct toko{
    char kode[50],nama[50],harga[50],stock[50];
    int jumlah;
    struct toko *next;
    struct toko *history;
};  struct toko *baru,*head_sort=NULL, *head=NULL, *tail=NULL,*masuk,*masuk2;
//Untuk Menambah Barang Toko
void tambah_barang(){
    int x;
    int jumlah_barang, masukan;
    char kode_barang[50],nama_barang[50],harga_barang[50],stock_barang[50];

    system("cls");
    printf("\tBanyak Data Yang Akan Dimasukan : ");
    scanf("%d",&masukan);
    printf("\n");
    for(x=1; x<=masukan; x++){
    printf("\tMasukan Data Barang Toko[%d]\n",x);
    baru = (struct toko*)malloc(sizeof(struct toko));
    fflush(stdin);
    printf("\tMasukan Kode Barang : ");
    gets(baru->kode);
    printf("\tMasukan Nama Barang : ");
    gets(baru->nama);
    printf("\tMasukan Harga Barang : ");
    gets(baru->harga);
    printf("\tMasukan Stock Barang : ");
    gets(baru->stock);
    printf("\tMasukan Jumlah Barang: ");
    scanf("%d",&baru->jumlah);
    printf("\n\n");

    baru->next=NULL;
    if(head == NULL)
    {
        head=baru;
        tail=baru;
    }
    else
    {
        tail=head;
        while(tail->next!=NULL)
        {
            tail=tail->next;
        }
        tail->next=baru;

    }
    }getch();
}
//Untuk Melihat Barang Toko
void lihat_barang(){
    int x =1;
    if(head != NULL)
    {
        masuk=head;
        while(masuk != NULL)
        {
            printf("\t\t\t Data Barang Toko[%d]\n",x);
            cetak_barang();
            x++;
            masuk=masuk->next;
        }
    }
    else
    {
        printf("\t\t\t Belum Ada Barang Masuk");
    }
}
//Untuk Tampilkan Barang Toko
void cetak_barang(){
    printf("\tKode Barang:\t%s\n",masuk->kode);
    printf("\tNama Barang:\t%s\n",masuk->nama);
    printf("\tHarga Barang:\t%s\n",masuk->harga);
    printf("\tStock Barang:\t%s\n",masuk->stock);
    printf("\tJumlah Barang:\t%d\n\n",masuk->jumlah);
}
//Untuk Memilih Data Misal Akan Update Barang Lainnya
void pilih_barang(char mode[50]){
    if(head==NULL){
        return;
    }
    int loop = 1;
    char input;
    char nama[50];
    while(loop == 1)
    {
        system("cls");
        printf("\tUbah Data Barang Toko\n\n");
        lihat_barang();
        printf("\tTekan n untuk lanjut");
        input=getche();
        switch(input)
        {
        case'n':
            printf("\n\n\tCari Barang Berdasarkan Nama: ");
            scanf("%s",nama);
            if(cari_barang(nama) ==1)
            {
                if(strcmp(mode,"Ubah") == 0)
                {
                    update_barang();
                }

                else if(strcmp(mode,"Riwayat") == 0)
                {
                    riwayat_barang();
                }
            }
            else
            {
                printf("\t\t\t Data tidak ditemukan!");
                getch();
            }
        default:
            loop=0;
            break;

        }
    }
}
//Untuk Mencari Barang Toko
int cari_barang(char nama[50]){
    int flagIsFound=0;
    masuk=head;
    while(masuk != NULL){
        if(strcmp(masuk->nama,nama) == 0){
            flagIsFound=1;
            break;
        }else{
            masuk=masuk->next;
        }
    }
    return flagIsFound;
}
//Untuk Mengedit Data
void update_barang(){
    int input;
    char kodeBaru[50],namaBaru[50],hargaBaru[50],stockBaru[50];
    int jumlahBaru[50];
    int loop =1;
    while(loop == 1){
        system("CLS");
        cetak_barang();
        printf("\t1. Ganti Kode Barang.\n");
        printf("\t2. Ganti Nama Barang.\n");
        printf("\t3. Ganti Harga Barang.\n");
        printf("\t4. Ganti Stock Barang.\n");
        printf("\t5. Ganti Jumlah Barang.\n");
        printf("\t6. KELUAR.\n");
        printf("\tMasukan Pilihan Anda : ");
        scanf("%d", &input);
        printf("\n\n");
        switch(input)
        {
        case 1:
            printf("\t\t\t Masukkan Kode Baru: ");
            scanf("%s",kodeBaru);
            salin_barang();
            strcpy(masuk->kode,kodeBaru);
            masuk->history=baru;
            break;
        case 2:
            printf("\t\t\t Masukkan Nama Barang Baru: ");
            scanf("%s",namaBaru);
            salin_barang();
            strcpy(masuk->nama,namaBaru);
            masuk->history=baru;
            break;
        case 3:
            printf("\t\t\t Masukkan Harga Baru: ");
            scanf("%s",hargaBaru);
            salin_barang();
            strcpy(masuk->harga,hargaBaru);
            masuk->history=baru;
            break;
        case 4:
            printf("\t\t\t Masukkan Stock Baru: ");
            scanf("%s",stockBaru);
            salin_barang();
            strcpy(masuk->stock,stockBaru);
            break;
        case 5:
            printf("\t\t\t Masukkan  Jumlah Barang Baru: ");
            scanf("%d",&masuk->jumlah);
            masuk->history=baru;
            break;
        case 6:
            loop=0;
            break;
        }
    }
}
//Untuk Menampilkan/Menyalin Barang Di Toko Setelah Update Barang Toko
void salin_barang(){
    baru = (struct toko*)malloc(sizeof(struct toko));
    strcpy(baru->kode,masuk->kode);
    strcpy(baru->nama,masuk->nama);
    strcpy(baru->harga,masuk->harga);
    strcpy(baru->stock,masuk->stock);
    baru->jumlah=masuk->jumlah;
    baru->history=masuk->history;
    baru->next=NULL;
}
//Melihat Riwayat Perubahan Pada Barang Toko
void riwayat_barang(){
    int x=1;
    system("CLS");
    printf("\tRiwayat Perubahan Barang Toko(terbaru -> terlama)");
    while(masuk != NULL)
    {
        printf("\n\n \t\t\t Data:%d\n",x);
        cetak_barang();
        masuk=masuk->history;
        x++;
    }
    getch();
}
//Menghapus Barang Toko
void hapus_barang(){
    char del[50];
    int a=0, i;
    lihat_barang();
    printf("\nMasukan Kode Barang Toko Yang Ingin Di Hapus : ");
    scanf("%s",&del);

    struct toko*p;
    struct toko*q;
    q=head;
    p=head->next;

    if(strcmp(q->kode,del)==0){
        head=p;
        free(q);
    }else{
        while(strcmp(p->kode,del)!=0)
        {
            p=p->next;
            q=q->next;
        }
        if(p->next==NULL){
            q->next=NULL;
            free(p);
        }else{
            q->next=p->next;
            free(p);
        }
    }
}
int main(){
char pilih;
    while(1)
    {
        system("cls");
        printf("\tProgram Data Barang Toko\n\n");
        printf("\t=======================Pilihan Operasi=======================\n\n");
        printf("\t1. Tambah Barang Toko\n");
        printf("\t2. Lihat Barang Toko\n");
        printf("\t3. Update Barang Toko\n");
        printf("\t4. Hapus Barang Toko\n");
        printf("\t5. Histori \n");
        printf("\t6. Keluar \n");
        printf("\n\tPilihan Operasi Yang Akan Anda Lakukan : ");
        scanf("%d",&pilih);
        switch(pilih)
        {
        case 1:
            tambah_barang();
            break;
        case 2:
            system("cls");
            printf("\tData Barang Toko\n\n");
            lihat_barang();
            getch();
            break;
        case 3:
            pilih_barang("Update");
            break;
        case 4:
            system("cls");
            hapus_barang();
            break;
        case 5:
            pilih_barang("Riwayat");
            break;
        }
    }
//    }else
    getch();
}
