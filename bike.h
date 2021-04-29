#ifndef BIKE_H
#define BIKE_H

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <stdexcept>

#include <sstream>

using namespace std;


class Bike
{
  public:
    Bike();
    Bike( string id, string name, int gears ) throw ( invalid_argument );
    void setID( string id ) throw ( invalid_argument );
    void setName( string name );
    void setGears( int gears ) throw ( invalid_argument );
    string getID() const;
    string getName() const;
    int getGears() const;
    virtual void print( ostream& out = cout ) const;
    virtual void read( istream& in ) throw ( invalid_argument );
    virtual ~Bike();

  protected:
    string id;
    string name;
    int gears;

}; // END Bike class declaration

#endif // BIKE_H