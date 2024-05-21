#include <stdio.h>
#include <stdlib.h>
#include "header.h"
// TAMPILAN PROGRAM

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
    printf("| 1. Struktur Hirarki Sandi Morse    |\n");
    printf("| 2. Struktur huruf dalam hirarki    |\n");
    printf("|    sandi                           |\n");
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

void hirarkiSandiMorse()
{
    printf("                    STRUKTUR HIRARKI SANDI MORSE\n");
    printf("                            START\n");
    printf("                             / \\\n");
    printf("                            /   \\\n");
    printf("                           /     \\\n");
    printf("                          /       \\\n");
    printf("                         /         \\\n");
    printf("                        /           \\\n");
    printf("                       /             \\\n");
    printf("                      /               \\\n");
    printf("                     /                 \\\n");
    printf("                    /                   \\\n");
    printf("                   /                     \\\n");
    printf("                  /                       \\\n");
    printf("                 /                         \\\n");
    printf("                /                           \\\n");
    printf("               /                             \\\n");
    printf("              E                               T\n");
    printf("             / \\                             / \\\n");
    printf("            /   \\                           /   \\\n");
    printf("           /     \\                         /     \\\n");
    printf("          /       \\                       /       \\\n");
    printf("         /         \\                     /         \\\n");
    printf("        /           \\                   /           \\\n");
    printf("       /             \\                 /             \\\n");
    printf("      I               A               N               M\n");
    printf("     / \\             / \\             / \\             / \\\n");
    printf("    /   \\           /   \\           /   \\           /   \\\n");
    printf("   /     \\         /     \\         /     \\         /     \\\n");
    printf("  S       U       R       W       D       K       G       O\n");
    printf(" / \\     / \\     / \\     / \\     / \\     / \\     / \\     / \\\n");
    printf("H   V    F      L       P   J   B   X   C   Y   Z   Q \n");
}