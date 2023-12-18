#include "header.h"

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
    moveCursor(33, 10); printf(" ______________________________________________________ ");
    moveCursor(33, 11); printf("|                                                      |");
    moveCursor(33, 12); printf("|                Top 10 Skor Tertinggi                 |");
    moveCursor(33, 13); printf("|______________________________________________________|"); 
    moveCursor(33, 14); printf("|                  |               |                   |");    
    moveCursor(33, 15); printf("|    NamaPemain    |     Bidak     |   SkorTertinggi   |");
    moveCursor(33, 16); printf("|__________________|_______________|___________________|");
    moveCursor(33, 17); printf("|                  |               |                   |");
    moveCursor(33, 18); printf("|                  |               |                   |");
    moveCursor(33, 19); printf("|                  |               |                   |");
    moveCursor(33, 20); printf("|                  |               |                   |");
    moveCursor(33, 21); printf("|                  |               |                   |");
    moveCursor(33, 22); printf("|                  |               |                   |");
    moveCursor(33, 23); printf("|                  |               |                   |");
    moveCursor(33, 24); printf("|                  |               |                   |");
    moveCursor(33, 25); printf("|                  |               |                   |");
    moveCursor(33, 26); printf("|                  |               |                   |");
    moveCursor(33, 27); printf("|                  |               |                   |");
    moveCursor(33, 28); printf("|__________________|_______________|___________________|");

    for (int i = 0; i < jmlData && i < 10; i++)
    {
        moveCursor(38, 18 + i); printf("%s", riwayatPemain[i].nama);
        moveCursor(60, 18 + i); printf("%c", riwayatPemain[i].bidak);
        moveCursor(78, 18 + i); printf("%d", riwayatPemain[i].skor);
    }
    moveCursor(44, 30); printf("tekan tombol apapun untuk kembali");
    getch();
    bersihkanLayar();
}

void lihatPeringkat()
{
    readPeringkat();
    sortPeringkat();
    printPeringkat();
}