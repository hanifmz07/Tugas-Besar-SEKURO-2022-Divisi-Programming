# include <iostream>
# include <conio.h>
using namespace std;

struct Point {
    int x, y;
};

class Robot {
    public:
        // Deklarasi Array Posisi (sb.x dan sb.y)
        
        Point coord;
        //int position[1][2];

        Robot() 
        {
            // menginisiasi posisi awal (0,0)
            //this->position[0][0] = 0;
            //this->position[0][1] = 0;
            this->coord.x = 0;
            this->coord.y = 0;

        }

        // Deklarasi fungsi moveRobot
        void moveRobot (int direction); 

        // Fungsi menampilkan posisi awal
        void showPoint ()
        {
            cout << " -------------------" << endl;
            cout << "| Posisi Awal : ";
            //cout << position[0][0] << " " << position[0][1] << " | " << endl;
            cout << this->coord.x << " " << this->coord.y << " | " << endl;
            cout << " -------------------" << endl;
        }
};

// Fungsi menggerakkan robot
void Robot::moveRobot(int direction)
{
    while (true){
        
        if (direction == 1) // Maju
        {
            if (this->coord.y + 1 > 9) {
                cout << "Posisi salah (diluar peta)!" << endl;
                cout << "Silahkan pilih kembali!" << endl;
                continue;
            } else {
                this->coord.y ++;
                break;
            }
            //position[0][0] ++;
        }
        else if (direction == 2) // Mundur
        {
            if (this->coord.y - 1 < 0) {
                cout << "Posisi salah (diluar peta)!" << endl;
                cout << "Silahkan pilih kembali!" << endl;
                continue;
            } else {
                this->coord.y --;
                break;
            }
            //position[0][0] --;
        }
        else if (direction == 3) // Kanan
        {
            if (this->coord.x + 1 > 9) {
                cout << "Posisi salah (diluar peta)!" << endl;
                cout << "Silahkan pilih kembali!" << endl;
                continue;
            } else {
                this->coord.x ++;
                break;
            }
            //position[0][1] --;
        }
        else if (direction == 4) // Kiri
        {
            if (this->coord.x - 1 < 0) {
                cout << "Posisi salah (diluar peta)!" << endl;
                cout << "Silahkan pilih kembali!" << endl;
                continue;
            } else {
                this->coord.x --;
                break;
            }
            //position[0][1] ++;
        }

    }
    
	// mengecek posisi robot benar atau tidak
    // posisi diantara [0..9]
    // posisi sudah benar, maka tampilkan posisi akhir
    //cout << "Posisi sekarang : " << this->coord.x << " " << this->coord.y;

    //cout << "\ntekan ENTER untuk kembali ke menu" << endl;
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
