#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include <mmsystem.h>

typedef struct{
    char nama[50];
    char bidak;
    int skor;
}PEMAIN;

char bidakKomputer;
char pemenang;
PEMAIN pemain1;
PEMAIN pemain2;
FILE *fileSkor;
char papan3x3[10];
char papan5x5[26];
char papan7x7[50];
PEMAIN riwayatPemain[10];
int jmlData;

void moveCursor(int x, int y); // untuk memindahkan posisi kursor berdasarkan koordinat kartesius
void printBanner();
void loading();
void printPembuka();
int printPanah(int posisiMenuPertama, int posisiMenuTerakhir); // berfungsi untuk mengontrol panah
int pilihMenuUtama();
int pilihLawan();
int pilihLevel();
int pilihUkuranPapan();
void kredit();
void tutorGame();
void inputNama();
void pilihBidak();
void setColor(char isiKotak);
void resetColor();
void resetPapan(int banyakIndeksPapan, char papan[banyakIndeksPapan]);
char cekMenang(int banyakIndeksPapan, char papan[banyakIndeksPapan]);
void printPapan(int banyakIndeksPapan, char papan[banyakIndeksPapan]);
void giliranPemain(int banyakIndeksPapan, char papan[banyakIndeksPapan], PEMAIN *pemain);
void printPemenang();
void printSkor();
void saveSkor();
void mainPapan(int banyakIndeksPapan, char papan[banyakIndeksPapan], PEMAIN *pemain, PEMAIN *pemain2);
char nanyaMainLagi();
void inisialisasi();
void readPeringkat();
void sortPeringkat();
void printPeringkat();
void lihatPeringkat();
void inputNamaKomputer();
void pilihBidakKomputer();
void giliranKomputerPemula(int banyakIndeksPapan, char papan[banyakIndeksPapan]);
void mainPapanKomputerPemula(int banyakIndeksPapan, char papan[banyakIndeksPapan], PEMAIN *pemain);
void bersihkanLayar();
void bersihkanLayarTertentu();