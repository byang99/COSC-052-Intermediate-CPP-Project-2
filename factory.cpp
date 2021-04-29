#include "factory.h"

Bike* BikeFactory:: make(istream& in) throw (invalid_argument)
{
    Bike* bikePtr = NULL;
    char letter = ' ';
    bool allDone = false;
    // check to see type of the next bike in the stream by looking at the first character       
    in >> letter;                            
    if (in)
    {
        // return that character to the stream
        in.putback(letter);
        cout << "(Factory::Make) Letter: " << letter << endl;
        // dynamically allocated an object of the appropriate type and call its 
        // polymorphic read method to extract the next data row from the stream  
        // find the id of the first data file record
        if( toupper(letter) == 'U' )
        {
            bikePtr = new Urban;
        }
        else if( toupper(letter) == 'D' )
        {
            bikePtr = new Delivery;
        }
        else
        {
            throw invalid_argument ("Code does not match any known bike");
            allDone = true;
        }

        //if bike type is valid, invoke the polymorphic read method 
        //in Bike class of the dynamically allocated bike object 
        if(!allDone)
        {
            cout << "Calling read function. (Factory:: Make)" << endl;
            bikePtr->read(in);
        }
    }
    
    return bikePtr;
}