#include "Point.hpp"
#include <iostream>
#include <cmath>
using namespace ariel;

Point::Point(double x, double y) : x(x), y(y) {}

double Point::distance(const Point& other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    return std::sqrt(dx * dx + dy * dy);
}

std::string Point::print() const {
    std::string ans = ""; 
    ans += "(" + std::to_string(x)  + "," + std::to_string(y) + ")";
    std::cout << "(" << x << ", " << y << ")";
    return ans;
}

Point Point::moveTowards(const Point& source, const Point& destination, double distance) const {
    double dx = destination.x - source.x;
    double dy = destination.y - source.y;
    double currentDistance = std::sqrt(dx * dx + dy * dy);

    if (currentDistance <= distance)
        return destination;

    double ratio = distance / currentDistance;
    double newX = source.x + dx * ratio;
    double newY = source.y + dy * ratio;

    return Point(newX, newY);
}