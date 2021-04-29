#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <stdexcept>
#include "bike.h"
#include "urban.h"
#include "delivery.h"
#include "bikes.h"

using namespace std;


class BikeFactory
{
  friend class Bikes;

  private:
    static Bike* make( istream& in ) throw ( invalid_argument );

}; // END BikeFactory class declaration

#endif // FACTORY_H