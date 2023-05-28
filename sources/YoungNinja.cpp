#include "Character.hpp"
#include "Ninja.hpp"
#include <iostream>
#include "YoungNinja.hpp"
using namespace ariel;

YoungNinja::YoungNinja(const std::string& name, const Point& location)
    : Ninja(name, 100, location, 14) {}

std::string YoungNinja::print() const {
    // std::cout << "N - Name: " << name << ", HP: " << hitPoints << ", Location: ";
    // location.print();
    // std::cout << ", Speed: " << speed << std::endl;
    return "";
}