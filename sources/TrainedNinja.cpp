#include "Character.hpp"
#include "Ninja.hpp"
#include <iostream>
#include "TrainedNinja.hpp"

using namespace ariel;



TrainedNinja::TrainedNinja(const std::string& name, const Point& location)
    : Ninja(name, 120, location, 12) {}

std::string TrainedNinja::print() const {
    // std::cout << "N - Name: " << name << ", HP: " << hitPoints << ", Location: ";
    // location.print();
    // std::cout << ", Speed: " << speed << std::endl;
    return "";
}