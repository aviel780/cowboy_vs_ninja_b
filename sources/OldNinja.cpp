#include "Character.hpp"
#include "Ninja.hpp"
#include <iostream>
#include "OldNinja.hpp"
using namespace ariel;

OldNinja::OldNinja(const std::string& name, const Point& location)
    : Ninja(name, 150, location, 8) {}

std::string OldNinja::print() const {
    // std::cout << "N - Name: " << name << ", HP: " << hitPoints << ", Location: ";
    // location.print();
    // std::cout << ", Speed: " << speed << std::endl;
    return "";
}