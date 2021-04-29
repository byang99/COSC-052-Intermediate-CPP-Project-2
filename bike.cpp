#include "bike.h"

Bike:: Bike()
{
    setID("A00");
    setName(" ");
    setGears(1);
}

Bike::Bike( string id, string name, int gears ) throw ( invalid_argument )
{
    setID(id);
    setName(name);
    setGears(gears);
}

Bike:: ~Bike()
{
    //cout << "Inside destructor for Bike class." << endl;
}

string Bike:: getID() const
{
    return id;
}

string Bike:: getName() const
{
    return name;
}

int Bike:: getGears() const
{
    return gears;
}

void Bike:: setGears( int gears ) throw ( invalid_argument )
{
    if(gears < 1 || gears > 24)
    {
        throw invalid_argument ("Invalid number of gears.");
    }

    this->gears = gears;    
}

void Bike:: setID( string id ) throw ( invalid_argument )
{
    //test for invalid length ID is not 3 characters long
    if(id.size() != 3)
    {
        //id is too long (more than 3 characters)
        if (id.size() > 3)
        {
            throw invalid_argument("ID is too long.");
        }
        //id is too short (less than 3 characters)
        else if (id.size() < 3)
        {
            throw invalid_argument("ID is too short.");
        }
    }
    //if length is valid, test for content [A-Z][0-9][0-9]
    else if(id.size() == 3)
    {
        //if NOT (uppercase letter AND digit AND digit)
        if( !( isupper(id.at(0)) && isdigit(id.at(1)) && isdigit(id.at(2)) ) )
        {
            if( !(isupper(id.at(0))) && (isdigit(id.at(1))) && (isdigit(id.at(2))) )
            {
                throw invalid_argument("First character of id is invalid");
            }
            else if( (isupper(id.at(0))) && !(isdigit(id.at(1))) && (isdigit(id.at(2))) )
            {
                throw invalid_argument("Second character of id is invalid");
            }
            else if( (isupper(id.at(0))) && (isdigit(id.at(1))) && !(isdigit(id.at(2))) )
            {
                throw invalid_argument("Third character of id is invalid");
            }
            else if( !(isupper(id.at(0))) && !(isdigit(id.at(1))) && (isdigit(id.at(2))) )
            {
                throw invalid_argument("First and second characters of id are invalid");
            }
            else if( !(isupper(id.at(0))) && (isdigit(id.at(1))) && !(isdigit(id.at(2))) )
            {
                throw invalid_argument("First and third characters of id are invalid");
            }
            else if( (isupper(id.at(0))) && !(isdigit(id.at(1))) && !(isdigit(id.at(2))) )
            {
                throw invalid_argument("Second and third characters of id are invalid");
            }
            else if( !(isupper(id.at(0))) && !(isdigit(id.at(1))) && !(isdigit(id.at(2))) )
            {
                throw invalid_argument("All characters of id are invalid");
            }
        }
    }
    
    this->id = id;  
}

void Bike:: setName( string name )
{
    this->name = name;
}

void Bike:: print( ostream& out ) const
{
    //out << "ID: " << id << endl;
    out << "Name: " << name << endl;
    out << "Number of gears: " << gears << endl;
}

void Bike:: read( istream& in ) throw ( invalid_argument )
{
    string id = "";
    int gears = 1;
    
    //read ID
    if(in >> id)
    {
        setID(id);
        //cout << "ID: " << id << endl;
        
        //read double quoted string: Read name
        char quotation = ' ';
        string name = "";
        in >> quotation;
        getline(in, name, '"');
        setName(name);
        
        //cout << "Name: " << name << endl;
        
        //read gears
        in >> gears;
        setGears(gears);      
        //cout << "Gears: " << gears << endl;
    }
}