#ifndef TrainedNinja_HPP
#define TrainedNinja_HPP
#include <string>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
namespace ariel {
class TrainedNinja : public Ninja {
public:
    TrainedNinja(const std::string& name, const Point& location);
    std::string print() const override;
};
 }

#endif  // TrainedNinja_HPP