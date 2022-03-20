#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "classes.hpp"
#include <stdlib.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
  
void fun(void) { cout << "Exiting"; }

Point initRange(){
    srand(time(0));
    int a, b;
    a = rand() % 3 + 1;
    b = rand() % 3 + 1;
    return {a, b};
};

void createBunshin(MechaKurama* &pointerMK){
    srand(time(0));
    int health, damage;
    Point range;

    health = rand() % 40 + 80;
    damage = rand() % 30 + 10;
    range = initRange();
    
    MechaKurama* bunshinMechaKurama = new MechaKurama(health, damage, range);
    pointerMK = bunshinMechaKurama;
}

void createRobot(Robot* &pointerR){
    Robot* robot = new Robot("Robot");
    pointerR = robot;
}

void printBattlefield(Point mechaKurama, Point robot, MechaKurama *pointerMK){
    for (int i = 0; i < 10; i++){
        
        for (int j = 0; j < 10; j++){
            
            if (i == 9 - mechaKurama.y && j == mechaKurama.x){
                cout << 'M' << " ";
            } 
            else if (i == 9 - robot.y && j == robot.x){
                cout << 'R' << " ";
            } else if ((i <= 9 - mechaKurama.y + pointerMK->range.y && i >= 9 - mechaKurama.y - pointerMK->range.y) && (j <= mechaKurama.x + pointerMK->range.x && j >= mechaKurama.x - pointerMK->range.x)) {
                cout << 'x' << " ";
            } else {
                cout << "-" << " ";
            }
            
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    Robot *pointerR;
    createRobot(pointerR);
    
    int choice;
    int direction;
    int exit = 0;
    bool MKdead = true;
    bool attackAvailability;
    
    while (exit == 0){
        MechaKurama *pointerMK;
        if (MKdead) {
            createBunshin(pointerMK);
            
            // Jika koordinat bunshin sama dengan koordinat robot, koordinat bunshin akan diacak lagi
            while (pointerMK->coor.x == pointerR->coord.x && pointerMK->coor.y == pointerR->coord.y) {
                pointerMK->coor = pointerMK->initRobot();
            }

            cout << "Bunshin Mecha Kurama muncul di medan perang!" << endl;
            cout << "Koordinat: " << pointerMK->coor.x << " " << pointerMK->coor.y << endl;
            cout << "Health: " << pointerMK->getHealth() << endl;
            cout << "Damage: " << pointerMK->getDamage() << endl;
            cout << "Range (x, y): " << pointerMK->getRange().x << " " << pointerMK->getRange().y << endl;
            MKdead = false;
        }
        
        cout << "\nJarak Robot dengan Bunshin Mecha Kurama: " << pointerR->getDistance(pointerMK->coor) << endl;
        if (pointerR->getDistance(pointerMK->coor) > 3){
            attackAvailability = false;
            cout << "PERINGATAN!: Bunshin Mecha Kurama diluar jangkauan senjata Robot." << endl;
        } else {
            attackAvailability = true;
        }
        
        printBattlefield(pointerMK->coor, pointerR->coord, pointerMK);
        
        cout << "\nMau serang atau jalan?" << endl;
        cout << "Serang (ketik 1)" << endl;
        cout << "Jalan (ketik 2)" << endl;
        cout << "Exit Program (ketik 3)" << endl;
        
        while (true) {
            cin >> choice;
            if (choice == 1) {
                
                if (attackAvailability) {
                    pointerR->attack(pointerMK);
                    
                    if (pointerMK->health < 0) {
                        pointerMK->health = 0;
                    }
                    cout << "Health Bunshin: " << pointerMK->getHealth() << endl;
                    
                    break;
                } else {
                    cout << "WARNING!: OUT OF RANGE" << endl;
                }
                
            } else if (choice == 2) {
                pointerR->moveRobot(pointerMK->coor);
                break;
            } else if (choice == 3) {
                atexit(fun);
                cout << "Jumlah bunshin yang telah dibunuh: " << pointerR->count << endl;
                _Exit(10);
            } else {
                cout << "Input salah, mohon melakukan input kembali." << endl;
            }
            
        }
        if (pointerMK->getHealth() <= 0) {
            MKdead = true;
            pointerR->count += 1;
            delete pointerMK;
            cout << endl;
            continue;
        }
        
        if ((pointerR->coord.x >= pointerMK->coor.x - pointerMK->range.x && pointerR->coord.x <= pointerMK->coor.x + pointerMK->range.x) && (pointerR->coord.y >= pointerMK->coor.y - pointerMK->range.y && pointerR->coord.y <= pointerMK->coor.y + pointerMK->range.y)) {
            pointerR->takeAttack(pointerMK);
            if (pointerR->health < 0) {
                pointerR->health = 0;
                cout << "Health Robot: " << pointerR->health << endl;
                cout << endl;
                cout << "Robot telah hancur dengan cara terhormat...\n";
                break;
            }
            cout << "Health Robot: " << pointerR->health << endl;
            cout << endl;
        }
    }
    cout << "Jumlah bunshin yang telah dibunuh: " << pointerR->count << endl;
    return 0;
}
