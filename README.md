# Tugas-Besar-SEKURO-2022-Divisi-Programming

<p>&nbsp;</p>

## Nama/NIM Anggota Kelompok:
### 16521066 - Hanif Muhammad Zhafran
### 16521192 - Albert
### 16521254 - Muhammad Rafli

<p>&nbsp;</p>

## Cara Menjalankan Program
Directory dari program utama berada di folder tubes_uro_final.

Cara run program (ini dilakukan di terminal vscode):
1. Pada terminal, atur directory agar sama dengan directory source code
2. Ketik g++ main.cpp functions.cpp -o main.exe pada terminal
3. Kemudian run main.exe dengan cara mengetik .\main.exe

Setelah program dijalankan, sebuah arena/battlefield akan dibuat dengan ukuran 10x10.
Sobot akan muncul di koordinat (0,0) dan Bunshin Mecha Kurama akan muncul di suatu koordinat secara acak (tetapi tidak sama dengan koordinat robot).
Spec robot:
1. Jarak maksimal senjata robot: 3 satuan (jarak yang digunakan adalah jarak euclidean)
2. Health: 100 HP
3. Damage senjata: 50

Spec Bunshin Mecha Kurama:
1. Health: 80-120 HP
2. Damage: 10-40
3. Range (x, y): (1-3, 1-3) satuan
Area dari range bunshin berupa persegi panjang dengan panjang dari (pusat - x) sampai (pusat + x) dan lebar dari (pusat - y) sampai (pusat + y).
Jika robot memasuki area tersebut, robot akan otomatis diserang oleh bunshin.

User akan diminta untuk menginput nomor 1, 2, atau 3, sesuai dengan keinginan user. Nomor 1 merupakan perintah untuk menyerang, nomor 2 merupakan perintah untuk bergerak, nomor 3 merupakan perintah untuk exit program.
Nomor 1 tidak bisa digunakan ketika jarak antara robot dan bunshin > 3.

Ketika bunshin berhasil dikalahkan oleh robot, akan muncul bunshin lain di koordinat acak (tetapi tidak sama dengan koordinat robot).

Program akan berhenti ketika user memilih nomor 3 saat memilih apa yang akan dilakukan atau ketika Health robot sudah habis (mencapai 0).
Ketika program akan berhenti, program akan menampilkan terlebih dahulu berapa jumlah bunshin yang berhasil dibunuh. Kemudian baru program akan berakhir.
