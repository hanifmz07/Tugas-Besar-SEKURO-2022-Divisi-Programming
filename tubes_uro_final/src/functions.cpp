#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "classes.hpp"

using namespace std;

void Robot::display(){
    cout << "\nName\t: " << this->name << endl;
    cout << "Health\t: " << this->health << endl;
    cout << "Power\t: "<< this->damage << endl;
}

void Robot::attack(MechaKurama* player){
    cout << endl << this->name << " menyerang Bunshin Mecha Kurama!" << endl;
    player->health -= this->damage;
}

void Robot::takeAttack(MechaKurama* robot){
    cout << endl << "Bunshin Mecha Kurama menyerang Robot!" << endl;
    this->health -= robot->damage;
}
//getter
string Robot::getName(){
    return this->name;
}

double Robot::getHealth(){
    return this->health;
}

Point Robot::moveRobot(Point coordMK)
{
    MechaKurama *coorPointer;
    while (true){
        int direction;
        cout << "\nPilih arah yang akan dituju:" << endl;
        cout << "1. Maju"   <<endl;
        cout << "2. Mundur" <<endl;
        cout << "3. Kanan"  <<endl;
        cout << "4. Kiri"   <<endl;
        cout << "Pilihan (ketik angka): ";
        std::cin >> direction;
        cout << endl;
        if (direction == 1) // Maju
        {
            if (this->coord.y + 1 > 9) {
                cout << "Posisi salah (diluar peta)!" << endl;
                cout << "Silahkan pilih kembali!" << endl;
                continue;
            } else if (coordMK.y == this->coord.y + 1 && coordMK.x == this->coord.x){
                cout << "Posisi salah (menabrak Bunshin Mecha Kurama)!" << endl;
                cout << "Silahkan pilih kembali!" << endl;
                continue;
            } else {
                this->coord.y ++;
                break;
            }

        }
        else if (direction == 2) // Mundur
        {
            if (this->coord.y - 1 < 0) {
                cout << "Posisi salah (diluar peta)!" << endl;
                cout << "Silahkan pilih kembali!" << endl;
                continue;
            } else if (coordMK.y == this->coord.y - 1 && coordMK.x == this->coord.x){
                cout << "Posisi salah (menabrak Bunshin Mecha Kurama)!" << endl;
                cout << "Silahkan pilih kembali!" << endl;
                continue;
            } else {
                this->coord.y --;
                break;
            }

        }
        else if (direction == 3) // Kanan
        {
            if (this->coord.x + 1 > 9) {
                cout << "Posisi salah (diluar peta)!" << endl;
                cout << "Silahkan pilih kembali!" << endl;
                continue;
            } else if (coordMK.x == this->coord.x + 1 && coordMK.y == this->coord.y){
                cout << "Posisi salah (menabrak Bunshin Mecha Kurama)!" << endl;
                cout << "Silahkan pilih kembali!" << endl;
                continue;
            } else {
                this->coord.x ++;
                break;
            }

        }
        else if (direction == 4) // Kiri
        {
            if (this->coord.x - 1 < 0) {
                cout << "Posisi salah (diluar peta)!" << endl;
                cout << "Silahkan pilih kembali!" << endl;
                continue;
            } else if (coordMK.x == this->coord.x - 1 && coordMK.y == this->coord.y){
                cout << "Posisi salah (menabrak Bunshin Mecha Kurama)!" << endl;
                cout << "Silahkan pilih kembali!" << endl;
                continue;
            } else {
                this->coord.x --;
                break;
            }

        }
    }
    return this->coord;
}

double Robot::getDistance(Point coordMK){
    return sqrt(pow(coordMK.x - this->coord.x, 2) + pow(coordMK.y - this->coord.y, 2));
}