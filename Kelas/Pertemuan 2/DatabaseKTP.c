#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct date_t {
    int day, month, year;
} date;

typedef struct InfoDataKTP {
    char NIK[20], name[100], tempatLahir[20], address[100], work[20];
    date birthday;
    int gender, religion, nationality;
} infoDataKTP;

char Nationality[2][4] = { "WNI", "WNA" };
char Gender[2][10] = { "Perempuan", "Laki-laki" };

void DisplayData(infoDataKTP Data_KTP){
	printf("NIK: %s\n", Data_KTP.NIK);
	printf("Nama: %s\n", Data_KTP.name);
	printf("Tempat Lahir: %s\n", Data_KTP.tempatLahir);
	printf("Tanggal Lahir: %d - %d - %d\n", Data_KTP.birthday.day, Data_KTP.birthday.month, Data_KTP.birthday.year);
	printf("Alamat: %s\n", Data_KTP.address);
	printf("Jenis Kelamin: %s\n", Gender[Data_KTP.gender]);
	printf("Kewarganegaraan: %s\n", Nationality[Data_KTP.nationality]);
}

void LoadData(){
    system("cls");
    FILE *databaseKTP;
    databaseKTP = fopen("database.dat", "ab+");

    if(databaseKTP == NULL){
        printf("Maaf, file yang Anda buka tidak dapat ditemukan.\n");
        fclose(databaseKTP);
    } else {
    	int ketemu = 0, idData = 1;
    	infoDataKTP dataKTP;
		
		printf("================ Database KTP ================\n\n");
        while(!feof(databaseKTP)){ 
            if(fread(&dataKTP, sizeof(infoDataKTP), 1, databaseKTP)){
                printf("Data ke-%d", idData++);
				printf("==============================================\n");
				DisplayData(dataKTP);
				printf("==============================================\n");
                ketemu = 1;
            }   
        }
        if (ketemu == 0){
        	printf("Belum ada data yang dimasukkan!\n");
		}
		char response = 'y';
		do{
        	printf("Apakah Anda ingin keluar dari menu Lihat Data (y/n)? ");
			scanf("\n%c", &response);
		} while(response == 'n');
		system("cls");
        printf("Anda telah keluar dari menu Lihat Data, kembali ke menu utama...\n\n");
        fclose(databaseKTP);
    }
}

infoDataKTP GetData(){
	infoDataKTP dataKTP;
    printf("================ Input Data KTP ================\n");
    printf("NIK (16 digit): ");
    scanf("%s", dataKTP.NIK);
    printf("Nama: ");
    scanf("\n%[^\n]s", dataKTP.name);
    printf("Tempat Lahir: ");
    scanf("\n%[^\n]s", dataKTP.tempatLahir);
    printf("Tanggal Lahir (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &dataKTP.birthday.day, &dataKTP.birthday.month, &dataKTP.birthday.year);
    printf("Alamat: ");
    scanf("\n%[^\n]s", dataKTP.address);
    printf("Jenis Kelamin:\n0. Perempuan\n1. Laki-laki\n\nSilakan pilih jenis kelamin Anda: ");
    scanf("%d", &dataKTP.gender);
    printf("Agama:\n0. Islam\n1. Kristen\n2. Katolik\n3. Hindu\n4. Buddha\n5. Konghucu\n\nSilakan pilih agama Anda: ");
    scanf("%d", &dataKTP.religion);
    printf("Kewarganegaraan:\n0. WNI\n1. WNA\n\nSilakan pilih kewarganegaraan Anda: ");
    scanf("%d", &dataKTP.nationality);
	return dataKTP;
}

void InsertData(infoDataKTP dataKTP){
	long long p = atoll(dataKTP.NIK);
	fseek(databaseKTP, (p - 1) * sizeof(infoDataKTP), SEEK_SET);
	fwrite(&dataKTP, sizeof(infoDataKTP), 1, databaseKTP);
	printf("Data berhasil ditambahkan!\n");
}

void AddData(){
    system("cls");
    FILE *databaseKTP;
    databaseKTP = fopen("database.dat", "ab+");

    if(databaseKTP == NULL){
        printf("Maaf, file yang Anda buka tidak dapat ditemukan.\n");
        fclose(databaseKTP);
    } else {
        char response = 'n';
        do {    	
	        infoDataKTP dataKTP = GetData();
	        
            system("cls");
            printf("Rincian data KTP yang Anda masukkan:\n");
            DisplayData(dataKTP);
            
            printf("Apakah data yang Anda masukkan sudah benar (y/n)? ");
            scanf("\n%c", &response);
            if(response == 'y'){
                InsertData(dataKTP);
			} 
	        
            printf("\nApakah Anda ingin memasukkan data KTP lagi (y/n) ? ");
            scanf("\n%c", &response);
			system("cls");
        } while(response == 'y');
        printf("Anda telah keluar dari menu Input Data, kembali ke menu utama...\n\n");
    	fclose(databaseKTP);
    }
}

void ExitProgram(){
	system("cls");
    printf("Anda telah keluar dari aplikasi database e-KTP.\nTerima kasih telah menggunakan aplikasi ini ^_^\n");
    exit(0);
}

void ShowMenu(){
    printf("================ Database KTP ================\n");
    printf("Menu:\n");
    printf("1. Entri Data e-KTP\n");
    printf("2. Lihat Data e-KTP\n");
    printf("3. Exit\n");
    printf("==============================================\n");
}

int main(){
    while (1){
        ShowMenu();
        printf("Silakan pilih menu yang Anda inginkan: ");
        int selectedMenuByUser;
        scanf("%d", &selectedMenuByUser);
        switch (selectedMenuByUser){
            case 1: {
                AddData();
                break;
            }
            case 2: {
                LoadData();
                break;
            }
            case 3: {
                ExitProgram();
                break;
            }
            default: {
            	system("cls");
                printf("Menu yang Anda pilih tidak valid, silakan memilih menu kembali\n\n");
            }
        }
    }
    return 0;
}
