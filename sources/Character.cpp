#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace ariel;

Character::Character(const std::string name, int hitPoints, const Point location)
    : name(name), hitPoints(hitPoints), location(location) {
        this->name = name;
        this->location = location;
        this->hitPoints;
        this->have_team;
        this->is_capten;
    }

bool Character::isAlive() const {
    return hitPoints > 0;
}

double Character::distance(const Character* other) const {
    return getLocation().distance(other->location);
}

//set the damge from the hit
void Character::hit(int damage) {
    if (damage < 0){
        throw std::invalid_argument("error- the damge mast be more then 0.");
    }
    this->hitPoints -= damage;
    if ( this->hitPoints -= damage < 0)
         this->hitPoints -= damage = 0;
}

int Character::getHit() const{
    return this->hitPoints;
}

std::string Character::getName() const {
    return this->name;
}

Point Character::getLocation() const {
    return this->location;
}

bool Character::ch_have_team() const{
    return this->have_team;
}

void Character::set_ch_have_team(){
    this->have_team = true;
}

bool Character::capten_of_team() const{
    return this->is_capten;
}

void Character::set_capten_of_team(){
    this->is_capten = true;
}

void Character::setLocation(Point new_loc){
    this->location = new_loc;
}




