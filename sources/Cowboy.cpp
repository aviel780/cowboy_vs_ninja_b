#include "Character.hpp"
#include "Cowboy.hpp"
#include <iostream>
using namespace ariel;

Cowboy::Cowboy(const std::string& name, const Point& location)
    : Character(name, 110, location), bullets(6) {}

void Cowboy::shoot(Character* enemy) {
    if (enemy->isAlive() == false || isAlive() == false){
        throw std::runtime_error("the cowboys are ded");
    }
    if (isAlive() && hasBullets()) {
        enemy->hit(10);
        bullets--;
    }
}


bool Cowboy::hasBullets() const {
    return bullets > 0;
}

void Cowboy::reload() {
    if (isAlive() == false){
        throw std::runtime_error("no need to reload the cowboy are ded");
    }
    this->bullets = 6;
}

void Cowboy::CowboyAttack(Character* target) {
    if (target == nullptr) {
        throw std::invalid_argument("the terget dont exsist");
    }
   if (target->isAlive() == false || isAlive() == false){
        throw std::runtime_error("the cowboy is ded");
    }
     
    if (bullets == 0) {
        reload();
    } else {
        shoot(target);
    }
    
}

std::string Cowboy::print() const {
    std::string ans = "";
    ans += + "C - Name: " + name + ", HP: " + std::to_string(hitPoints) + ", Location: "+ location.print() + ", Bullets: " + std::to_string(bullets);
    std::cout << ans << std::endl;
    return ans;

}