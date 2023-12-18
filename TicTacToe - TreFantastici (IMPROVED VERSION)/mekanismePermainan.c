#include "header.h"

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

void saveSkor()
{
    fileSkor = fopen("dataSkor.txt", "a");
    fprintf(fileSkor,"%s#%c#%d\n", pemain1.nama, pemain1.bidak, pemain1.skor);
    fclose(fileSkor);
    jmlData++;
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


void printPapan(int banyakIndeksPapan, char papan[banyakIndeksPapan])
{
    bersihkanLayarTertentu();
    moveCursor(13,9);
    printf("\t\t\t\t\t\t      \n");
    if (banyakIndeksPapan == 10)
    {
        printf("\t\t\t\t\t\t      ___ ___ ___ \n");
        printf("\t\t\t\t\t\t     |   |   |   |\n");
        for (int i = 0; i < 3; ++i) 
        {
            printf("\t\t\t\t\t\t     |");

            for (int j = 0; j < 3; ++j) 
            {
                int index = i * 3 + j + 1;
                setColor(papan[index]);
                printf("|");
            }
            printf("\n");
            if (i < 2) 
            {
                printf("\t\t\t\t\t\t     |---|---|---|\n");
            }
        }
        printf("\t\t\t\t\t\t     |___|___|___|\n");
    }
    else if (banyakIndeksPapan == 26)
    {
        printf("\t\t\t\t\t\t  ___ ___ ___ ___ ___ \n");
        printf("\t\t\t\t\t\t |   |   |   |   |   |\n");
        for (int i = 0; i < 5; ++i) 
        {
            printf("\t\t\t\t\t\t |");

            for (int j = 0; j < 5; ++j) 
            {
                int index = i * 5 + j + 1;
                setColor(papan[index]);
                printf("|");
            }
            printf("\n");
            if (i < 4) 
            {
                printf("\t\t\t\t\t\t |---|---|---|---|---|\n");
            }
        }
        printf("\t\t\t\t\t\t |___|___|___|___|___|\n\n");
    }
    else if (banyakIndeksPapan == 50)
    {
        printf("\t\t\t\t\t      ___ ___ ___ ___ ___ ___ ___\n");
        printf("\t\t\t\t\t     |   |   |   |   |   |   |   |\n");
        for (int i = 0; i < 7; ++i) 
        {
            printf("\t\t\t\t\t     |");

            for (int j = 0; j < 7; ++j) 
            {
                int index = i * 7 + j + 1;
                setColor(papan[index]);
                printf("|");
            }
            printf("\n");
            if (i < 6) 
            {
                printf("\t\t\t\t\t     |---|---|---|---|---|---|---|\n");
            }
        }
        printf("\t\t\t\t\t     |___|___|___|___|___|___|___|\n\n");
    }
    printSkor();
}

void giliranPemain(int banyakIndeksPapan, char papan[banyakIndeksPapan], PEMAIN *pemain)
{
    int langkahSah = false;
    char pilihIndeks;
    moveCursor(17,17); printf("Giliran %s (%c)\n", (*pemain).nama, (*pemain).bidak);
    while (langkahSah == false)
    {
        moveCursor(17,18); printf("inputkan pilihan kamu :"); scanf(" %c", &pilihIndeks); fflush(stdin);
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
        if (langkahSah == false)
        {
            moveCursor(9,20); printf("langkah kamu tidak valid");
            moveCursor(9,21); printf("atau kotak sudah diisi, coba lagi!");
        }
    } 
}

void printSkor()
{
    if (pemain2.bidak != 'N') // != 'N' berarti pemain 2 telah mempunyai bidak, sehingga sudah pasti pemain 1 melawan pemain 2
    {
        moveCursor(83, 11); printf("Skor %s: %d\n", pemain1.nama, pemain1.skor);
        moveCursor(83, 12); printf("Skor %s: %d\n\n", pemain2.nama, pemain2.skor);
    }
    else if (bidakKomputer != 'N') // != 'N' berarti komputer telah mempunyai bidak, sehingga sudah pasti pemain 1 melawan komputer
    {
        moveCursor(83, 11); printf("Skor %s: %d\n\n", pemain1.nama, pemain1.skor);
    }
}

void printPemenang()
{
    if (pemenang == pemain1.bidak)
    {
        moveCursor(84,16); printf("Selamat %s !!", pemain1.nama);
        moveCursor(80,17); printf("Kamu Menang Dengan Bidak %c", pemain1.bidak);        
        pemain1.skor++;
    }
    else if (pemenang == pemain2.bidak)
    {
        moveCursor(84,16); printf("Selamat %s !!", pemain2.nama);
        moveCursor(80,17); printf("Kamu Menang Dengan Bidak %c", pemain2.bidak);        
        pemain2.skor++;
    }
    else if (pemenang == bidakKomputer)
    {
        if (pemain1.skor > 0)
        {
            saveSkor();
        }
        moveCursor(84,16); printf("Yah Kamu Kalah :(\n");
        pemain1.skor = 0;
    }
    else if (pemenang == '\0')
    {
        moveCursor(84,16); printf("Tidak Ada Kotak Tersisa,");
        moveCursor(88,17); printf("Permainan DRAW !!");
    }
}

void inisialisasi()
{
    bidakKomputer = 'N'; // N artinya belum memilih bidak
    pemain1.bidak = 'N';
    pemain2.bidak = 'N';
    pemain1.skor = 0;
    pemain2.skor = 0;
}

char nanyaMainLagi()
{
    char inputUser;
    moveCursor(9,17); printf("ingin bermain lagi ? (Y/N)"); scanf(" %c", &inputUser); inputUser = toupper(inputUser);
    while (inputUser != 'Y' && inputUser != 'N')
    {
        moveCursor(3,18); printf("inputkan yang valid!! (Hanya Y atau N)"); scanf(" %c", &inputUser); inputUser = toupper(inputUser);
    }
    return inputUser;
}

void mainPapan(int banyakIndeksPapan, char papan[banyakIndeksPapan], PEMAIN *pemain, PEMAIN *pemain2)
{
    char inputUser;
    inisialisasi();
    inputNama();
    pilihBidak();
    bersihkanLayar();
    loading();
    bersihkanLayar();
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
    bersihkanLayarTertentu();
    bersihkanLayar();
}