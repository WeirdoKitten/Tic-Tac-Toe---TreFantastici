#include "header.h"

int main()
{
    int inputMenu;
    int inputLawan;
    int inputLevel;
    int inputPapan;
    printPembuka();
    while (true)
    {
        inputMenu = pilihMenuUtama();
        switch (inputMenu)
        {
        case 1 : // case 1 adalah posisi menu "Mulai Permainan"
            inputLawan = pilihLawan();
            if (inputLawan == 2) // 2 adalah posisi menu "Pemain VS Pemain"
            {
                inputPapan = pilihUkuranPapan();
                if (inputPapan == 2) // 2 adalah posisi menu "Papan 3x3"
                {
                    mainPapan(10, papan3x3, &pemain1, &pemain2);
                }
                else if (inputPapan == 3) // 3 adalah posisi menu "Papan 5x5"
                {
                    mainPapan(26, papan5x5, &pemain1, &pemain2);
                }
                else if (inputPapan == 4) // 4 adalah posisi menu "Papan 7x7"
                {
                    mainPapan(50, papan7x7, &pemain1, &pemain2);
                }
            }
            else if (inputLawan == 3) // 3 adalah posisi menu "Pemain VS Komputer"
            {
                inputLevel = pilihLevel();
                if (inputLevel == 2) // 2 adalah posisi menu "Pemula"
                {
                    inputPapan = pilihUkuranPapan();
                    if (inputPapan == 2) // 2 adalah posisi menu "Papan 3x3"
                    {
                        mainPapanKomputerPemula(10, papan3x3, &pemain1);
                    }
                    else if (inputPapan == 3) // 3 adalah posisi menu "Papan 5x5"
                    {
                        mainPapanKomputerPemula(26, papan5x5, &pemain1);
                    }
                    else if (inputPapan == 4) // 4 adalah posisi menu "Papan 7x7"
                    {
                        mainPapanKomputerPemula(50, papan7x7, &pemain1);
                    }
                }
                else if (inputLevel == 3)
                {
                    /* code */
                }
                else if (inputLevel == 4)
                {
                    /* code */
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
        default:
            break;
        }
    }
    return 0;
}