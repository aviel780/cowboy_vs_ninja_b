#ifndef Cowboy_HPP
#define Cowboy_HPP

#include <string>
#include "Point.hpp"
#include "Character.hpp"

namespace ariel {
class Cowboy : public Character {
private:
    int bullets;

public:
    Cowboy(const std::string& name, const Point& location);
    void shoot(Character* enemy);
    bool hasBullets() const;
    
    void reload();
    std::string print() const override;
    ~Cowboy() override = default;
    void CowboyAttack(Character* target);
};
}

#endif  // Cowboy_HPP