#ifndef __MECHAKURAMA
#define __MECHAKURAMA
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>

using namespace std;

struct Point {
    int x, y;
};

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
        }

        Point initRobot(){
            srand(time(0));
            int a, b;
            a = rand() % 9;
            b = rand() % 9;
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

class Robot {
    public:
        // Deklarasi Array Posisi (sb.x dan sb.y)
        Point coord;
        int count;
        int health;
        int damage;
        Robot(string name){
            this->name = name;
            this->health = 100;
            this->count = 0;
            this->coord.x = 0;
            this->coord.y = 0;
            this->damage = 50;
            this->range = 3;
        }

        // Deklarasi fungsi moveRobot
        Point moveRobot(Point); 

        // Fungsi menampilkan posisi awal
        void showPoint(){
            cout << this->coord.x << " " << this->coord.y << endl;
        }
        
        void display();
        void attack(MechaKurama*);
        void takeAttack(MechaKurama*);
        //getter
        std::string getName();
        double getHealth();
        int getChoice();
        double getDistance(Point);

    
    private:
        std::string name;
        int choice;
        double range;
};

#endif