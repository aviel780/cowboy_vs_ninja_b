#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "Point.hpp"
#include <vector>

enum SortOrder {
    HIT_POINTS_ASCENDING = 0,
    HIT_POINTS_DESCENDING = 1,
    C_TO_N = 2
};

 
namespace ariel {
class Character {
protected:
    std::string name;
    int hitPoints;
    Point location;
    bool have_team;
    bool is_capten;

public:
    Character(const std::string name, int hitPoints, const Point location);
    bool isAlive() const;
    double distance(const Character* other) const;
    void hit(int damage);
    std::string getName() const;
    Point getLocation() const;
    virtual std::string print() const = 0;

    bool ch_have_team() const;
    void set_ch_have_team();
    bool capten_of_team() const;
    void set_capten_of_team();
    void setLocation(Point new_location);
    virtual ~Character() = default; 
    int getHit() const;
    void setHit(int);

};

 }

#endif  // CHARACTER_HPP
