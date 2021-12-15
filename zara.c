#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

void create_data();
void show_data();
void update_data();
void delete_data();
void search_data();

int  data_total_mhs, data,pilih;
char nim[50], data_nim['0'][50], data_nama['0'][50], data_kelas['0'][50], data_dosen['0'][50];
bool duplicate, detect;


int main(){

        menu:
		system("cls");
		printf("Sistem Pendataan Akun I-Lab Infotech\n\n");
		printf(("====== Pilihan Menu ===============\n"));
		printf("\n[1]. Create Data");
		printf("\n[2]. Show Data");
		printf("\n[3]. Update Data");
		printf("\n[4]. Delete Data");
		printf("\n[5]. Search Data");	
		printf("\n[6]. Exit");
		printf("\n\nInput Pilihan Nomor Menu : ");
		scanf("%d", &pilih);
		
		switch(pilih){
			case 1:
                create_data();
                printf(" Tekan enter untuk kembali ke menu...");
                getch(); goto menu;
				break;
			
            case 2:
                show_data();
                printf(" Tekan enter untuk kembali ke menu...");
                getch(); goto menu;
				break;
			
            case 3:
                update_data();
                printf(" Tekan enter untuk kembali ke menu...");
                getch(); goto menu;
				break;	
			
            case 4:
                delete_data();
                printf(" Tekan enter untuk kembali ke menu...");
                getch(); goto menu;
				break;
			
            case 5:
                search_data();
                printf(" Tekan enter untuk kembali ke menu...");
                getch(); goto menu;
				break;
			
            case 6:
                return(0);
			    break;
            
			default:
                printf("\nMohon Maaf Pilihan Anda Salah !");
				getch(); goto menu;
		}
}

void create_data(){

        system("cls");
        printf(" === Create Data ===\n");
        printf("\n Input NIM Praktikan\t\t\t: "); scanf(" %[^\n]s" , nim);
        duplicate = false;
        for(int i = 0; i < data_total_mhs; i++){
            if(strcmp(data_nim[i], nim) == 0){
                duplicate = true;
            }
        }
        if (strlen(nim) == 10){
            if(duplicate == false){
                printf("\n Input Nama Praktikan\t\t\t: "); 
				scanf(" %[^\n]s", &data_nama[data_total_mhs]);
                printf("\n Input Kelas Pemrograman Dasar\t\t: "); 
				scanf(" %[^\n]s" , &data_kelas[data_total_mhs]);
                printf("\n Input Nama Dosen Pengampu\t\t: "); 
				scanf(" %[^\n]s" , &data_dosen[data_total_mhs]);
                strcpy(data_nim[data_total_mhs], nim); data_total_mhs++;
                printf("\n\n Data Berhasil di Tambah.\n");
            } else {
                printf("\n\n Inputan NIM Terdeteksi Duplikat.\n");
            }
        } else {
            printf("\n\n Inputan NIM harus 10 karakter.\n");
        }
	
}

void show_data () {
	
	system("cls");
        printf("\n === data Data ===\n\n");
        if( data_total_mhs >= 1){
            for(data = 0; data < data_total_mhs; data++){
                printf(" == %d ==", data + 1);
                printf("\n\n NIM Praktikan\t\t\t: %s", data_nim[data]);
                printf("\n\n Nama Praktikan\t\t\t: %s", data_nama[data]);
                printf("\n\n Kelas Pemrograman Dasar\t: %s", data_kelas[data]);
                printf("\n\n Dosen Pengampu\t\t\t: %s", data_dosen[data]);
                printf("\n\n");
            }
        } else {
            printf("\n\n !!! Data Tidak Ditemukan !!!\n");
        }
}

void update_data() {
	
	system("cls");
        printf(" === Update Data ===\n\n");
        printf(" Masukkan NIM Praktikan yang Ingin di Edit Data nya : "); scanf("%s",nim);
        data=0; detect = false;
        while(data < data_total_mhs && detect == false){
            if(strcmp(nim,data_nim[data]) == 0){
                detect = true;
            }   data++;
        }
        if(detect == false){
            printf("\n\n Data yang akan di update tidak tersedia\n");
        } else {
            data--;
            printf("\n Nama Baru\t\t\t: "); 
			scanf(" %[^\n]s", data_nama[data]);
            printf("\n Kelas Baru\t\t\t: "); 
			scanf(" %[^\n]s", data_kelas[data]);
            printf("\n Dosen Pengampu Baru\t\t: "); 
			scanf(" %[^\n]s", data_dosen[data]);
            printf("\n\n Data Berhasil di Edit.\n");
        }
}

void delete_data() {
	
	system("cls");
        printf(" === Delete Data ===\n\n");
        printf(" Masukkan NIM Praktikan yang Ingin di Delete Data nya : "); scanf("%s",nim);
        detect = false; data = 0;
        while(data < data_total_mhs && detect == false){
            if(strcmp(nim,data_nim[data]) == 0){
                detect = true;
            }   data++;
        }
        if(detect == false){
            printf("\n\n Data Tidak Di Temukan\n");
        } else {
            data--;
            for(data = data; data <= data_total_mhs; data++){
                strcpy(data_nim[data], data_nim[data+1]);
                strcpy(data_nama[data],data_nama[data+1]);
                strcpy(data_kelas[data],data_kelas[data+1]);
                strcpy(data_dosen[data],data_dosen[data+1]);
            }
            data--; strcpy(data_nim[data],""); data_total_mhs--;
            printf("\n\n Data Berhasil di Hapus\n");
        }
}

void search_data() {
	system("cls");
        printf(" === Search Data ===\n\n");
        printf(" Masukkan NIM Praktikan : "); scanf("%s", nim);
        detect = false; data = 0;
        while(data < data_total_mhs && detect == false){
            if(strcmp(nim,data_nim[data]) == 0){
                detect = true;
            }   data++;
        }
        if(detect == false){
            printf("\n\n Data Tidak di Temukan.\n");
        } else {
            data--;
            printf("\n Nama Praktikan\t\t\t: %s", data_nama[data]);
            printf("\n\n Kelas Pemrograman Dasar\t: %s", data_kelas[data]);
            printf("\n\n Dosen Pengampu\t\t\t: %s", data_dosen[data]);
            printf("\n\n");
        }
}
