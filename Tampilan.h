#ifndef B8_SANDIMORSE_TAMPILAN_H
#define B8_SANDIMORSE_TAMPILAN_H

#include <stdio.h>
#include <stdlib.h>

void menuUtama()
{
    system("cls");
    printf("=====================================\n");
    printf("|      Selamat Datang di Program    |\n");
    printf("|           Sandi Morse             |\n");
    printf("=====================================\n");
    printf("| Menu:                             |\n");
    printf("| 1. Baca file input.txt            |\n");
    printf("| 2. Terjemahan Sandi Morse         |\n");
    printf("| 3. Print Struktur Tree            |\n");
    printf("| 4. Percakapan                     |\n");
    printf("| 0. Keluar                         |\n");
    printf("=====================================\n");
    printf("Pilihan Anda: ");
}
void menuTerjemah()
{
    system("cls");
    printf("=====================================\n");
    printf("|               Menu                 |\n");
    printf("=====================================\n");
    printf("| 1. Sandi Morse Menjadi Kalimat     |\n");
    printf("| 2. Kalimat Menjadi Sandi Morse     |\n");
    printf("| 0. Kembali                         |\n");
    printf("=====================================\n");
    printf("Pilihan Anda: ");
}

void menuHirarki()
{
    system("cls");
    printf("=====================================\n");
    printf("|                Menu                |\n");
    printf("=====================================\n");
    printf("| 1. Hirarki tree Sandi Morse        |\n");
    printf("| 2. hierarki tree salah satu        |\n");
    printf("|    karakter                        |\n");
    printf("| 3. Struktur tree karakter ke       |\n");
    printf("|    karakter                        |\n");
    printf("| 0. Kembali                         |\n");
    printf("=====================================\n");
    printf("Pilihan Anda: ");
}

void menuPercakapan()
{
    system("cls");
    printf("=====================================\n");
    printf("|                Menu                |\n");
    printf("=====================================\n");
    printf("| 1. Pengguna 1                      |\n");
    printf("| 2. Pengguna 2                      |\n");
    printf("| 0. Kembali                         |\n");
    printf("=====================================\n");
    printf("Pilihan Anda: ");
}

void menuPengguna1()
{
    system("cls");
    printf("=====================================\n");
    printf("|               Menu                 |\n");
    printf("=====================================\n");
    printf("| 1. Menulis pesan kepada pengguna 1 |\n");
    printf("| 2. Membaca Pesan dari pengguna 2   |\n");
    printf("| 0. Kembali                         |\n");
    printf("=====================================\n");
    printf("Pilihan anda : ");
}

void menuPengguna2()
{
    system("cls");
    printf("=====================================\n");
    printf("|               Menu                 |\n");
    printf("=====================================\n");
    printf("| 1. Menulis pesan kepada pengguna 1 |\n");
    printf("| 2. Membaca Pesan dari pengguna 2   |\n");
    printf("| 0. Kembali                         |\n");
    printf("=====================================\n");
    printf("Pilihan anda : ");
}

void menuPengguna()
{
    system("cls");
    printf("=====================================\n");
    printf("|            Menu Pengguna           |\n");
    printf("=====================================\n");
    printf("| 1. Menulis pesan                   |\n");
    printf("| 2. Membaca Pesan                   |\n");
    printf("| 0. Kembali                         |\n");
    printf("=====================================\n");
    printf("Pilihan anda : ");
}

#endif //B8_SANDIMORSE_TAMPILAN_H