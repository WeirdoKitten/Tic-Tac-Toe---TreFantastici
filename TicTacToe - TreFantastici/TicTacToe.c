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

void printBanner() 
{
    printf("    _______ _ ______   _______ ______ ______   _______ ______ ______\n");
    printf("   |__   __| | _____| |__   __|  __  |  ____| |__   __|  __  |  ____|\n");
    printf("      | |  | | |         | |  | |__| | |         | |  | |  | |  |___ \n");
    printf("      | |  | | |         | |  |  __  | |         | |  | |  | |   ___| \n");
    printf("      | |  | | |____     | |  | |  | | |____     | |  | |__| |  |___    \n");
    printf("      |_|  |_|______|    |_|  |_|  |_|______|    |_|  |______|______|  \n\n");
}

void printSkor()
{
    if (pemain2.bidak != 'N') // != 'N' berarti pemain 2 telah mempunyai bidak, sehingga sudah pasti pemain 1 melawan pemain 2
    {
        printf("Skor %s: %d\n", pemain1.nama, pemain1.skor);
        printf("Skor %s: %d\n\n", pemain2.nama, pemain2.skor);
    }
    else if (bidakKomputer != 'N') // != 'N' berarti komputer telah mempunyai bidak, sehingga sudah pasti pemain 1 melawan komputer
    {
        printf("Skor : %d\n\n", pemain1.skor);
    }
}

void printPenutup()
{
    printf("Permainan Telah Berakhir !\n\n");
    printf("      tekan tombol apapun untuk kembali ke menu utama");
    getch();
    system("cls");
}

void maaf()
{
    printBanner();
    printf("\t ______________________________________________________ \n");
    printf("\t|                                                      |\n");
    printf("\t|                   Segera Rilis !!                    |\n");
    printf("\t|______________________________________________________|\n");
    printf("\t|                                                      |\n");
    printf("\t|                                                      |\n");
    printf("\t|           maaf mode ini belum tersedia :(            |\n");
    printf("\t|       kamu masih bisa memainkan level pemula         |\n");
    printf("\t|                                                      |\n");
    printf("\t|    tekan tombol apapun untuk kembali ke menu utama   |\n");
    printf("\t|                                                      |\n");
    printf("\t|______________________________________________________|\n");
    getch();
    system("cls");
}

void kredit()
{
    printBanner();
    printf("\t ______________________________________________________ \n");
    printf("\t|                                                      |\n");
    printf("\t|                     Tentang Kami                     |\n");
    printf("\t|______________________________________________________|\n");
    printf("\t|                                                      |\n");
    printf("\t|   231524007 | Farrel Zandra         | @farrel29__    |\n");
    printf("\t|   231524020 | Nobby Dharma Khaulid  | @nobbykhaulid  |\n");
    printf("\t|   231524026 | Satria Permata Sejati | @WeirdoKitten  |\n");
    printf("\t|                                                      |\n");
    printf("\t|    tekan tombol apapun untuk kembali ke menu utama   |\n");
    printf("\t|                                                      |\n");
    printf("\t|______________________________________________________|\n");
    getch();
    system("cls");
}

void printPembuka()
{
    printBanner();
    printf("\t     Selamat Datang Di TicTacToe !! - TriFantastici\n\n");
    printf("\t    tips : sebelum main, lihat tutorialnya dulu ya :)\n\n");
    printf("\t            Loading...\n\t            ");
    for (int i = 0; i < 5; i++)
    {
        printf("%c%c%c%c%c%c",219 , 219, 219, 219, 219, 219, 219);
        sleep(1);
    }
    printf("\n\n\t         tekan tombol apapun untuk lanjut main\n");
    getch();
    system("cls");
}

void tutorGame() 
{
    printf("\t\t\tPertama kali memainkan permainan ini? Berikut penjelasan permainan!\n");
    printf("\t\t ______________________________________________________________________________ \n");
    printf("\t\t|                                                                              |\n");
    printf("\t\t|                       TUTOR SEBELUM MEMASUKI PERMAINAN                       |\n");
    printf("\t\t|______________________________________________________________________________|\n");
    printf("\t\t|                                                                              |\n");
    printf("\t\t|1. Pilih opsi Mulai Permainan.                                                |\n");
    printf("\t\t|2. Pilih lawan yang anda inginkan.                                            |\n");
    printf("\t\t|3. Pilih tingkat kesulitan yang anda inginkan                                 |\n");
    printf("\t\t|   (apabila memilih lawan komputer).                                          |\n");
    printf("\t\t|4. Pilih ukuran papan yang anda inginkan.                                     |\n");
    printf("\t\t|5. Inputkan nama pemain 1.                                                    |\n");
    printf("\t\t|6. Inputkan nama pemain 2 (apabila memilih lawan manusia).                    |\n");
    printf("\t\t|7. Pilih bidak dengan cara menginputkan antara X atau O sebagai pilihan       |\n");
    printf("\t\t|   bidak pemain pertama. Secara otomatis pemain kedua akan mendapatkan bidak  |\n");
    printf("\t\t|   lainnya.                                                                   |\n");
    printf("\t\t|8. Permainan dimulai!                                                         |\n");
    printf("\t\t|______________________________________________________________________________|\n\n");

    printf("\t\t ______________________________________________________________________________ \n");
    printf("\t\t|                                                                              |\n");
    printf("\t\t|                                TUTOR PERMAINAN                               |\n");
    printf("\t\t|______________________________________________________________________________|\n");
    printf("\t\t|                                                                              |\n");
    printf("\t\t|1. Ketikkan angka 1-9 yang merepresentasikan masing-masing kotak yang         |\n");
    printf("\t\t|   tersedia dan klik enter. Maka kotak kosong akan diisi dengan bidak pemain  |\n");
    printf("\t\t|   1.                                                                         |\n");
    printf("\t\t|   (apabila memilih lawan komputer).                                          |\n");
    printf("\t\t|2. Giliran Pemain selanjutnya. Jika pemain 2 adalah manusia, maka lakukan     |\n");
    printf("\t\t|   seperti langkah 1 (pastikan memilih kotak yang masih kosong. Namun jika    |\n");
    printf("\t\t|   pemain 2 adalah komputer maka kotak kosong akan otomatis terisi.           |\n");
    printf("\t\t|3. Ulangi langkah 1 dan 2 hingga sistem memberitahukan status permainan       |\n");
    printf("\t\t|   seperti, menang, kalah, ataupun seri.                                      |\n");
    printf("\t\t|4. Permainan selesai, anda dapat mengulangi permainan ataupun menyudahinya.   |\n");
    printf("\t\t|______________________________________________________________________________|\n");
    printf("\n\n\t\t\t\t\ttekan tombol apapun untuk kembali\n");
    getch();
    system("cls");
}

void sortPeringkat()
{
    PEMAIN temp;
    int i, j;
    for (i = 1; i < jmlData; i++)
    {
        temp = riwayatPemain[i];
        j = i - 1;
        while (j >= 0 && riwayatPemain[j].skor < temp.skor) 
        {
            riwayatPemain[j + 1] = riwayatPemain[j];
            j = j - 1;
        }
        riwayatPemain[j + 1] = temp;
    }
}

void readPeringkat()
{
    fileSkor = fopen("dataSkor.txt", "r");
    int i = 0;
    while (!feof(fileSkor))
    {
        fscanf(fileSkor,"%[^#]#%c#%d\n", riwayatPemain[i].nama, &riwayatPemain[i].bidak, &riwayatPemain[i].skor);
        fflush(stdin);
        i++;
    }
    fclose(fileSkor);
    jmlData = i;
}

void printPeringkat()
{
    printBanner();
    printf("\t\t\t    Papan Peringkat\n\n");
    printf("\t   %-21s %-18s %s\n", "NamaPemain", "Bidak", "SkorTertinggi");
    for (int i = 0; i < jmlData; i++)
    {
        printf("\t   %-23s %-22c %d\n", riwayatPemain[i].nama, riwayatPemain[i].bidak, riwayatPemain[i].skor);
    }
    printf("\n\n\t\t   tekan tombol apapun untuk kembali");
    getch();
    system("cls");
}

void lihatPeringkat()
{
    readPeringkat();
    sortPeringkat();
    printPeringkat();
}

void printPanah(int posisiMenu, int posisiPanah) // berfungsi untuk mengontrol panah
{
    if (posisiMenu == posisiPanah)
    {
        printf("\t|            ---> "); // jika true maka panah akan diprint
    }
    else
    {
        printf("\t|                 "); // jika false maka hanya akan ngeprint spasi
    }  
}

int pilihKomputer()
{
    int posisiPanah = 1;
    int tombolDitekan = 0;
    while(tombolDitekan != 13)
    {
        printBanner();
        printf("\t __________________________________________________ \n");
        printf("\t|                                                  |\n");
        printf("\t|               Pilih Level Komputer               |\n");
        printf("\t|__________________________________________________|\n");
        printf("\t|                                                  |\n");
        printf("\t|                                                  |\n");
        printPanah(1,posisiPanah); printf("Pemula                           |\n");
        printPanah(2,posisiPanah); printf("Menengah                         |\n");
        printPanah(3,posisiPanah); printf("Sepuh TicTacToe                  |\n");
        printf("\t|                                                  |\n");
        printf("\t|                                                  |\n");
        printf("\t|__________________________________________________|\n");

        tombolDitekan = getch();
        if (tombolDitekan == 80 && posisiPanah < 3) // 80 adalah kode ascii tombol panah bawah
        {
            posisiPanah++;
        }
        else if (tombolDitekan == 72 && posisiPanah > 1) // 72 adalah kode ascii tombol panah atas
        {
            posisiPanah--;
        }
        else
        {
            posisiPanah = posisiPanah;
        }
        system("cls");
    }
    return posisiPanah;
}


int pilihUkuranPapan()
{
    int posisiPanah = 1;
    int tombolDitekan = 0;
    while(tombolDitekan != 13)
    {
        printBanner();
        printf("\t __________________________________________________ \n");
        printf("\t|                                                  |\n");
        printf("\t|                Pilih Ukuran Papan                |\n");
        printf("\t|__________________________________________________|\n");
        printf("\t|                                                  |\n");
        printf("\t|                                                  |\n");
        printPanah(1,posisiPanah); printf("   Papan 3x3                     |\n");
        printPanah(2,posisiPanah); printf("   Papan 5x5                     |\n");
        printPanah(3,posisiPanah); printf("   Papan 7x7                     |\n");
        printf("\t|                                                  |\n");
        printf("\t|                                                  |\n");
        printf("\t|__________________________________________________|\n");

        tombolDitekan = getch();
        if (tombolDitekan == 80 && posisiPanah < 3) // 80 adalah kode ascii tombol panah bawah
        {
            posisiPanah++;
        }
        else if (tombolDitekan == 72 && posisiPanah > 1) // 72 adalah kode ascii tombol panah atas
        {
            posisiPanah--;
        }
        else
        {
            posisiPanah = posisiPanah;
        }
        system("cls");
    }
    return posisiPanah;
}

int pilihLawan()
{
    int posisiPanah = 1;
    int tombolDitekan = 0;
    while(tombolDitekan != 13)
    {
        printBanner();
        printf("\t ______________________________________________________ \n");
        printf("\t|                                                      |\n");
        printf("\t|                  Pilih Lawan Kamu                    |\n");
        printf("\t|______________________________________________________|\n");
        printf("\t|                                                      |\n");
        printf("\t|                                                      |\n");
        printPanah(1,posisiPanah); printf(" Pemain VS Pemain                    |\n");
        printPanah(2,posisiPanah); printf(" Pemain VS Komputer                  |\n");
        printf("\t|                                                      |\n");
        printf("\t|                                                      |\n");
        printf("\t|                                                      |\n");
        printf("\t|______________________________________________________|\n");

        tombolDitekan = getch();
        if (tombolDitekan == 80 && posisiPanah < 2)
        {
            posisiPanah++;
        }
        else if (tombolDitekan == 72 && posisiPanah > 1)
        {
            posisiPanah--;
        }
        else
        {
            posisiPanah = posisiPanah;
        }
        system("cls");
    }
    return posisiPanah;
}

int pilihMenuUtama()
{
    int posisiPanah = 1;
    int tombolDitekan = 0;
    while(tombolDitekan != 13)
    {
        printBanner();
        printf("\t ______________________________________________________ \n");
        printf("\t|                                                      |\n");
        printf("\t|                     Menu Utama                       |\n");
        printf("\t|______________________________________________________|\n");
        printf("\t|                                                      |\n");
        printPanah(1,posisiPanah); printf(" Mulai Permainan                     |\n");
        printPanah(2,posisiPanah); printf(" Lihat Papan Peringkat               |\n");
        printPanah(3,posisiPanah); printf(" Tutorial Permainan                  |\n");
        printPanah(4,posisiPanah); printf(" Kredit                              |\n");
        printPanah(5,posisiPanah); printf(" Keluar                              |\n");
        printf("\t|                                                      |\n");
        printf("\t|______________________________________________________|\n");

        tombolDitekan = getch();
        if (tombolDitekan == 80 && posisiPanah < 5) // 80 adalah kode ascii tombol panah bawah
        {
            posisiPanah++;
        }
        else if (tombolDitekan == 72 && posisiPanah > 1) // 72 adalah kode ascii tombol panah atas
        {
            posisiPanah--;
        }
        else
        {
            posisiPanah = posisiPanah;
        }
        system("cls");
    }
    return posisiPanah;
}

void saveSkor()
{
    fileSkor = fopen("dataSkor.txt", "a");
    fprintf(fileSkor,"%s#%c#%d\n", pemain1.nama, pemain1.bidak, pemain1.skor);
    fclose(fileSkor);
    jmlData++;
}

void inisialisasi()
{
    bidakKomputer = 'N'; // N artinya belum memilih bidak
    pemain1.bidak = 'N';
    pemain2.bidak = 'N';
    pemain1.skor = 0;
    pemain2.skor = 0;
}

void inputNama(PEMAIN *pemain, PEMAIN *pemain2)
{
    fflush(stdin); printf("\n\n\t\tinputkan nama pemain 1 :"); gets((*pemain).nama);
    fflush(stdin); printf("\t\tinputkan nama pemain 2 :"); gets((*pemain2).nama);
}

void inputNamaKomputer(PEMAIN *pemain)
{
    fflush(stdin); printf("\n\n\t\tinputkan nama pemain 1 :"); gets((*pemain).nama);
}

void pilihBidakKomputer(PEMAIN *pemain)
{
    printf("      pilih bidak untuk %s (hanya input X atau O): ", (*pemain).nama);
    scanf(" %c", &(*pemain).bidak);
    (*pemain).bidak = toupper((*pemain).bidak);
    while ((*pemain).bidak != 'X' && (*pemain).bidak != 'O') 
    {
        printf("inputkan yang valid (X atau O): ");
        scanf(" %c", &(*pemain).bidak);
        (*pemain).bidak = toupper((*pemain).bidak);
    }
    if ((*pemain).bidak == 'X')
    {
        bidakKomputer = 'O';
    }
    else if ((*pemain).bidak == 'O')
    {
        bidakKomputer = 'X';
    }
}

void giliranKomputerPemula(int banyakIndeksPapan, char papan[banyakIndeksPapan])
{
    int langkahSah = false;
    srand(time(0)); // angka random dimulai dari 0
    int nilaiRandom;
    int langkahKomputer;
    while (langkahSah == false)
    {
        nilaiRandom = rand() % 3;
        if (nilaiRandom == 0) 
        {
            langkahKomputer = '1' + rand() % 9; // menghasilkan karakter 1-9
        } 
        else if (nilaiRandom == 1)
        {
            langkahKomputer = 'a' + rand() % 26; // menghasilkan karakter a-z
        } 
        else 
        {
            langkahKomputer = 'A' + rand() % 14; // menghasilkan karakter A - N
        }
        for (int i = 1; i < banyakIndeksPapan; i++)
        {
            if (langkahKomputer == '0'+ i && papan[i] == '0'+ i)
            {
                papan[i] = bidakKomputer;
                langkahSah = true;
            }
            else if (langkahKomputer == 'a' + i - 10 && papan[i] == 'a' + i - 10)
            {
                papan[i] = bidakKomputer;
                langkahSah = true;
            }
            else if (langkahKomputer == 'A' + i - 36 && papan[i] == 'A' + i - 36)
            {
                papan[i] = bidakKomputer;
                langkahSah = true;
            }
        }
    } 
}

void pilihBidak(PEMAIN *pemain, PEMAIN *pemain2) 
{
    printf("      pilih bidak untuk %s (hanya input X atau O): ", (*pemain).nama);
    scanf(" %c", &(*pemain).bidak);
    (*pemain).bidak = toupper((*pemain).bidak);
    while ((*pemain).bidak != 'X' && (*pemain).bidak != 'O') 
    {
        printf("inputkan yang valid (X atau O): ");
        scanf(" %c", &(*pemain).bidak);
        (*pemain).bidak = toupper((*pemain).bidak);
    }
    if ((*pemain).bidak == 'X')
    {
        (*pemain2).bidak = 'O';
    }
    else if ((*pemain).bidak == 'O')
    {
        (*pemain2).bidak = 'X';
    }
}

void resetPapan(int banyakIndeksPapan, char papan[banyakIndeksPapan])
{
    if (banyakIndeksPapan == 10)
    {
        for (int i = 1; i < banyakIndeksPapan; i++)
        {
            papan[i] = '0' + i;
        }
    }
    else if (banyakIndeksPapan == 26)
    {
        for (int i = 1; i < banyakIndeksPapan; i++)
        {
            if (i < 10)
            {
                papan[i] = '0' + i;
            }
            else
            {
                papan[i] = 'a' + i - 10;
            }
        }
    }
    else if (banyakIndeksPapan == 50)
    {
        for (int i = 1; i < banyakIndeksPapan; i++)
        {
            if (i < 10)
            {
                papan[i] = '0' + i;
            }
            else if(i >= 10 && i < 36)
            {
                papan[i] = 'a' + i - 10;
            }
            else
            {
                papan[i] = 'A' + i - 36;
            }
        }
    }
}

void giliranPemain(int banyakIndeksPapan, char papan[banyakIndeksPapan], PEMAIN *pemain)
{
    int langkahSah = false;
    char pilihIndeks;
    printf("Giliran %s (%c)\n", (*pemain).nama, (*pemain).bidak);
    while (langkahSah == false)
    {
        printf("inputkan pilihan kamu :"); scanf(" %c", &pilihIndeks); fflush(stdin);
        for (int i = 1; i < banyakIndeksPapan; i++)
        {
            if (pilihIndeks == '0'+ i && papan[i] == '0'+ i)
            {
                papan[i] = (*pemain).bidak;
                langkahSah = true;
            }
            else if (pilihIndeks == 'a' + i - 10 && papan[i] == 'a' + i - 10)
            {
                papan[i] = (*pemain).bidak;
                langkahSah = true;
            }
            else if (pilihIndeks == 'A' + i - 36 && papan[i] == 'A' + i - 36)
            {
                papan[i] = (*pemain).bidak;
                langkahSah = true;
            }
        }
        printf("langkah kamu tidak valid atau kotak sudah diisi, coba lagi!\n");
    } 
}

void resetColor() 
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Mengembalikan warna ke default
}

void setColor(char isiKotak) 
{
    if (isiKotak == 'X') {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);  // Kode warna biru
    } else if (isiKotak == 'O') {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // Kode warna merah
    } else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Kode warna putih (default)
    }
    printf(" %c ", isiKotak);
    resetColor();
}

void printPapan(int banyakIndeksPapan, char papan[banyakIndeksPapan])
{
    system("cls");
    printf("\t\t \n");
    if (banyakIndeksPapan == 10)
    {
        printf("\t\t ___ ___ ___ \n");
        printf("\t\t|   |   |   |\n");
        for (int i = 0; i < 3; ++i) 
        {
            printf("\t\t|");

            for (int j = 0; j < 3; ++j) 
            {
                int index = i * 3 + j + 1;
                setColor(papan[index]);
                printf("|");
            }
            printf("\n");
            if (i < 2) 
            {
                printf("\t\t|---|---|---|\n");
            }
        }
        printf("\t\t|___|___|___|\n");
    }
    else if (banyakIndeksPapan == 26)
    {
        printf("\t\t ___ ___ ___ ___ ___ \n");
        printf("\t\t|   |   |   |   |   |\n");
        for (int i = 0; i < 5; ++i) 
        {
            printf("\t\t|");

            for (int j = 0; j < 5; ++j) 
            {
                int index = i * 5 + j + 1;
                setColor(papan[index]);
                printf("|");
            }
            printf("\n");
            if (i < 4) 
            {
                printf("\t\t|---|---|---|---|---|\n");
            }
        }
        printf("\t\t|___|___|___|___|___|\n\n");
    }
    else if (banyakIndeksPapan == 50)
    {
        printf("\t\t ___ ___ ___ ___ ___ ___ ___\n");
        printf("\t\t|   |   |   |   |   |   |   |\n");
        for (int i = 0; i < 7; ++i) 
        {
            printf("\t\t|");

            for (int j = 0; j < 7; ++j) 
            {
                int index = i * 7 + j + 1;
                setColor(papan[index]);
                printf("|");
            }
            printf("\n");
            if (i < 6) 
            {
                printf("\t\t|---|---|---|---|---|---|---|\n");
            }
        }
        printf("\t\t|___|___|___|___|___|___|___|\n\n");
    }
    printSkor();
}

char cekMenang(int banyakIndeksPapan, char papan[banyakIndeksPapan])
{
    if (banyakIndeksPapan == 10)
    {
        // Cek baris
        for (int i = 1; i <= 7; i += 3)
        {
            if (papan[i] == papan[i + 1] && papan[i + 1] == papan[i + 2])
            {
                return papan[i];
            }
        }

        // Cek kolom
        for (int i = 1; i <= 3; ++i)
        {
            if (papan[i] == papan[i + 3] && papan[i + 3] == papan[i + 6])
            {
                return papan[i];
            }
        }

        // Cek diagonal
        if (papan[1] == papan[5] && papan[5] == papan[9])
        {
            return papan[1];
        }
        else if (papan[3] == papan[5] && papan[5] == papan[7])
        {
            return papan[3];
        }
    }
    else if (banyakIndeksPapan == 26)
    {
        // Cek baris
        for (int i = 1; i <= 21; i += 5)
        {
            for (int j = 0; j <= 1; ++j)
            {
                if (papan[i + j] == papan[i + j + 1] && papan[i + j + 1] == papan[i + j + 2] && papan[i + j + 2] == papan[i + j + 3])
                {
                    return papan[i + j];
                }
            }
        }

        // Cek kolom
        for (int i = 1; i <= 5; ++i)
        {
            for (int j = 0; j <= 15; j += 5)
            {
                if (papan[i + j] == papan[i + j + 5] && papan[i + j + 5] == papan[i + j + 10] && papan[i + j + 10] == papan[i + j + 15])
                {
                    return papan[i + j];
                }
            }
        }

        // Cek diagonal

        if (papan[1] == papan[7] && papan[7] == papan[13] && papan[13] == papan[19])
        {
            return papan[1];
        }
        else if (papan[6] == papan[12] && papan[12] == papan[18] && papan[18] == papan[24])
        {
            return papan[6];
        }
        else if (papan[2] == papan[8] && papan[8] == papan[14] && papan[14] == papan[20])
        {
            return papan[2];
        }
        else if (papan[10] == papan[14] && papan[14] == papan[18] && papan[18] == papan[22])
        {
            return papan[10];
        }
        else if (papan[4] == papan[8] && papan[8] == papan[12] && papan[12] == papan[16])
        {
            return papan[4];
        }
        else if (papan[5] == papan[9] && papan[9] == papan[13] && papan[13] == papan[17])
        {
            return papan[5];
        }
        else if (papan[9] == papan[13] && papan[13] == papan[17] && papan[17] == papan[21])
        {
            return papan[9];
        }
        else if (papan[7] == papan[13] && papan[13] == papan[19] && papan[19] == papan[25])
        {
            return papan[7];
        } 
    }

    else if (banyakIndeksPapan == 50)
    {
        for (int i = 1; i <= 7; i++)
        {
            // baris
            if (papan[1] == papan[2] && papan[2] == papan[3] && papan[3] == papan[4] && papan[4] == papan[5])
            {
                return papan[1];
            }
            if (papan[2] == papan[3] && papan[3] == papan[4] && papan[4] == papan[5] && papan[5] == papan[6])
            {
                return papan[2];
            }
            if (papan[3] == papan[4] && papan[4] == papan[5] && papan[5] == papan[6] && papan[6] == papan[7])
            {
                return papan[3];
            }
            if (papan[8] == papan[9] && papan[9] == papan[10] && papan[10] == papan[11] && papan[11] == papan[12])
            {
                return papan[8];
            }
            if (papan[9] == papan[10] && papan[10] == papan[11] && papan[11] == papan[12] && papan[12] == papan[13])
            {
                return papan[9];
            }
            if (papan[10] == papan[11] && papan[11] == papan[12] && papan[12] == papan[13] && papan[13] == papan[14])
            {
                return papan[10];
            }
            if (papan[15] == papan[16] && papan[16] == papan[17] && papan[17] == papan[18] && papan[18] == papan[19])
            {
                return papan[15];
            }
            if (papan[16] == papan[17] && papan[17] == papan[18] && papan[18] == papan[19] && papan[19] == papan[20])
            {
                return papan[16];
            }
            if (papan[17] == papan[18] && papan[18] == papan[19] && papan[19] == papan[20] && papan[20] == papan[21])
            {
                return papan[17];
            }
            if (papan[22] == papan[23] && papan[23] == papan[24] && papan[24] == papan[25] && papan[25] == papan[26])
            {
                return papan[22];
            }
            if (papan[23] == papan[24] && papan[24] == papan[25] && papan[25] == papan[26] && papan[26] == papan[27])
            {
                return papan[23];
            }
            if (papan[24] == papan[25] && papan[25] == papan[26] && papan[26] == papan[27] && papan[27] == papan[28])
            {
                return papan[24];
            }
            if (papan[29] == papan[30] && papan[30] == papan[31] && papan[31] == papan[32] && papan[32] == papan[33])
            {
                return papan[29];
            }
            if (papan[30] == papan[31] && papan[31] == papan[32] && papan[32] == papan[33] && papan[33] == papan[34])
            {
                return papan[30];
            }
            if (papan[31] == papan[32] && papan[32] == papan[33] && papan[33] == papan[34] && papan[34] == papan[35])
            {
                return papan[31];
            }
            if (papan[36] == papan[37] && papan[37] == papan[38] && papan[38] == papan[39] && papan[39] == papan[40])
            {
                return papan[36];
            }
            if (papan[37] == papan[38] && papan[38] == papan[39] && papan[39] == papan[40] && papan[40] == papan[41])
            {
                return papan[37];
            }
            if (papan[38] == papan[39] && papan[39] == papan[40] && papan[40] == papan[41] && papan[41] == papan[42])
            {
                return papan[38];
            }
            if (papan[43] == papan[44] && papan[44] == papan[45] && papan[45] == papan[46] && papan[46] == papan[47])
            {
                return papan[43];
            }
            if (papan[44] == papan[45] && papan[45] == papan[46] && papan[46] == papan[47] && papan[47] == papan[48])
            {
                return papan[44];
            }
            if (papan[45] == papan[46] && papan[46] == papan[47] && papan[47] == papan[48] && papan[48] == papan[49])
            {
                return papan[45];
            }

            // kolom
            if (papan[i] == papan[i + 7] && papan[i + 7] == papan[i + 14] && papan[i + 14] == papan[i + 21] && papan[i + 21] == papan[i + 28])
            {
                return papan[i];
            }
        }

        /* DIAGONAL */
        //diagonal kiri ke kanan
        if (papan[1] == papan[9] && papan[9] == papan[17] && papan[17] == papan[25] && papan[25] == papan[33])
        {
            return papan[1];
        }
        else if (papan[15] == papan[23] && papan[23] == papan[31] && papan[31] == papan[39] && papan[39] == papan[47])
        {
            return papan[15];
        }
        else if (papan[8] == papan[16] && papan[16] == papan[24] && papan[24] == papan[32] && papan[32] == papan[40])
        {
            return papan[8];
        }
        else if (papan[16] == papan[24] && papan[24] == papan[32] && papan[32] == papan[40] && papan[40] == papan[48])
        {
            return papan[16];
        }
        else if (papan[9] == papan[17] && papan[17] == papan[25] && papan[25] == papan[33] && papan[33] == papan[41])
        {
            return papan[9];
        }
        else if (papan[17] == papan[25] && papan[25] == papan[33] && papan[33] == papan[41] && papan[41] == papan[49])
        {
            return papan[17];
        }
        else if (papan[2] == papan[10] && papan[10] == papan[18] && papan[18] == papan[26] && papan[26] == papan[34])
        {
            return papan[2];
        }
        else if (papan[10] == papan[18] && papan[18] == papan[26] && papan[26] == papan[34] && papan[34] == papan[42])
        {
            return papan[10];
        }
        else if (papan[3] == papan[11] && papan[11] == papan[19] && papan[19] == papan[27] && papan[27] == papan[35])
        {
            return papan[3];
        } //diagonal kanan ke kiri
        else if (papan[5] == papan[11] && papan[11] == papan[17] && papan[17] == papan[23] && papan[23] == papan[29])
        {
            return papan[5];
        }
        else if (papan[6] == papan[12] && papan[12] == papan[18] && papan[18] == papan[24] && papan[24] == papan[30])
        {
            return papan[6];
        }
        else if (papan[12] == papan[18] && papan[18] == papan[24] && papan[24] == papan[30] && papan[30] == papan[36])
        {
            return papan[12];
        }
        else if (papan[7] == papan[13] && papan[13] == papan[19] && papan[19] == papan[25] && papan[25] == papan[31])
        {
            return papan[7];
        }
        else if (papan[13] == papan[19] && papan[19] == papan[25] && papan[25] == papan[31] && papan[31] == papan[37])
        {
            return papan[13];
        }
        else if (papan[19] == papan[25] && papan[25] == papan[31] && papan[31] == papan[37] && papan[37] == papan[43])
        {
            return papan[19];
        }
        else if (papan[14] == papan[20] && papan[20] == papan[26] && papan[26] == papan[32] && papan[32] == papan[38])
        {
            return papan[14];
        }
        else if (papan[20] == papan[26] && papan[26] == papan[32] && papan[32] == papan[38] && papan[38] == papan[44])
        {
            return papan[20];
        }
        else if (papan[21] == papan[27] && papan[27] == papan[33] && papan[33] == papan[39] && papan[39] == papan[45])
        {
            return papan[21];
        }
    }
    return '\0';
}

void printPemenang()
{
    if (pemenang == pemain1.bidak)
    {
        printf("selamat %s, kamu menang dengan bidak %c\n", pemain1.nama, pemain1.bidak);
        pemain1.skor++;
    }
    else if (pemenang == pemain2.bidak)
    {
        printf("selamat %s, kamu menang dengan bidak %c\n", pemain2.nama, pemain2.bidak);
        pemain2.skor++;
    }
    else if (pemenang == bidakKomputer)
    {
        if (pemain1.skor > 0)
        {
            saveSkor();
        }
        printf("yah kamu kalah :(\n");
        pemain1.skor = 0;
    }
    else if (pemenang == '\0')
    {
        printf("tidak ada kotak tersisa, permainan DRAW !!\n");
    }
}

char nanyaMainLagi()
{
    char inputUser;
    printf("ingin bermain lagi ? (Y/N)\n"); scanf(" %c", &inputUser); inputUser = toupper(inputUser);
    while (inputUser != 'Y' && inputUser != 'N')
    {
        printf("inputkan yang valid!! (hanya Y atau N)\n"); scanf(" %c", &inputUser); inputUser = toupper(inputUser);
    }
    return inputUser;
}

void mainPapan(int banyakIndeksPapan, char papan[banyakIndeksPapan], PEMAIN *pemain, PEMAIN *pemain2)
{
    char inputUser;
    inisialisasi();
    inputNama(pemain, pemain2);
    pilihBidak(pemain, pemain2);
    do
    {
        int totalLangkah = 0;
        pemenang = '\0';
        resetPapan(banyakIndeksPapan, papan);
        while (totalLangkah != banyakIndeksPapan - 1 && pemenang == '\0')
        {
            printPapan(banyakIndeksPapan, papan);
            if ((*pemain).bidak == 'X')
            {
                giliranPemain(banyakIndeksPapan, papan, pemain);
                printPapan(banyakIndeksPapan, papan);
                pemenang = cekMenang(banyakIndeksPapan, papan);
                if (pemenang !='\0')
                {
                    break;
                }
                totalLangkah++;
                if (totalLangkah == banyakIndeksPapan - 1)
                {
                    break;
                }
                giliranPemain(banyakIndeksPapan, papan, pemain2);
                printPapan(banyakIndeksPapan, papan);
                pemenang = cekMenang(banyakIndeksPapan, papan);
                totalLangkah++;
            }
            else if ((*pemain).bidak == 'O')
            {
                giliranPemain(banyakIndeksPapan, papan, pemain2);
                printPapan(banyakIndeksPapan, papan);
                pemenang = cekMenang(banyakIndeksPapan, papan);
                if (pemenang !='\0')
                {
                    break;
                }
                totalLangkah++;
                if (totalLangkah == banyakIndeksPapan - 1)
                {
                    break;
                }
                giliranPemain(banyakIndeksPapan, papan, pemain);
                printPapan(banyakIndeksPapan, papan);
                pemenang = cekMenang(banyakIndeksPapan, papan);
                totalLangkah++;
            }
        }
        printPemenang();
        inputUser = nanyaMainLagi();
    } while (inputUser == 'Y');
    printPenutup();
}

void mainPapanKomputerPemula(int banyakIndeksPapan, char papan[banyakIndeksPapan], PEMAIN *pemain)
{
    char inputUser;
    inisialisasi();
    inputNamaKomputer(pemain);
    pilihBidakKomputer(pemain);
    do
    {
        int totalLangkah = 0;
        pemenang = '\0';
        resetPapan(banyakIndeksPapan, papan);
        while (totalLangkah != banyakIndeksPapan - 1 && pemenang == '\0')
        {
            printPapan(banyakIndeksPapan, papan);
            if ((*pemain).bidak == 'X')
            {
                giliranPemain(banyakIndeksPapan, papan, pemain);
                printPapan(banyakIndeksPapan, papan);
                pemenang = cekMenang(banyakIndeksPapan, papan);
                if (pemenang !='\0')
                {
                    break;
                }
                totalLangkah++;
                if (totalLangkah == banyakIndeksPapan - 1)
                {
                    break;
                }
                giliranKomputerPemula(banyakIndeksPapan, papan);
                printPapan(banyakIndeksPapan, papan);
                pemenang = cekMenang(banyakIndeksPapan, papan);
                totalLangkah++;
            }
            else if ((*pemain).bidak == 'O')
            {
                giliranKomputerPemula(banyakIndeksPapan, papan);
                printPapan(banyakIndeksPapan, papan);
                pemenang = cekMenang(banyakIndeksPapan, papan);
                if (pemenang !='\0')
                {
                    break;
                }
                totalLangkah++;
                if (totalLangkah == banyakIndeksPapan -1)
                {
                    break;
                }
                giliranPemain(banyakIndeksPapan, papan, pemain);
                printPapan(banyakIndeksPapan, papan);
                pemenang = cekMenang(banyakIndeksPapan, papan);
                totalLangkah++;
            }
        }
        printPemenang();
        inputUser = nanyaMainLagi();
    } while (inputUser == 'Y');
    printPenutup();
    if (pemenang != bidakKomputer)
    {
        saveSkor();
    }
}

int main()
{
    system("cls");
    int pilihanMenu;
    int pilihanLawan;
    int pilihanPapan;
    int pilihanKomputer;
    printPembuka();
    while (true)
    {
        pilihanMenu = pilihMenuUtama();
        switch (pilihanMenu)
        {
        case 1 : // jika memilih 1, maka mulai permainan, diawali dengan pilih lawan kemudian pilih ukuran papan
            pilihanLawan = pilihLawan();
            if (pilihanLawan == 1) //jika memilih 1 maka akan dimainkan mode human vs human
            {
                pilihanPapan = pilihUkuranPapan();
                if (pilihanPapan == 1) // jika memilih 1 maka akan dimainkan permainan dengan papan 3x3
                {
                    mainPapan(10, papan3x3, &pemain1, &pemain2);
                }
                else if (pilihanPapan == 2) // jika memilih 2 maka akan dimainkan permainan dengan papan 5x5
                {
                    mainPapan(26, papan5x5, &pemain1, &pemain2);
                }
                else if (pilihanPapan == 3) // jika memilih 3 maka akan dimainkan permainan dengan papan 7x7
                {
                    mainPapan(50, papan7x7, &pemain1, &pemain2);
                }
                
            }
            else if (pilihanLawan == 2) //jika memilih 2 maka akan dimainkan mode human vs computer
            {
                pilihanKomputer = pilihKomputer();
                if (pilihanKomputer == 1) // jika memilih 1 maka level komputer yag dilawan adalah pemula
                {
                    pilihanPapan = pilihUkuranPapan();
                    if (pilihanPapan == 1) // jika memilih 1 maka akan dimainkan permainan dengan papan 3x3
                    {
                        mainPapanKomputerPemula(10, papan3x3, &pemain1);
                    }
                    else if (pilihanPapan == 2) // jika memilih 2 maka akan dimainkan permainan dengan papan 5x5
                    {
                        mainPapanKomputerPemula(26, papan5x5, &pemain1);
                    }
                    else if (pilihanPapan == 3) // jika memilih 3 maka akan dimainkan permainan dengan papan 7x7
                    {
                        mainPapanKomputerPemula(50, papan7x7, &pemain1);
                    }
                }
                else if (pilihanKomputer == 2) // jika memilih 2 maka level komputer yag dilawan adalah menengah
                {
                    maaf();
                }
                else if (pilihanKomputer == 3) // jika memilih 3 maka level komputer yag dilawan adalah SepuhTicTacToe
                {
                    maaf();
                }
            }
            break;
        case 2 :
            lihatPeringkat();
            break;
        case 3 :
            tutorGame();
            break;
        case 4 :
            kredit();
            break;
        case 5 :
            exit(false);
            break;
        }
    }
    return 0;
}