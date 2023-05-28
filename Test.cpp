#include <iostream>

#include "sources/Point.hpp"
#include "sources/Character.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"
#include "sources/Ninja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/OldNinja.hpp"
#include <stdexcept>
#include "doctest.h"
#include "sources/Cowboy.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>



using namespace ariel;
using namespace std;





TEST_CASE("Point constructors"){
    CHECK_NOTHROW(Point(6.1,4.52));
    CHECK_NOTHROW(Point(-35.12,0.1));
}

TEST_CASE("points mathods"){
      Point p1(0.0, 0.0);
  Point p2(3.0, 4.0);
  Point p3(-5.0, 4.7);

 CHECK_NOTHROW( p1.distance(p2));
 CHECK_NOTHROW( p2.distance(p3));
 CHECK_NOTHROW( p1.distance(p3));
 CHECK_NOTHROW( p2.distance(p2));
   }

  TEST_CASE("create chercters"){
      Point p1(0.0, 0.0);
  Point p2(3.0, 4.0);
  Point p3(-5.0, 4.7);
  Ninja ninja("Ryu",150, p2,12);
Cowboy cowboy("John", p1);
TrainedNinja ninja_R("Ryu", p2);
OldNinja ninja_O("oldRyu", p3);
  CHECK_NOTHROW( Cowboy cowboy("John", p1));
  CHECK_NOTHROW(TrainedNinja ninja_R("Ryu", p2));
  CHECK_NOTHROW(OldNinja ninja_O("oldRyu", p3));
  CHECK_NOTHROW(YoungNinja ninja_RY("Ryu", p2));
  CHECK_NOTHROW(Ninja ninja("Ryu",150, p2,12));

  CHECK_NOTHROW(ninja.getName());
  CHECK_NOTHROW( ninja_O.isAlive());
  CHECK_NOTHROW( cowboy.getLocation());
  CHECK_NOTHROW(ninja.hit(20));
  CHECK_NOTHROW( cowboy.hit(15));
  CHECK_NOTHROW(ninja.slash(&cowboy));
  CHECK_NOTHROW(cowboy.hasBullets());
  CHECK_NOTHROW(cowboy.reload());
  CHECK_NOTHROW(ninja_R.getLocation());

  
  
}

