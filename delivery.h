#ifndef DELIVERY_H
#define DELIVERY_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "bike.h"

using namespace std;


class Delivery : public Bike
{
  public:
    Delivery();
    Delivery( string id, string name, int gears, int capacity ) throw ( invalid_argument );
    void setID( string id ) throw ( invalid_argument );
    void setCapacity( int capacity ) throw ( invalid_argument );
    int getCapacity() const;
    virtual void print( ostream &out = cout ) const;
    virtual void read( istream &in ) throw ( invalid_argument );

  protected:
    int capacity;

}; // END Delivery class declaration

#endif // DELIVERY_H