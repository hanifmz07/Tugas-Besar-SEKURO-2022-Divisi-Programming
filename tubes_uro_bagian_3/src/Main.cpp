#include <iostream>
#include <string>

#include "Player.hpp"
#include "Damage.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Player* robot = new Player("Robot");
    Damage* damage1 = new Damage(60);
    robot->equipWeapon(damage1);
    robot->display();
    
    Player* kurama = new Player("Bunshin Kurama");
    Damage* damage2 = new Damage(30);
    kurama->equipWeapon(damage2);
    kurama->display();

    robot->attack(kurama);
    
    /*
    kurama->attack(robot);
    robot->display();
    kurama->display();
    */  
    
    //robot->repeat();
    //robot->getChoice(kurama);
/*
    robot->attack(kurama);
    kurama->attack(robot);
    robot->display();
    kurama->display();
    robot->attack(kurama);
    kurama->attack(robot);
    robot->display();
    kurama->display();
*/
    return 0;
}