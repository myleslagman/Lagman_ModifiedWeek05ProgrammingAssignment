// Lagman_ModifiedWeek05ProgrammingAssignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Johnny Utah owns a surf shop on the beach called “Point Break Surf Shop”. Johnny sells surfboards in 3 three sizes: 
//small (2 meters), medium (3 meters), and large (4 meters). The cost of one small surfboard is $175.00, one medium is $190.00, and one large is $200.00.  
//Write a program that will make the surf shop operational. 

// Modified to add size XXXS for squirrel surfing

#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

//Constants
const double XXXSSurfboardPrice = 92.00; //Added extra small surfboard for squirrel surfing
const double SmallSurfboardPrice = 175.00;
const double MediumSurfboardPrice = 190.00;
const double LargeSurfboardPrice = 200.00;

// Declaring function prototypes
void ShowUsage();
void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalXXXS);
void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXS);
void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXS);

// Main function
int main()
{
    char userSelect, size;
    int quantity;

    int totalQuantitySmall, totalQuantityMedium, totalQuantityLarge, totalQuantityXXXS;
    totalQuantitySmall = 0;
    totalQuantityMedium = 0;
    totalQuantityLarge = 0;
    totalQuantityXXXS = 0;

    //Opening Banner 
    cout << setw(60) << setfill('*') << '*' << endl;
    cout << right << setw(5) << setfill('*') << '*' << " Welcome to my Johnny Utah's PointBreak Surf Shop " << right << setw(5) << setfill('*') << '*' << endl;
    cout << setw(60) << setfill('*') << '*' << endl;
    cout << endl;
    cout << endl;

    //Calling out the Show Usage function
    ShowUsage();
    cout << endl;

    //Getting user selection
    cout << "\nPlease enter selection: ";
    cin >> userSelect;

    //As long as user input is != 'q' or 'Q', proceed to the code below
    //Branching if statements to determine which code (containing a function) to execute
    while (tolower(userSelect) != 'q')
    {
        if (tolower(userSelect) == 's')
        {
            ShowUsage();
        }
        else if (tolower(userSelect) == 'p')
        {
            MakePurchase(totalQuantitySmall, totalQuantityMedium, totalQuantityLarge, totalQuantityXXXS);
            cout << endl;
        }
        else if (tolower(userSelect) == 'c')
        {
            //If the quantity of all three surfboards is 0, remind user that no purchases were made yet.
            if (totalQuantitySmall == 0 && totalQuantityMedium == 0 && totalQuantityLarge == 0 && totalQuantityXXXS == 0)
            {
                cout << "No purchase made yet." << endl;
            }
            else
            {
                DisplayPurchase(totalQuantitySmall, totalQuantityMedium, totalQuantityLarge, totalQuantityXXXS);

            }

        }
        else if (tolower(userSelect) == 't')
        {
            //If the quantity of all three surfboards is 0, remind user that no purchases were made yet.
            if (totalQuantitySmall == 0 && totalQuantityMedium == 0 && totalQuantityLarge == 0 && totalQuantityXXXS == 0)
            {
                cout << "No purchase made yet." << endl;
            }
            else
            {
                DisplayTotal(totalQuantitySmall, totalQuantityMedium, totalQuantityLarge, totalQuantityXXXS);
            }

        }
        else
        {
            cout << "Invalid choice!" << endl;
        }

        cout << "\nPlease enter selection: ";
        cin >> userSelect;
    }

    cout << "Thank you" << endl;
}

// Defining the functions 
void ShowUsage() //a function to show the user how to use the program.
{
    //Display the menu
    cout << "To show program usage 'S'" << endl;
    cout << "To purchase a surfboard press 'P'" << endl;
    cout << "To display current purchase press 'C'" << endl;
    cout << "To display total amount due press 'T'" << endl;
    cout << "To quit the program press 'Q'" << endl;
}

void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalXXXS) //a function to sell surfboards.
{
    //Declaring + Initializing variables needed
    int quantity = 0;
    char size = '\0';
    string sizexxxs = " ";

    //Ask the user their preferred quantity and size
    cout << "Please enter the quantity and type ";
    cout << "(X=extrasmall(size XXXS), S=small, M=medium, L=large) of ";
    cout << "surfboard you would like to purchase:";
    cin >> quantity >> size;

    //If the purchased surfboard's size is small, add its quantity to iTotalSmall.
    if (tolower(size) == 's')
    {
        iTotalSmall = iTotalSmall + quantity;
    }

    //If the purchased surfboard's size is medium, add its quantity to iTotalMedium.
    else if (tolower(size) == 'm')
    {
        iTotalMedium = iTotalMedium + quantity;
    }

    //If the purchased surfboard's size is large, add its quantity to iTotalLarge.
    else if (tolower(size) == 'l')
    {
        iTotalLarge = iTotalLarge + quantity;
    }

    //If the purchased surfboard's size is extra small, add its quantity to iTotalLarge.
    else if (tolower(size) == 'x')
    {
        iTotalXXXS = iTotalXXXS + quantity;
    }

}

void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXS) //function to show the number of surfboards of each size sold.
{
    //If the total quantity of small surfboards is more than 0, then display its quantity.
    if (iTotalSmall > 0)
    {
        cout << "The total number of small surfboards is " << iTotalSmall;
        cout << endl;
    }

    //If the total quantity of medium surfboards is more than 0, then display its quantity.
    if (iTotalMedium > 0)
    {
        cout << "The total number of medium surfboards is " << iTotalMedium;
        cout << endl;
    }

    //If the total quantity of large surfboards is more than 0, then display its quantity.
    if (iTotalLarge > 0)
    {
        cout << "The total number of large surfboards is " << iTotalLarge;
        cout << endl;
    }

    //If the total quantity of XXXS surfboards is more than 0, then display its quantity.
    if (iTotalXXXS > 0)
    {
        cout << "The total number of XXXS surfboards is " << iTotalXXXS;
        cout << endl;
    }
}

void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXS) //a function to show the total amount of money made.
{
    double surfboardAmountSmall, surfboardAmountMedium, surfboardAmountLarge, surfboardAmountXXXS, totalAmtDue;
    surfboardAmountSmall = surfboardAmountMedium = surfboardAmountLarge = surfboardAmountXXXS = totalAmtDue = 0;

    //Set the precision for the double values to two decimal places.

    cout << fixed << setprecision(2);

    //If the total quantity of small surfboards is more than 0, then display its quantity and total.

    if (iTotalSmall > 0)
    {
        //Calculate the total of the small surfboards by multiplying its total quantity with its price value.
        surfboardAmountSmall = iTotalSmall * SmallSurfboardPrice;
        cout << "The total number of small surfboards is " << iTotalSmall;
        cout << " at a total of $";
        cout << surfboardAmountSmall << endl;

        //Add the total of small surfboards to the total amount.
        totalAmtDue = totalAmtDue + surfboardAmountSmall;

    }

    //If the total quantity of medium surfboards is more than 0, then display its quantity and total.
    if (iTotalMedium > 0)
    {
        //Calculate the total of the medium surfboards
        //by multiplying its total quantity with
        //its unit price value.
        surfboardAmountMedium = iTotalMedium * MediumSurfboardPrice;
        cout << "The total number of medium surfboards is " << iTotalMedium;
        cout << " at a total of $";
        cout << surfboardAmountMedium << endl;

        //Add the total of medium surfboards to the total amount.

        totalAmtDue = totalAmtDue + surfboardAmountMedium;
    }


    //If the total quantity of large surfboards is more than 0, then display its quantity and total.
    if (iTotalLarge > 0)
    {
        //Calculate the total of the large surfboards by multiplying its total quantity with its price value.
        surfboardAmountLarge = iTotalLarge * LargeSurfboardPrice;
        cout << "The total number of large surfboards is " << iTotalLarge;
        cout << " at a total of $";
        cout << surfboardAmountLarge << endl;

        //Add the total of large surfboards to the total amount.
        totalAmtDue = totalAmtDue + surfboardAmountLarge;
    }

    if (iTotalXXXS > 0)
    {
        //Calculate the total of the XXXS surfboards by multiplying its total quantity with its price value.
        surfboardAmountXXXS = iTotalXXXS * XXXSSurfboardPrice;
        cout << "The total number of xxxs surfboards is " << iTotalXXXS;
        cout << " at a total of $";
        cout << surfboardAmountXXXS << endl;

        //Add the total of large surfboards to the total amount.
        totalAmtDue = totalAmtDue + surfboardAmountXXXS;
    }

    //Display the total amount due.
    cout << "Amount due: $" << totalAmtDue << endl;

}
