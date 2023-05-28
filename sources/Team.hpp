#ifndef TEAM_HPP
#define TEAM_HPP

#include <vector>
#include "Character.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Cowboy.hpp"
namespace ariel {
class Team {
private:
    Character* leader;
    std::vector<Character*> fighters;

public:
    Team(Character* leader);
    void add(Character* fighter);
    void attack(Team* enemy);
    int stillAlive() const;
    std::string print() const;
    ~Team();
};
 }

#endif  // TEAM_HPP