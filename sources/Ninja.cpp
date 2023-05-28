#include "Character.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "Point.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace ariel;


Ninja::Ninja(const std::string& name, int hitPoints, const Point& location, int speed)
    : Character(name, hitPoints, location), speed(speed) {}

void Ninja::move(Character* move_to_location) {
    if (isAlive()) {
        double dist = distance(move_to_location);
        if (dist > 1) {
        Point newLocation = location.moveTowards(getLocation(), move_to_location->getLocation(), speed);
        setLocation(newLocation);
        }
        if(dist<=1){
            throw std::runtime_error("no need to move");
        }
    }

    if (isAlive()==false){
        throw std::runtime_error("no need to attack a ded Character");
    }

}

void Ninja::slash(Character* enemy) {   
    enemy->hit(40);
}

int Ninja::getSpeed() const{
    return this->speed;
}

std::string Ninja::print() const {
    std::string print = " " ;
    print += "Ninja: ";
    if (isAlive() == false)
         print += "(" + getName() + ")";
    else
         print +=  getName() + " - HP: " + std::to_string (this->hitPoints);
    print += " - Location: " + getLocation().print();
    
    std::cout <<print<< std::endl;
    return print;

}

void Ninja::NinjaAttack(Character* target){
    if (target == nullptr) {
        throw std::invalid_argument("the ninja done exsist");
    }
    if (isAlive()==false||target->isAlive()==false){
        throw std::runtime_error("the ninja is ded");
    }
    
    if (distance(target) <= 1){
        slash(target);
    }
    if (distance(target) > 1){
        move(target);
    }
    
}




