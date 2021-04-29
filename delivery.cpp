#include "delivery.h"

Delivery:: Delivery():Bike()
{
    setID("D00");
    setCapacity(1);
}

Delivery:: Delivery( string id, string name, int gears, int capacity ) throw ( invalid_argument ): 
           Bike(id, name, gears)
{
    setID(id);
    setCapacity(capacity);
}

void Delivery:: setID( string id ) throw ( invalid_argument )
{
    //checks 23 and valid length (exactly 3 characters)
    Bike::setID(id);
    
    //check 1, 12, 13, 123
    if( !(toupper(id.at(0)) == 'D' && isdigit(id.at(1)) && isdigit(id.at(2))) )
    {
        if ( toupper(id.at(0)) != 'D' && (isdigit(id.at(1))) && (isdigit(id.at(2))) )
        {
            throw invalid_argument("First character of id is invalid");
        }
        /*
        //else if( toupper(id.at(0)) == 'D' && !(isdigit(id.at(1))) && (isdigit(id.at(2))) )
        //{
        //    throw invalid_argument("Second character of id is invalid");
        //}
        //else if( toupper(id.at(0)) == 'D' && (isdigit(id.at(1))) && !(isdigit(id.at(2))) )
        //{
        //    throw invalid_argument("Third character of id is invalid");
        //}
        */ 
        else if( toupper(id.at(0)) != 'D' && !(isdigit(id.at(1))) && (isdigit(id.at(2))) )
        {
            throw invalid_argument("First and second characters of id are invalid");
        }
        else if( toupper(id.at(0)) != 'D' && (isdigit(id.at(1))) && !(isdigit(id.at(2))) )
        {
            throw invalid_argument("First and third characters of id are invalid");
        }
        /*
        //else if( toupper(id.at(0)) == 'D' && !(isdigit(id.at(1))) && !(isdigit(id.at(2))) )
        //{
        //   throw invalid_argument("Second and third characters of id are invalid");
        //}
        */ 
        else if( toupper(id.at(0)) != 'D' && !(isdigit(id.at(1))) && !(isdigit(id.at(2))) )
        {
            throw invalid_argument("All characters of id are invalid");
        }
    }
    
    this->id = id;
}

void Delivery:: setCapacity( int capacity ) throw ( invalid_argument )
{
    if(capacity < 1 || capacity > 120)
    {
        throw invalid_argument ("Invalid bike capacity.");
    }

    this->capacity = capacity;
}

int Delivery:: getCapacity() const
{
    return capacity;
}

void Delivery:: print( ostream &out ) const
{
    Bike::print(out);
    out << "Capacity: " << capacity << endl;
}

void Delivery:: read( istream &in ) throw ( invalid_argument )
{
    int capacity = 1;
    
    Bike::read(in);
    
    if(in)
    {
        in >> capacity;
        setCapacity(capacity);
    }
    //make sure ID is that of a delivery bike
    setID(getID());
}