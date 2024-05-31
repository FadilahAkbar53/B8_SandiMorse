# Program Sandi Morse

## Deskripsi
Ini adalah program sederhana yang ditulis dalam bahasa C untuk mengonversi teks ke dalam sandi Morse dan sebaliknya.

Program ini memungkinkan pengguna untuk melakukan beberapa fungsi berikut:
* Konversi Teks ke Sandi Morse: Pengguna dapat memasukkan teks dan mendapatkan keluaran sandi Morse yang sesuai.
* Konversi Sandi Morse ke Teks: Pengguna dapat memasukkan sandi Morse dan mendapatkan teks yang sesuai.
* Struktur Hirarki Sandi Morse: Program menampilkan struktur hierarki sandi Morse untuk referensi pengguna.
* Percakapan: Program memungkinkan dua pengguna untuk saling bertukar pesan terenkripsi menggunakan sandi Morse.

## Instalasi Program
1. Clone repositori ini ke dalam direktori lokal Anda.
2. Buka terminal dan arahkan ke direktori tempat Anda menyimpan repositori.
3. pastikan Anda memiliki compiler C yang terinstal di sistem Anda.
4. Lakukan instalasi library cUrl dan cJSON dengan mengikuti langkah-langkah berikut:
    * cUrl:
      1. Untuk pengguna Linux, jalankan perintah berikut di terminal:
            ```bash
            sudo apt-get install libcurl4-openssl-dev
            ```
      2. Untuk pengguna Windows, unduh file binari dari [sini](https://curl.se/windows/).
      3. Setelah mengunduh, ekstrak file zip dan tambahkan path ke direktori bin ke dalam PATH sistem Anda.
      4. Masukan Folder Include dan Lib ke dalam folder include dan lib pada direktori MinGW Atau UCRT64.
      5. Untuk memastikan cUrl terinstal dengan benar, jalankan perintah berikut di terminal:
            ```bash
            curl --version
            ``` 
          
          Alternative jika menggunakan msys2, anda bisa menggunakan perintah berikut:
            ```bash
            pacman -S mingw-w64-ucrt-x86_64-curl
            ```
          catatan ucrt bisa diganti dengan msvcrt atau hilangkan extensi jika menggunakan Mingw tergantung versi compiler yang digunakan.
    * cJSON:
      1. Untuk pengguna Linux, jalankan perintah berikut di terminal:
          ```bash
          sudo apt-get install libcjson-dev
          ```
      2. Untuk pengguna Windows, unduh file binari dari [sini](https://packages.msys2.org/base/mingw-w64-cjson)
      3. Masukan Folder Include dan Lib ke dalam folder include dan lib pada direktori MinGW Atau UCRT64.
      4. Untuk memastikan cJSON terinstal dengan benar, jalankan perintah berikut di terminal:
            ```bash
            cJSON --version
            ```
      5. Jika menggunakan msys2, anda bisa menggunakan perintah berikut:
            ```bash
            pacman -S mingw-w64-ucrt-x86_64-cjson
            ```
            catatan ucrt bisa diganti dengan msvcrt atau hilangkan extensi jika menggunakan Mingw tergantung versi compiler yang digunakan.
          
    * Configurasi IDE Dev-C++:
      1. Buka Dev-C++ dan buka menu Tools -> Compiler Options.
      2. Pilih tab "Directories" dan tambahkan path ke direktori include dan lib cUrl dan cJSON.
      3. Pilih tab "Linker" dan tambahkan path ke direktori lib cUrl dan cJSON.
      4. Klik OK untuk menyimpan perubahan.
        
    * Configurasi IDE Visual Studio Code (Code Runner Extension):
      1. Buka file .vscode/settings.json dan tambahkan path ke direktori include dan lib cUrl dan cJSON.
      2. jika tidak ditemukan, buka extension Code Runner masuk ke pengaturan Extention Setting pada Executor Map klik "Edit in settings.json".
      3. Masukan kode berikut untuk memastikan cUrl dan cJSON terinstal dengan compiler C yang digunakan:
          ```json
          "code-runner.executorMap": {
              "c": "cd $dir && gcc $fileName -o $fileNameWithoutExt -lcurl -lcjson && $dir$fileNameWithoutExt",
          }
          ```
     * Configurasi Alternatif Dengan Cmake:
       1. pastikan code editor anda mampu menggunakan cmake.
       2. buka terminal dan arahkan ke direktori tempat Anda menyimpan repositori.
       3. jalankan perintah berikut:
       4. Generate MakeFile dengan extention atau code editor yang anda gunakan.
       5. jika CMakeLists.txt sudah tergenerate masukan code berikut:
            ```cmake
            cmake_minimum_required(VERSION 3.26)
            project(B8_SandiMorse C)
            include_directories("C:/msys64/mingw64/include")
            add_executable(B8_SandiMorse
                  main.c
            )
            target_link_libraries(B8_SandiMorse ${CURL_LIBRARY} ${CJSON_LIBRARY})
            ```
        * catatan include_directories sesuaikan dengan path include cUrl dan cJSON.
     * program siap build dan run program.
     

## Kontribusi
* Fadilah Akbar            | 231524041
* Jelang Anugrah Raharjo   | 231524046
* Nesta Rizkia Saputra     | 231524060
