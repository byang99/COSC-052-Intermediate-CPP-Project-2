#include "bikes.h"

Bikes:: Bikes()
{
    bikes = {};
}

Bikes:: ~Bikes()
{
    cout << "Inside destructor for Bikes class..." << endl;
    unsigned long deleteCount = 0;                                                   
    cout << "Executing loop to deallocate dynamically allocated memory..." << endl;
    cout << endl;
    cout << "Initial size of vector: " << bikes.size() << endl;
    
    // deallocate dynamically allocated memory, starting from the end of the vector
    for ( int i = bikes.size()-1; i >= 0; i-- )                               
    {
        //cout << "I: " << i << endl;
        delete bikes.at(i);                                                           
        deleteCount++;                                                               
    }
    
    bikes.clear();
    
    cout << deleteCount << " objects deleted and memory deallocated." << endl;
    cout << "Final size of vector: " << bikes.size() << endl;
}

int Bikes:: getTotalGears() const
{
    cout << "Total number of gears: ";
    int totalGears = 0;
    for( unsigned long i = 0; i < bikes.size(); i++ )
    {
        totalGears = totalGears + bikes.at(i)->getGears();
    }
    return totalGears;
}

int Bikes:: getTotalCapacity() const
{
    cout << "Total carrying capacity of all delivery bikes: ";
    //counter variable
    int totalCapacity = 0;
    
    for( unsigned long i = 0; i < bikes.size(); i++ )
    {
        //dynamically cast the the pointer at bikes.at(i) to a Delivery pointer
        Delivery* deliveryPtr = dynamic_cast <Delivery*> (bikes.at(i));
        
        //if object is delivery bike (pointer can be cast to a delivery pointer)
        if(deliveryPtr)
        {
            totalCapacity = totalCapacity + deliveryPtr->getCapacity();
        }
    }
    return totalCapacity;
}

void Bikes:: print( ostream &out ) const
{
    cout << "Printing bike info..." << endl << endl;
    cout << "in Bikes::print function." << endl << endl;
    
    unsigned numBikes = 0;
    
    for( unsigned long i = 0; i < bikes.size(); i++ )
    {
        numBikes++;
        
        //polymorphic print function for the various bike objects
        bikes.at(i)->print(out);
        out << endl;
    }
    cout << "Total number of bikes: " << numBikes << endl;
}

void Bikes:: read( string filename ) throw ( logic_error, invalid_argument )
{
    ifstream inputFile;
    inputFile.open(filename.c_str());
    
    if(!inputFile)
    {
        string errorMsg = "The file " + filename + " failed to open.";
        throw logic_error(errorMsg);
    }
    else
    {
        cout << "Reading file..." << endl;
        cout << "Inside Bikes::read method..." << endl;

        Bike* bikePtr = NULL;

        // loop through all records of the input stream
        // as long as the stream is in a working state, 
        // use BikeFactory to create the next Bike pointer
        
        while( inputFile )
        {
            cout << "inputFile in working state in Bikes::read." << endl;
            bikePtr = BikeFactory::make(inputFile);
            //cout << "Control return for make." << endl;
            if(bikePtr)
            {
                cout << "bikePtr is valid in Bikes::read" << endl << endl;
                bikes.push_back(bikePtr);
            }
        } // END while loop to read data file
        
        inputFile.close();
    }
    cout << "End of read function." << endl;
}

unsigned Bikes:: size() const
{
    unsigned size = bikes.size();
    return size;
}