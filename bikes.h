#ifndef BIKES_H
#define BIKES_H

#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <cmath>
#include "bike.h"
#include "urban.h"
#include "delivery.h"
#include "factory.h"

using namespace std;


class Bikes
{

  public:
    Bikes();
    int getTotalGears() const;
    int getTotalCapacity() const;
    void print( ostream &out = cout ) const;
    void read( string filename ) throw ( logic_error, invalid_argument );
    unsigned size() const;
    ~Bikes();

  private:
    vector<Bike *> bikes;

}; // END Bikes class declaration

#endif // BIKES_H