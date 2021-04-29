#include "urban.h"

Urban:: Urban():Bike()
{
    //cout << "Calling Bike default constructor" << endl;
    setID("U00");
}

Urban:: Urban( string id, string name, int gears ) throw ( invalid_argument ):
        Bike(id, name, gears)
{   
    setID(id);
}

void Urban:: setID( string id ) throw ( invalid_argument )
{
    //checks 23
    Bike::setID(id);
    
    //check 1, 12, 13, 123
    if( !(toupper(id.at(0)) == 'U' && isdigit(id.at(1)) && isdigit(id.at(2))) )
    {
        if ( toupper(id.at(0)) != 'U' && (isdigit(id.at(1))) && (isdigit(id.at(2))) )
        {
            throw invalid_argument("First character of id is invalid");
        }
        //else if( toupper(id.at(0)) == 'U' && !(isdigit(id.at(1))) && (isdigit(id.at(2))) )
        //{
        //    throw invalid_argument("Second character of id is invalid");
        //}
        //else if( toupper(id.at(0)) == 'U' && (isdigit(id.at(1))) && !(isdigit(id.at(2))) )
        //{
        //    throw invalid_argument("Third character of id is invalid");
        //}
        else if( toupper(id.at(0)) != 'U' && !(isdigit(id.at(1))) && (isdigit(id.at(2))) )
        {
            throw invalid_argument("First and second characters of id are invalid");
        }
        else if( toupper(id.at(0)) != 'U' && (isdigit(id.at(1))) && !(isdigit(id.at(2))) )
        {
            throw invalid_argument("First and third characters of id are invalid");
        }
        //else if( toupper(id.at(0)) == 'U' && !(isdigit(id.at(1))) && !(isdigit(id.at(2))) )
        //{
        //    throw invalid_argument("Second and third characters of id are invalid");
        //}
        else if( toupper(id.at(0)) != 'U' && !(isdigit(id.at(1))) && !(isdigit(id.at(2))) )
        {
            throw invalid_argument("All characters of id are invalid");
        }
    }

    this->id = id;
}

void Urban:: print( ostream &out) const
{
    Bike::print(out);
}

void Urban::read( istream &in ) throw ( invalid_argument )
{
    // NOT A REQUIREMENT: store current values of object in local variable
    Urban oldBike = *this;

    try 
    {
        // call the parent class read method
        Bike::read( in );
  
        // call setID for derived class to complete more
        // refined validation testing
        setID( id );
        
        // if there were other derived class data members, 
        // call derived class read and setter methods here 
  
    } // END try
  
  
    // NOT A REQUIREMENT: if anything goes wrong with read/setter methods
    //                    restore object's original values, 
    //                    re-throw exception
    
    catch ( invalid_argument &e )
    {
  
        *this = oldBike;
        throw;

    } // END catch
  
} // END Urban::read