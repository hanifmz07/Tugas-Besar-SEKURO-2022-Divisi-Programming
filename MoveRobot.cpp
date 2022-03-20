# include <iostream>
# include <conio.h>
using namespace std;

class Robot {
    public:
        // Deklarasi Array Posisi (sb.x dan sb.y)
        int position[1][2];

        // Constructor tanpa parameter
        Robot() 
        {
            // menginisiasi posisi awal (0,0)
            this->position[0][0] = 0;
            this->position[0][1] = 0;
        }

        // Deklarasi fungsi moveRobot
        void moveRobot (int direction); 

        // Fungsi menampilkan posisi awal
        void showPoint ()
        {
            cout << " -------------------" << endl;
            cout << "| Posisi Awal : ";
            cout << position[0][0] << " " << position[0][1] << " | " << endl;
            cout << " -------------------" << endl;
        }
};

// Fungsi menggerakkan robot
void Robot::moveRobot(int direction)
{
    // mengecek posisi robot benar atau tidak
    if (direction == 1) // Maju
    {
        position[0][0] ++;
    }
    else if (direction == 2) // Mundur
    {
        position[0][0] --;
    }
    else if (direction == 3) // Kanan
    {
        position[0][1] --;
    }
    else if (direction == 4) // Kiri
    {
        position[0][1] ++;
    }

    for (int j = 0; j < 2; j++)
    {
        if (position[0][j] < 0 or position[0][j] > 9)
        {
            cout << "Posisi salah (diluar peta) !!! " << endl;
            cout << "silahkan pilih kembali !!! " << endl;

            if (position [0][j] < 0)
            {
                position[0][j] ++; // Yang awalnya sempat dikurang, ditambah kembali
            }
            else if (position[0][j] > 9)
            {
                position[0][j] --; // Yang awalnya sempat ditambah, dikurangi kembali
            }
        }
    }
    // posisi diantara [0..9]
    // posisi sudah benar, maka tampilkan posisi akhir
    cout << "Posisi sekarang : " << position[0][0] << " " << position[0][1];

    cout << "\ntekan ENTER untuk kembali ke menu" << endl;
}


int main(int argc, char const *argv[])
{
    int pilih,arah;
    Robot r1; 
    menu:
        system("cls");
    cout << "================" << endl;
    cout << " 1. Move Robot"   << endl;
    cout << " 2. .........."   << endl;
    cout << " 3. .........."   << endl;
    cout << " 4. .........."   << endl;
    cout << " 5. Exit"         << endl;
    cout << "================" << endl;
    cout << "Pilihan (ketik angka): ";
    cin >> pilih;

    if (pilih == 1)
    {
        system("cls");
        cout << "=========================================================" << endl;
        cout << "                Mekanisme Pergerakan Robot            "    << endl;
        cout << "=========================================================" << endl;
        cout << "NB : - ROBOT HANYA BISA BERGERAK SATU SATUAN    "          << endl;
        cout << "     - POSISI ROBOT HARUS DI DALAM PETA , DIANTARA [0..9]" << endl;
  
        r1.showPoint(); // memanggil fungsi showPoint

        cout << "1. Maju"   <<endl;
        cout << "2. Mundur" <<endl;
        cout << "3. Kanan"  <<endl;
        cout << "4. kiri"   <<endl;
        cout << "Pilihan (ketik angka): ";
        cin >> arah;

        r1.moveRobot(arah); // memanggil fungsi moveRobot
        getch();
        goto menu;
    }

    if (pilih == 5)
    {
        system("cls");
        exit;
    }

    return 0;
}
