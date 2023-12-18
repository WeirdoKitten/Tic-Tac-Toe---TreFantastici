#include "header.h"

void moveCursor(int x, int y) // untuk memindahkan posisi kursor berdasarkan koordinat kartesius
{
    COORD koordinat;
    koordinat.X = x;
    koordinat.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), koordinat);
}

void printBanner()
{
	moveCursor(13, 1); printf("%c", 201);
    for (int i = 1; i < 95; i++)
    {
        printf("%c", 205);
    }
    printf ("%c", 187);

	moveCursor(18, 2); printf(" ______   __     ______     ______   ______     ______     ______   ______     ______    	    ");
	moveCursor(18, 3); printf("/\\__  _\\ /\\ \\   /\\  ___\\   /\\__  _\\ /\\  __ \\   /\\  ___\\   /\\__  _\\ /\\  __ \\   /\\  ___\\    ");
	moveCursor(18, 4); printf("\\/_/\\ \\/ \\ \\ \\  \\ \\ \\____  \\/_/\\ \\/ \\ \\  __ \\  \\ \\ \\____  \\/_/\\ \\/ \\ \\ \\/\\ \\  \\ \\  __\\     ");
	moveCursor(18, 5); printf("   \\ \\_\\  \\ \\_\\  \\ \\_____\\    \\ \\_\\  \\ \\_\\ \\_\\  \\ \\_____\\    \\ \\_\\  \\ \\_____\\  \\ \\_____\\   ");
	moveCursor(18, 6); printf("    \\/_/   \\/_/   \\/_____/     \\/_/   \\/_/\\/_/   \\/_____/     \\/_/   \\/_____/   \\/_____/     ");
	
	moveCursor(13,8); printf("%c", 200);
    for (int i = 1; i < 95; i++)
    {
        printf("%c", 205);
	}
    printf("%c", 188);
}

void loading()
{
	moveCursor(47,13); printf("          Loading...");
	moveCursor(47,14); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201 , 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
	moveCursor(47,15); printf("%c                           %c", 186,186);
	moveCursor(47,16); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200 , 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
	for(int x = 48; x < 75; x++)
    {
		moveCursor(x,15); printf("%c", 219);
		usleep(20000);
	}
}

void printPembuka()
{
    system("cls");
    printBanner();
    moveCursor(39, 21); printf("Selamat Datang Di TicTacToe !! - TreFantastici\n\n");
    moveCursor(38, 23); printf("Tips : sebelum main, lihat tutorialnya dulu ya :)\n\n");
    loading();
    moveCursor(43, 13); printf("tekan tombol apapun untuk lanjut main");
    getch();
}

int printPanah(int posisiMenuPertama, int posisiMenuTerakhir) // berfungsi untuk mengontrol panah
{
    int posisiPanah = posisiMenuPertama; // untuk mengakses menu, jika nilai 1 maka mengakses menu urutan ke-1
    int tombolDitekan = 0;
    while(tombolDitekan != 13)
    {
        tombolDitekan = getch();
        if (tombolDitekan == 80 && posisiPanah < posisiMenuTerakhir) // 80 adalah kode ascii tombol panah bawah
        {
            posisiPanah++;
        }
        else if (tombolDitekan == 72 && posisiPanah > posisiMenuPertama) // 72 adalah kode ascii tombol panah atas
        {
            posisiPanah--;
        }
        else
        {
            posisiPanah = posisiPanah;
        }

        if (posisiPanah == 1)
        {
            moveCursor(33, 17); printf("|            ---> ");
            moveCursor(33, 18); printf("|                 ");
            moveCursor(33, 19); printf("|                 ");
            moveCursor(33, 20); printf("|                 ");
            moveCursor(33, 21); printf("|                 ");
            moveCursor(33, 22); printf("|                 ");
        }
        else if (posisiPanah == 2)
        {
            moveCursor(33, 17); printf("|                 ");
            moveCursor(33, 18); printf("|            ---> ");
            moveCursor(33, 19); printf("|                 ");
            moveCursor(33, 20); printf("|                 ");
            moveCursor(33, 21); printf("|                 ");
            moveCursor(33, 22); printf("|                 ");
        }
        else if (posisiPanah == 3)
        {
            moveCursor(33, 17); printf("|                 ");
            moveCursor(33, 18); printf("|                 ");
            moveCursor(33, 19); printf("|            ---> ");
            moveCursor(33, 20); printf("|                 ");
            moveCursor(33, 21); printf("|                 ");
            moveCursor(33, 22); printf("|                 ");
        }
        else if (posisiPanah == 4)
        {
            moveCursor(33, 17); printf("|                 ");
            moveCursor(33, 18); printf("|                 ");
            moveCursor(33, 19); printf("|                 ");
            moveCursor(33, 20); printf("|            ---> ");
            moveCursor(33, 21); printf("|                 ");
            moveCursor(33, 22); printf("|                 ");
        }
        else if (posisiPanah == 5)
        {
            moveCursor(33, 17); printf("|                 ");
            moveCursor(33, 18); printf("|                 ");
            moveCursor(33, 19); printf("|                 ");
            moveCursor(33, 20); printf("|                 ");
            moveCursor(33, 21); printf("|            ---> ");
            moveCursor(33, 22); printf("|                 ");
        }
        else if (posisiPanah == 6)
        {
            moveCursor(33, 17); printf("|                 ");
            moveCursor(33, 18); printf("|                 ");
            moveCursor(33, 19); printf("|                 ");
            moveCursor(33, 20); printf("|                 ");
            moveCursor(33, 21); printf("|                 ");
            moveCursor(33, 22); printf("|            ---> ");
        }
        moveCursor(89, 23);
    }
    return posisiPanah; 
}

int pilihMenuUtama()
{
    moveCursor(33, 12); printf(" ______________________________________________________ ");
    moveCursor(33, 13); printf("|                                                      |");
    moveCursor(33, 14); printf("|                     Menu Utama                       |");
    moveCursor(33, 15); printf("|______________________________________________________|"); // ketentuan posisi semua menu
    moveCursor(33, 16); printf("|                                                      |");
    moveCursor(33, 17); printf("|            --->  Mulai Permainan                     |"); // posisi 1
    moveCursor(33, 18); printf("|                  Lihat Papan Peringkat               |"); // posisi 2
    moveCursor(33, 19); printf("|                  Tutorial Permainan                  |"); // posisi 3
    moveCursor(33, 20); printf("|                  Kredit                              |"); // posisi 4
    moveCursor(33, 21); printf("|                  Keluar                              |"); // posisi 5
    moveCursor(33, 22); printf("|                                                      |"); // posisi 6
    moveCursor(33, 23); printf("|______________________________________________________|");
    return printPanah(1, 5);
}

int pilihLevel()
{
    moveCursor(33, 12); printf(" ______________________________________________________ ");
    moveCursor(33, 13); printf("|                                                      |");
    moveCursor(33, 14); printf("|                 Pilih Level Komputer                 |");
    moveCursor(33, 15); printf("|______________________________________________________|"); // ketentuan posisi semua menu
    moveCursor(33, 16); printf("|                                                      |");
    moveCursor(33, 17); printf("|                                                      |"); // posisi 1
    moveCursor(33, 18); printf("|            --->     Pemula                           |"); // posisi 2
    moveCursor(33, 19); printf("|                     Menengah                         |"); // posisi 3
    moveCursor(33, 20); printf("|                     Sepuh TicTacToe                  |"); // posisi 4
    moveCursor(33, 21); printf("|                                                      |"); // posisi 5
    moveCursor(33, 22); printf("|                                                      |"); // posisi 6
    moveCursor(33, 23); printf("|______________________________________________________|");
    return printPanah(2, 4);
}

int pilihLawan()
{
    moveCursor(33, 12); printf(" ______________________________________________________ ");
    moveCursor(33, 13); printf("|                                                      |");
    moveCursor(33, 14); printf("|                   Pilih Lawan Kamu                   |");
    moveCursor(33, 15); printf("|______________________________________________________|"); // ketentuan posisi semua menu
    moveCursor(33, 16); printf("|                                                      |");
    moveCursor(33, 17); printf("|                                                      |"); // posisi 1
    moveCursor(33, 18); printf("|            --->   Pemain VS Pemain                   |"); // posisi 2
    moveCursor(33, 19); printf("|                   Pemain VS Komputer                 |"); // posisi 3
    moveCursor(33, 20); printf("|                                                      |"); // posisi 4
    moveCursor(33, 21); printf("|                                                      |"); // posisi 5
    moveCursor(33, 22); printf("|                                                      |"); // posisi 6
    moveCursor(33, 23); printf("|______________________________________________________|");
    return printPanah(2, 3);
}

int pilihUkuranPapan()
{
    moveCursor(33, 12); printf(" ______________________________________________________ ");
    moveCursor(33, 13); printf("|                                                      |");
    moveCursor(33, 14); printf("|                  Pilih Ukuran Papan                  |");
    moveCursor(33, 15); printf("|______________________________________________________|"); // ketentuan posisi semua menu
    moveCursor(33, 16); printf("|                                                      |");
    moveCursor(33, 17); printf("|                                                      |"); // posisi 1
    moveCursor(33, 18); printf("|            --->      Papan 3x3                       |"); // posisi 2
    moveCursor(33, 19); printf("|                      Papan 5x5                       |"); // posisi 3
    moveCursor(33, 20); printf("|                      Papan 7x7                       |"); // posisi 4
    moveCursor(33, 21); printf("|                                                      |"); // posisi 5
    moveCursor(33, 22); printf("|                                                      |"); // posisi 6
    moveCursor(33, 23); printf("|______________________________________________________|");
    return printPanah(2, 4);
}

void kredit()
{
    moveCursor(33, 12); printf(" ______________________________________________________ ");
    moveCursor(33, 13); printf("|                                                      |");
    moveCursor(33, 14); printf("|                     Tentang Kami                     |");
    moveCursor(33, 15); printf("|______________________________________________________|");
    moveCursor(33, 16); printf("|                                                      |");
    moveCursor(33, 17); printf("|   231524007 | Farrel Zandra         | @farrel29__    |");
    moveCursor(33, 18); printf("|   231524020 | Nobby Dharma Khaulid  | @nobbykhaulid  |");
    moveCursor(33, 19); printf("|   231524026 | Satria Permata Sejati | @WeirdoKitten  |");
    moveCursor(33, 20); printf("|                                                      |");
    moveCursor(33, 21); printf("|    tekan tombol apapun untuk kembali ke menu utama   |");
    moveCursor(33, 22); printf("|                                                      |");
    moveCursor(33, 23); printf("|______________________________________________________|");
    getch();
}

void tutorGame() 
{
    moveCursor(21, 10); printf("      Pertama kali memainkan permainan ini? Berikut penjelasan permainan!");
    moveCursor(21, 11); printf(" ______________________________________________________________________________ ");
    moveCursor(21, 12); printf("|                                                                              |");
    moveCursor(21, 13); printf("|                              Tutorial Permainan                              |");
    moveCursor(21, 14); printf("|______________________________________________________________________________|");
    moveCursor(21, 15); printf("|                                                                              |");
    moveCursor(21, 16); printf("| 1. Ketikkan angka 1-9 yang merepresentasikan masing-masing kotak yang        |");
    moveCursor(21, 17); printf("|    tersedia dan klik enter. Maka kotak kosong akan diisi dengan bidak yang   |");
    moveCursor(21, 18); printf("|    kamu pilih                                                                |");
    moveCursor(21, 19); printf("|                                                                              |");
    moveCursor(21, 20); printf("| 2. Giliran Pemain selanjutnya. Jika pemain 2 adalah manusia, maka lakukan    |");
    moveCursor(21, 21); printf("|    seperti langkah 1 (pastikan memilih kotak yang masih kosong. Namun jika   |");
    moveCursor(21, 22); printf("|    pemain 2 adalah komputer maka kotak kosong akan otomatis terisi.          |");
    moveCursor(21, 23); printf("|                                                                              |");
    moveCursor(21, 24); printf("| 3. Ulangi langkah 1 dan 2 hingga sistem memberitahukan status permainan      |");
    moveCursor(21, 25); printf("|    seperti, menang, kalah, ataupun seri.                                     |");
    moveCursor(21, 26); printf("|                                                                              |");
    moveCursor(21, 27); printf("| 4. Permainan selesai, anda dapat mengulangi permainan ataupun menyudahinya.  |");
    moveCursor(21, 28); printf("|______________________________________________________________________________|");
    moveCursor(44, 30); printf("tekan tombol apapun untuk kembali");
    getch();
    bersihkanLayar();
}
void bersihkanLayar()
{
    moveCursor(21, 10); printf("                                                                                ");
    moveCursor(21, 11); printf("                                                                                ");
    moveCursor(21, 12); printf("                                                                                ");
    moveCursor(21, 13); printf("                                                                                ");
    moveCursor(21, 14); printf("                                                                                ");
    moveCursor(21, 15); printf("                                                                                ");
    moveCursor(21, 16); printf("                                                                                ");
    moveCursor(21, 17); printf("                                                                                ");
    moveCursor(21, 18); printf("                                                                                ");
    moveCursor(21, 19); printf("                                                                                ");
    moveCursor(21, 20); printf("                                                                                ");
    moveCursor(21, 21); printf("                                                                                ");
    moveCursor(21, 22); printf("                                                                                ");
    moveCursor(21, 23); printf("                                                                                ");
    moveCursor(21, 24); printf("                                                                                ");
    moveCursor(21, 25); printf("                                                                                ");
    moveCursor(21, 26); printf("                                                                                ");
    moveCursor(21, 27); printf("                                                                                ");
    moveCursor(21, 28); printf("                                                                                ");
    moveCursor(21, 29); printf("                                                                                ");
    moveCursor(21, 30); printf("                                                                                ");
}

void bersihkanLayarTertentu()
{
    moveCursor(3,17); printf("                                               "); 
    moveCursor(3,18); printf("                                               ");
    moveCursor(3,20); printf("                                               ");
    moveCursor(3,21); printf("                                               ");

    moveCursor(83,11); printf("                                         ");
    moveCursor(83,12); printf("                                         ");
    moveCursor(80,16); printf("                                         ");
    moveCursor(80,17); printf("                                         ");
}