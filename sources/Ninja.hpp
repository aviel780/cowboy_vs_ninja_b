#ifndef Ninja_HPP
#define Ninja_HPP
#include <string>
#include "Point.hpp"
#include "Character.hpp"


 
namespace ariel {
class Ninja : public Character {

private:
    int speed;

public:
    Ninja(const std::string& name, int hitPoints, const Point& location, int speed);
    void move(Character* move_to_location);
    void slash(Character* attack_damge);
    std::string print() const override;
    ~Ninja() override = default;
    
    int getSpeed() const;
    void NinjaAttack(Character* attack_enemy);
};

 }

#endif  // Ninja_HPP