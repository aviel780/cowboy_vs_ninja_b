#include "Team2.hpp"
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <limits>
#include "Ninja.hpp"
#include "Cowboy.hpp"

using namespace ariel;


void Team2::add(Character* fighter) {
    fighters.push_back(fighter);
}

void Team2::attack(Team2* enemy) {
    Character* leader = fighters[0];
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

int Team2::stillAlive() const {
    int aliveCount = 0;
    for (Character* fighter : fighters) {
        if (fighter->isAlive())
            aliveCount++;
    }
    return aliveCount;
}

std::string Team2::print() const {
    // for (Character* fighter : fighters) {
    //     fighter->print();
    // }
    return "";
}

Team2::~Team2() {
    // for (Character* fighter : fighters) {
    //     delete fighter;
    // }
}