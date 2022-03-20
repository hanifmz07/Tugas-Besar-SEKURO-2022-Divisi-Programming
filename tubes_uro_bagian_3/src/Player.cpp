#include <iostream>
#include <string>
#include "Damage.hpp"
#include "Player.hpp"

Player::Player(const char* name){
    this->name = name;
    this->health = 100;
    this->count = 0;
    this->choice = 1;
}

void Player::display(){
    std::cout << "\nName\t: " << this->name << std::endl;
    std::cout << "Health\t: " << this->health << std::endl;
    std::cout << "Power\t: "<< this->damage->getPower() << std::endl;
    //std::cout << "Kills\t: " << this->count << std::endl;
}

void Player::attack(Player* player){
    int choice; 
    while(this->health > 0){
        std::cout << "\nMau serang atau maju?" << std::endl;
        std::cout << "Serang (ketik 1)" << std::endl;
        std::cout << "Maju (ketik 2)" << std::endl;
        if(player->health <= 0){
            this->count += 1;
            std::cout << player->name << " meninggal" << std::endl;

            // disini isi sama fungsi random bunshin lagi
        }
        std::cin >> choice;
        if (choice == 1){
            std::cout << std::endl << this->name << " menyerang " << player->getName() << std::endl;
            player->defence(this->damage->getPower());
            std::cout << "\nName\t: " << player->getName() << std::endl;
            std::cout << "Health\t: " << player->health << std::endl;
            std::cout << "Power\t: "<< player->damage->getPower() << std::endl;

            std::cout << std::endl << player->getName() << " menyerang " << this->name << std::endl;
            this->defence(player->damage->getPower());
            std::cout << "\nName\t: " << this->name << std::endl;
            std::cout << "Health\t: " << this->health << std::endl;
            std::cout << "Power\t: "<< this->damage->getPower() << std::endl;
        }

        /*
        Masukin fungsi maju
        else if(choice == 2){

        }
        else{
            std::cout << "Input tidak sesuai" << std::endl;
        }
        */
    }
    std::cout << this->name << " meninggal" << std::endl;
    std::cout << "Kills\t:  " << this->count << std::endl;
}

//getter
std::string Player::getName(){
    return this->name;
}

//setter
void Player::equipWeapon(Damage* damage){
    this->damage = damage;
}

double Player::getHealth(){
    return this->health;
}

void Player::defence(double damage){
    if(this->health > 0){
        this->health -= damage;
        std::cout << this->name << " mendapatkan damage : " << damage << std::endl;
    }
}