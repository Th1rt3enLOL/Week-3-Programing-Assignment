#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

//declare constants
double freeShip = 0, fragShip = 2,
usa50 = 6, usa100 = 9, usa150 = 12,
can50 = 8, can100 = 12, can150 = 15,
aus50 = 10, aus100 = 14, aus150 = 17,
mars = 17427;

int main()
{
    //declare variables
    string item, fragile, destination;
    double price, shipping;

    //header
    cout << setw(49) << setfill('.') << left << "" << endl
        << "ITCS 2530 - Programing Assignment for week #3\n"
        << setw(49) << "" << endl
        << endl
        << endl;

    //prompt input and transform item name
    cout << setw(48) << "Please enter the item name (no spaces)" << ":";
    cin >> item;
    transform(item.begin(), item.end(), item.begin(), toupper);

    //prompt input transform and validate fragile
    cout << setw(48) << "Is the item fragile? (y=yes/n=no)" << ":";
    cin >> fragile;
    transform(fragile.begin(), fragile.end(), fragile.begin(), toupper);
    if (fragile != "Y" && fragile != "N")
    {
        cout << "\nInvalid entry, exiting\n";
        return 0;
    }

    //prompt and input price
    cout << setw(48) << "Please enter your order total" << ":";
    cin >> price;

    //prompt input transform and validate destination
    cout << setw(48) << "Please enter destination. (usa/can/aus/mars)" << ":";
    cin >> destination;
    transform(destination.begin(), destination.end(), destination.begin(), toupper);
    if (destination != "USA" && destination != "CAN" && destination != "AUS" && destination != "MARS")
    {
        cout << "\nInvalid entry, exiting\n";
        return 0;
    }

    //determine shipping cost
    if (destination == "MARS")
    {
        shipping = mars;
    }
    else if (price <= 50)
    {
        if (destination == "USA")
        {
            shipping = usa50;
        }
        else if (destination == "CAN")
        {
            shipping = can50;
        }
        else if (destination == "AUS")
        {
            shipping = aus50;
        }
    }
    else if (price <= 100)
    {
        if (destination == "USA")
        {
            shipping = usa100;
        }
        else if (destination == "CAN")
        {
            shipping = can100;
        }
        else if (destination == "AUS")
        {
            shipping = aus100;
        }
    }
    else if (price <= 150)
    {
        if (destination == "USA")
        {
            shipping = usa150;
        }
        else if (destination == "CAN")
        {
            shipping = can150;
        }
        else if (destination == "AUS")
        {
            shipping = aus150;
        }
    }
    else
    {
        shipping = freeShip;
    }

    if (fragile == "Y")
    {
        shipping += fragShip;
    }

    //add shipping to total price
    price += shipping;

    //output
    cout << endl << fixed << setprecision(2) << setw(40) << "Your item is" << item << endl
        << setw(40) << "Your shipping cost is" << "$" << shipping << endl
        << setw(40) << "You are shipping to" << destination << endl
        << setw(40) << "Your total shipping costs are" << "$" << price << endl
        << endl
        << setw(40) << setfill('-') << "" << "Thank You!\n\n";
}