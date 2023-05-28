#ifndef TEAM2_HPP
#define TEAM2_HPP

#include <vector>
#include "Character.hpp"
namespace ariel {
class Team2 {
private:
    std::vector<Character*> fighters;

public:
    void add(Character* fighter);
    void attack(Team2* enemy);
    int stillAlive() const;
    std::string print() const;
    ~Team2();
};
 }
#endif  // TEAM2_HPP