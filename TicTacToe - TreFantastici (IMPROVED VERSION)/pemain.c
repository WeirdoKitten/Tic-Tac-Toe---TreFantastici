#include "header.h"

void inputNama()
{
    moveCursor(33, 12); printf(" ______________________________________________________ ");
    moveCursor(33, 13); printf("|                                                      |");
    moveCursor(33, 14); printf("|                 Persiapan Permainan                  |");
    moveCursor(33, 15); printf("|______________________________________________________|");
    moveCursor(33, 16); printf("|                                                      |");
    moveCursor(33, 17); printf("|                                                      |"); 
    moveCursor(33, 18); printf("|    inputkan nama pemain 1 :                          |"); 
    moveCursor(33, 19); printf("|    inputkan nama pemain 2 :                          |"); 
    moveCursor(33, 20); printf("|                                                      |"); 
    moveCursor(33, 21); printf("|                                                      |"); 
    moveCursor(33, 22); printf("|                                                      |"); 
    moveCursor(33, 23); printf("|______________________________________________________|");
    fflush(stdin); moveCursor(63, 18); gets(pemain1.nama);
    fflush(stdin); moveCursor(63, 19); gets(pemain2.nama);
}

void pilihBidak()
{
    moveCursor(33, 12); printf(" ______________________________________________________ ");
    moveCursor(33, 13); printf("|                                                      |");
    moveCursor(33, 14); printf("|                 Persiapan Permainan                  |");
    moveCursor(33, 15); printf("|______________________________________________________|"); 
    moveCursor(33, 16); printf("|                                                      |");
    moveCursor(33, 17); printf("|              pilih bidak untuk pemain 1              |");
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
        pemain2.bidak = 'O';
    }
    else if (pemain1.bidak == 'O')
    {
        pemain2.bidak = 'X';
    }
}