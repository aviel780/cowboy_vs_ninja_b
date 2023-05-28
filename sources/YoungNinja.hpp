#ifndef YoungNinja_HPP
#define YoungNinja_HPP
#include <string>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
namespace ariel {
class YoungNinja : public Ninja {
public:
    YoungNinja(const std::string& name, const Point& location);
    std::string print() const override;
};
 }
#endif  // YoungNinja_HPP