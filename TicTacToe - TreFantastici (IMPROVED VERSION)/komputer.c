#include "header.h"

void inputNamaKomputer()
{
    moveCursor(33, 12); printf(" ______________________________________________________ ");
    moveCursor(33, 13); printf("|                                                      |");
    moveCursor(33, 14); printf("|                 Persiapan Permainan                  |");
    moveCursor(33, 15); printf("|______________________________________________________|");
    moveCursor(33, 16); printf("|                                                      |");
    moveCursor(33, 17); printf("|                                                      |"); 
    moveCursor(33, 18); printf("|                                                      |"); 
    moveCursor(33, 19); printf("|     inputkan nama kamu :                             |"); 
    moveCursor(33, 20); printf("|                                                      |"); 
    moveCursor(33, 21); printf("|                                                      |"); 
    moveCursor(33, 22); printf("|                                                      |"); 
    moveCursor(33, 23); printf("|______________________________________________________|");
    fflush(stdin); moveCursor(60, 19); gets(pemain1.nama);
}

void pilihBidakKomputer()
{
    moveCursor(33, 12); printf(" ______________________________________________________ ");
    moveCursor(33, 13); printf("|                                                      |");
    moveCursor(33, 14); printf("|                 Persiapan Permainan                  |");
    moveCursor(33, 15); printf("|______________________________________________________|"); 
    moveCursor(33, 16); printf("|                                                      |");
    moveCursor(33, 17); printf("|                  pilih bidak kamu                    |");
    moveCursor(33, 18); printf("|                                                      |");
    moveCursor(33, 19); printf("|               (hanya input X atau O):                |");
    moveCursor(33, 20); printf("|                                                      |");
    moveCursor(33, 21); printf("|                                                      |");
    moveCursor(33, 22); printf("|                                                      |");
    moveCursor(33, 23); printf("|______________________________________________________|");
    moveCursor(73, 19); scanf(" %c", &pemain1.bidak); pemain1.bidak = toupper(pemain1.bidak);
    while (pemain1.bidak != 'X' && pemain1.bidak != 'O') 
    {
        moveCursor(46, 21); printf("inputkan yang valid (X atau O): ");
        moveCursor(78, 21); scanf(" %c", &pemain1.bidak);
        pemain1.bidak = toupper(pemain1.bidak);
    }
    if (pemain1.bidak == 'X')
    {
        bidakKomputer = 'O';
    }
    else if (pemain1.bidak == 'O')
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

void mainPapanKomputerPemula(int banyakIndeksPapan, char papan[banyakIndeksPapan], PEMAIN *pemain)
{
    char inputUser;
    inisialisasi();
    inputNamaKomputer();
    pilihBidakKomputer();
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
    if (pemenang != bidakKomputer)
    {
        saveSkor();
    }
    bersihkanLayar();
    bersihkanLayarTertentu();
}