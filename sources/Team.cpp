#include "Team.hpp"
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <limits>
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Cowboy.hpp"
using namespace ariel;



Team::Team(Character* leader) : leader(leader) {}

void Team::add(Character* fighter) {
    fighters.push_back(fighter);
}

void Team::attack(Team* enemy) {
    if (!leader->isAlive()) {
        // Find the living character closest to the dead leader
        double minDistance = std::numeric_limits<double>::max();
        Character* newLeader = nullptr;

        for (Character* fighter : fighters) {
            if (fighter->isAlive() && fighter != leader) {
                double dist = leader->distance(fighter);
                if (dist < minDistance) {
                    minDistance = dist;
                    newLeader = fighter;
                }
            }
        }

        if (newLeader)
            leader = newLeader;
    }

    Character* victim = nullptr;

    while (leader->isAlive() && enemy->stillAlive()) {
        // Find the living enemy closest to the leader
        double minDistance = std::numeric_limits<double>::max();

        for (Character* enemyFighter : enemy->fighters) {
            if (enemyFighter->isAlive()) {
                double dist = leader->distance(enemyFighter);
                if (dist < minDistance) {
                    minDistance = dist;
                    victim = enemyFighter;
                }
            }
        }

        if (!victim)
            break;

        for (Character* fighter : fighters) {
            if (fighter->isAlive()) {
                Cowboy* cowboy = dynamic_cast<Cowboy*>(fighter);
                if (cowboy && cowboy->hasBullets()) {
                    cowboy->shoot(victim);
                } else if (cowboy) {
                    cowboy->reload();
                } else {
                    Ninja* ninja = dynamic_cast<Ninja*>(fighter);
                    if (ninja)
                        ninja->move(victim);
                }
            }
        }

        if (!victim->isAlive()) {
            victim = nullptr;
        }
    }
}

int Team::stillAlive() const {
    int aliveCount = 0;
    for (Character* fighter : fighters) {
        if (fighter->isAlive())
            aliveCount++;
    }
    return aliveCount;
}

std::string Team::print() const {
    // for (Character* fighter : fighters) {
    //     fighter->print();
    // }
    return "";
}

Team::~Team() {
    // for (Character* fighter : fighters) {
    //     delete fighter;
    // }
}