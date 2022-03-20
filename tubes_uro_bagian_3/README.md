### MEKANISME SERANG
Untuk mekanisme serang ini, kami membuat beberapa void dan function.
Untuk kegunaan dari tiap void atau functionnya dapat dipaparkan secara berikut.
- **void Player::display()** -> Digunakan untuk menampilkan atribut dari robot atau bunshin Mechakurama.
- __void Player::attack(Player* player)__ -> Digunakan untuk memilih serang atau maju. 
- __void Player::equipWeapon(Damage* damage)__ -> Digunakan untuk mengambil nilai dari damage untuk digunakan pada function atau void lain.
- **void Player::defence(double damage)** -> Digunakan untuk mengurangi atribut health robot atau bunshin Mechakurama dengan damage yang dimiliki oleh Player.
- **double Damage::getPower()** -> Digunakan untuk mengambil nilai dari damage.
- **std::string Player::getName()** -> DIgunakan untuk mengambil nilai dari name.

#### Cara Menjalankan SubProgram
1. Pertama, kita harus membuat variabel dari class Player dan Damage yang akan diisi oleh suatu nilai.
2. Baik itu Robot, atau MechaKurama mendapatkan perlakuan yang sama.
3. Setelah memberikan variable dan nilainya, gunakan **void equipWeapon** pada keduanya untuk menambahkan atribut damage pada robot dan bunshin Mechakurama.
4. Lalu untuk tampilan pertama, gunakan **void Player::display()** untuk menampilkan informasi mengenai atribut dari Robot dan Bunshin Mechakurama.
5. Gunakan perintah **robot->attack(kurama);** agar robot dapat memulai aksinya untuk menyerang atau maju.
6. di dalam void tersebut, user akan diberikan opsi untuk menyerang atau maju.
7. Jika memilih untuk menyerang, maka robot akan mengurangi atribut health Mechakurama dengan atribut damage yang dimilikinya.
8. Bunshin Mechakurama akan menyerang balik secara otomatis.
9. Jika memilih untuk maju, maka program akan diarahkan pada subprogram mekanisme bergerak.
10. jika Bunshin Mechakurama berhasil dikalahkan, akan muncul lagi satu bunshin baru.
11. Jika atribut health robot telah habis, program telah selesai dan akan ditampilkan nilai total dari Bunshin Mechakurama yang telah dikalahkan.
