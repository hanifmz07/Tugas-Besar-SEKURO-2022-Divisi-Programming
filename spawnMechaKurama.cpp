#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

Point initRange(){
    srand(time(0));
    int a, b;
    a = rand() % 5 + 1;
    b = rand() % 5 + 1;
    return {a, b};
};
// Lebih baik jika range dalam bentuk satu nilai saja

class MechaKurama{
    public:
        Point coor;
        int health;
        int damage;
        Point range;

        // Constructor
        MechaKurama(int health, int damage, Point range){
            this->coor = initRobot();
            this->health = health;
            this->damage = damage;
            this->range = range;
            cout << "Bunshin Mecha Kurama muncul di medan perang!" << endl; 
        }

        Point initRobot(){
            srand(time(0));
            int a, b;
            a = rand() % 9 + 1;
            b = rand() % 9 + 1;
            return {a, b};
        };

        int getHealth(){
            return this->health;
        }

        int getDamage(){
            return this->damage;
        }

        Point getRange(){
            return this->range;
        }

        // Destructor
        ~MechaKurama(){
            cout << "Bunshin Mecha Kurama berhasil dikalahkan!" << endl;
        }

};

void createBunshin(MechaKurama* &pointerMK){
    srand(time(0));
    int health, damage;
    Point range;

    health = rand() % 40 + 80;
    damage = rand() % 10 + 5;
    range = initRange();
    
    MechaKurama* bunshinMechaKurama = new MechaKurama(health, damage, range);
    pointerMK = bunshinMechaKurama;
}

void printBattlefield(Point mechaKurama, Point robot){
    for (int i = 0; i < 10; i++){
        
        for (int j = 0; j < 10; j++){
            
            if (i == mechaKurama.y && j == mechaKurama.x){
                cout << 'M' << " ";
            } 
            else if (i == robot.y && j == robot.x){
                cout << 'R' << " ";
            } 
            else{
                cout << "-" << " ";
            }
            
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    int exit = 0;
    while (exit == 0){
        MechaKurama *pointerMK;
        createBunshin(pointerMK);
        cout << "Koordinat: " << pointerMK->coor.x << " " << pointerMK->coor.y << endl;
        cout << "Health: " << pointerMK->getHealth() << endl;
        cout << "Damage: " << pointerMK->getDamage() << endl;
        cout << "Range: " << pointerMK->getRange().x << " " << pointerMK->getRange().y << endl;
        printBattlefield(pointerMK->coor, {0,0});
        delete pointerMK;
        cin >> exit;
        /*
        if (pointerMK->getHealth() <= 0) {
            pointerMK->health = 0;
            delete pointerMK;
        }
        */
    }
    
    return 0;
}
