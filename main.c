#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Extraction.h"
// Global Variable
int exit_program ; // kontrol untuk exit program
int user_option ; // menampung pilihan user
long nik_in ; // Input NIK
char nama_lengkap_in[100]; // Input nama lengkap
char tempat_lahir_in[100]; // Input tempat lahir
char tanggal_lahir_in[100]; // Input tanggal lahir
int umur_in; // Input umur
char gender_in[2]; // Input gender
char b_type_in[3]; // Input golongan darah
char status_in[20]; // Input status
char pekerjaan_in[100]; // Input pekerjaan
char waktu_sekarang_str[25]; // Waktu sistem dalam string
char tahun_sekarang_str[5]; // Tahun sistem dalam string
char tahun_lahir_subjek_str[5]; // Tahun lahir subjek dalam string
int tahun_sekarang_int; // Tahun sistem dalam integer
int tahun_lahir_subjek_int; // Tahun lahir subjek dalam integer
//int numbering = 1; // Penomoran data
long nik_up; // NIK Data yang ingin diubah
int feat_up; // Feature yang ingin diubah
int sort_up; // Opsi pengurutan
int sort_trend; // opsi trend pengurutan
char filename [100]; // Menampung nama file external

int main()
{
    // Menenetukan waktu sekarang
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    printf ( "Current local time and date: %s", asctime (timeinfo) );
    strcpy(tahun_sekarang_str,"\0");
    strcpy(tahun_sekarang_str,((asctime(timeinfo))+ 20));
    tahun_sekarang_int = atoi(tahun_sekarang_str);
    exit_program = 0;
    struct Node* last = NULL; // Menampung node terkahir di linked list
    FILE* fp; // File Pointer untuk menempung pointer ke file eksternal
    while(exit_program == 0){
        tampil_menu();
        scanf("%d", &user_option);
        if(user_option == 1){
            // Input NIK
            printf("\nMasukan NIK:");
            scanf("%ld", &nik_in);
            // Input Nama Lengkap
            printf("\nMasukan Nama Lengkap:");
            gets(nama_lengkap_in);
            gets(nama_lengkap_in);
            // Input Tempat Lahir
            printf("\nMasukan Tempat Lahir:");
            gets(tempat_lahir_in);
            // Input Tanggal Lahir
            printf("\nMasukan Tanggal Lahir:");
            gets(tanggal_lahir_in);
            // Menghitung Umur
            strcpy(tahun_lahir_subjek_str,"\0");
            strcpy(tahun_lahir_subjek_str,(tanggal_lahir_in + 4));
            tahun_lahir_subjek_int = atoi(tahun_lahir_subjek_str);
            umur_in = tahun_sekarang_int - tahun_lahir_subjek_int;
            // Input Gender
            printf("\nMasukan Jenis Kelamin:");
            gets(gender_in);
            // Input Golongan Darah
            printf("\nMasukan Golongan Darah:");
            gets(b_type_in);
            // Input Status
            printf("\nMasukan Status:");
            gets(status_in);
            // Input Pekerjaan
            printf("\nMasukan Pekerjaan:");
            gets(pekerjaan_in);
            push_newdata(&last, nik_in, nama_lengkap_in, tempat_lahir_in, tanggal_lahir_in, umur_in, gender_in, b_type_in, status_in, pekerjaan_in);
            printf("Penambahan data berhasil dilakukan!");
        }
        else if (user_option == 2){
            printf("Masukkan NIK data yang ingin diupdate:");
            scanf("%ld", &nik_up);
            update_menu();
            scanf("%d", &feat_up);
            update_data(last, nik_up, feat_up, tahun_sekarang_int);
        }
        else if (user_option == 3){
            printf("Masukkan NIK data yang ingin dihapus:");
            scanf("%ld", &nik_up);
            pop_data(last, nik_up);
        }
        else if (user_option == 4){
            printf("Masukkan nama file external:");
            gets(filename);
            gets(filename);
            fp = fopen(filename, "r+");
            parse_external(fp, &last);
        }
        else if (user_option == 5){
            search_menu();
            scanf("%d", &feat_up);
            search_data(last, feat_up);
        }
        else if (user_option == 6){
            sort_menu();
            scanf("%d", &sort_up);
            sort_trend_menu ();
            scanf("%d", &sort_trend);
            if (sort_trend == 1){
                bubbleSort_a(last->next, sort_up);
            }
            else{
                bubbleSort_d(last->next, sort_up);
            }
        }
        else if(user_option == 7){
            printList(last->next);
        }
        else if(user_option == 8){
            fp = fopen("updated.csv", "w+");
            printFile(last, fp);
            fclose(fp);
        }
        else if(user_option == 9){
           exit_program = 1;
        }
        else {
            printf("Silahkan pilih opsi yang benar!");
        }
    }
    return 0;
}
