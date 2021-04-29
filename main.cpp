#include "main.h"
#include <sstream>
using namespace std;


int main(int argc, char* argv[]) 
{
    try
    {
        if ( argc < 2 )
        {
            cout << "Not enough command line arguments, please pass the complete path and name";
            cout << endl;
            cout << "of one of the \"All\" input data files as a command line argument.\n";
            cout << "Test cannot continue... Goodbye\n";
            cout << endl;
            throw invalid_argument ("missing command line argument for file name");
            cout << endl;
        }
        else 
        {
            //This will print the first argument passed to your program
            cout << "First argument: " << argv[1] << endl << endl;
            string filename = argv[1];
            
            string inputData = "";

            //inputData += "U01 \"Trek Soho Deluxe\" 8";
            //inputData += "AAA \"Trek Transport+\" 5 80";
            //inputData += "D02 \"Johnny Loco Cargo Cruiser\" 8 75";
            //inputData += "U02 \"Johnny Loco Urban Londoner\" 3";
            //inputData += "U03 \"Johnny Loco Urban Moscow\" 1";
            //inputData += "U04 \"Kona Dew DL\" 4";
            //inputData += "D03 \"Kona Minute\" 8 70";
            //inputData += "D04 \"Kona Ute\" 8 100";
            
            //istringstream inFile( inputData );
            //string id = "D01";
            //string name = "Trek Soho Deluxe";
            //int gears = 5;
            
            //test Bike default constructor
            //Bike bike1;
            //bike1.print();
            //Bike bike(id, name, gears);
            
            /*cout << "ID: " << bike.getID() << endl;
            cout << "Name: " << bike.getName() << endl;
            cout << "Gears: " << bike.getGears() << endl;*/
            
            //Bike print function
            //bike.print();
            
            //Bike b;
            //b.read(inFile);
            //b.print();
            
            //Bike bike;
            //bike.setID(id);
            //bike.setName(name);
            //bike.setGears(gears);
            //bike.print();
            
            //string id = "D01";
            //string name = "Trek Soho Deluxe";
            //int gears = 5;
            //int capacity = 1;
            //Delivery d(id, name, gears, capacity);
            //d.print();
            //cout << "Capacity: " << d.getCapacity();
            
            //Delivery d;
            //d.read(inFile);
            //d.print();
            /*
            Delivery d;
            d.setID(id);
            d.setName(name);
            d.setGears(gears);
            d.setCapacity(capacity);
            d.print();
            cout << endl;
            cout << "Capacity: " << d.getCapacity() << endl;
            */
            
            //string id = "AAA";
            //string name = "Trek Soho Deluxe";
            //int gears = 24;
            //Urban u;
            //u.print();
            
            //Urban u(id, name, gears);
            //u.print();
            
            //Urban u;
            //u.read(inFile);
            //u.print();
            /*
            Urban u;
            u.setID(id);
            u.setName(name);
            u.setGears(gears);
            u.print();
            cout << endl;
            cout << "ID: " << u.getID() << endl;
            cout << "Name: " << u.getName() << endl;
            cout << "Gears: " << u.getGears() << endl;
            */
            
            //BikeFactory b;

            //Bike* bPtr = NULL;
            //bPtr = b.make(inFile);
            //bPtr->print();
            
            //Bikes bikes;
            //bikes.print();
            
            Bikes bikes;
            
            //read from input file
            bikes.read(filename);
            
            //print bike info
            bikes.print();
            
            //cout << "Total carrying capacity of delivery bikes: ";
            cout << bikes.getTotalCapacity();
            cout << endl; 
            
            
            //cout << "Total gears: ";
            cout << bikes.getTotalGears() << endl;
            cout << endl;
            
        }
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << endl;
    }
    catch (logic_error &e)
    {
        cout << e.what() << endl;
    }
    catch (...)
    {
        cout << "Caught unknown exception in function main." << endl;
    }
    return 0;
}

