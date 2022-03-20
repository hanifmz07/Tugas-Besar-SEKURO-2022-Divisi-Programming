#include <iostream>
#include <string>
#include "Damage.hpp"
#include "Player.hpp"

using namespace std;

Player::Player(const char* name){
    this->name = name;
    this->health = 100;
    this->count = 0;
    this->choice = 1;
}

void Player::display(){
    cout << "\nName\t: " << this->name << endl;
    cout << "Health\t: " << this->health << endl;
    cout << "Power\t: "<< this->damage->getPower() << endl;
    //cout << "Kills\t: " << this->count << endl;
}

void Player::attack(Player* player){
    int choice; 
    while(this->health > 0){
        cout << "\nMau serang atau maju?" << endl;
        cout << "Serang (ketik 1)" << endl;
        cout << "Maju (ketik 2)" << endl;
        if(player->health <= 0){
            this->count += 1;
            cout << player->name << " meninggal" << endl;

            // disini isi sama fungsi random bunshin lagi
        }
        cin >> choice;
        if (choice == 1){
            cout << endl << this->name << " menyerang " << player->getName() << endl;
            player->defence(this->damage->getPower());
            cout << "\nName\t: " << player->getName() << endl;
            cout << "Health\t: " << player->health << endl;
            cout << "Power\t: "<< player->damage->getPower() << endl;

            cout << endl << player->getName() << " menyerang " << this->name << endl;
            this->defence(player->damage->getPower());
            cout << "\nName\t: " << this->name << endl;
            cout << "Health\t: " << this->health << endl;
            cout << "Power\t: "<< this->damage->getPower() << endl;
        }

        /*
        Masukin fungsi maju
        else if(choice == 2){

        }
        else{
            cout << "Input tidak sesuai" << endl;
        }
        */
    }
    cout << this->name << " meninggal" << endl;
    cout << "Kills\t:  " << this->count << endl;
}

//getter
string Player::getName(){
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
        cout << this->name << " mendapatkan damage : " << damage << endl;
    }
}