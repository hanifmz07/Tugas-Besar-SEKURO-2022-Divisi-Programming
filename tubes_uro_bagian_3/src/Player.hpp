#ifndef __PLAYER
#define __PLAYER

#include <string>
#include "Damage.hpp"

class Player{
    private:
        std::string name;
        double health;
        Damage* damage;
        int count;
        int choice;
         
    public:
        Player(const char*);
        void display();
        void attack(Player* player);
        //getter
        std::string getName();
        double getHealth();
        //setter
        void equipWeapon(Damage*);
        int getChoice();
        //void Player::repeat(); 
    private:
        void defence(double);
};

#endif