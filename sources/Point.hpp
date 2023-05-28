#ifndef POINT_HPP
#define POINT_HPP
#include <string>

namespace ariel {

class Point {
private:
    double x;
    double y;

public:
    Point(double x, double y);
    double distance(const Point& other) const;
    std::string print() const;
    Point moveTowards(const Point& source, const Point& destination, double distance) const;
};

 }

#endif  // POINT_HPP