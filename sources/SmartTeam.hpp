#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#include <vector>
#include "Character.hpp"
#include "Team.hpp"
namespace ariel {
class SmartTeam {
private:
    std::vector<Character*> fighters;

public:
    void add(Character* fighter);
    void attack(SmartTeam* enemy);
    int stillAlive() const;
    std::string print() const;
    ~SmartTeam();
};
 }
#endif  // SMARTTEAM_HPP