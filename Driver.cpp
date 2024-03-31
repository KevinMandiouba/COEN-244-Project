#include <iostream>
#include "TAs.h"
using namespace std;

int main()
{

    cout << "*********************************" << endl;
    cout << "\tFiltering the TAs" << endl;
    cout << "*********************************" << endl;

    TAs TAs;

    TAs.copyInfo(); //Reads TAs.txt and copies the data from the text file into a vector of TA objects

    TAs.modifyInfo(); //Removes any lines with invalid TAs from TAs.txt using the vector of TAs

    TAs.getInfo(); //Displays the new content of the text file using the vector of TAs before TAs.txt is modified


    cout << "\n*********************************" << endl;
    cout << "   TA record management system" << endl;
    cout << "*********************************" << endl;

    int menu_option;

    cout << "1. Add new TAs\n";
    cout << "2. Sort TAs\n";
    cout << "3. Quit\n";
    
    while (true) {

        try {
            cout << "\n*********************************" << endl;
            cout << "Please pick a menu option: ";
            cin >> menu_option;

            //Exemption Handling for the menu options

            if (cin.fail()) {

                cin.clear();

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                throw invalid_argument("Invalid input! Please enter an integer");
            }
            else if (menu_option != 1 && menu_option != 2 && menu_option != 3) {

                throw invalid_argument("Invalid input! Please enter an integer between 1 and 3");
            }

            //Actions performed after the exceptions have been handled 

            switch (menu_option) {

            case 1: //Prompts the user for the information representing one or many TA

                TAs.addNewTAs(); 

                TAs.modifyInfo(); 

                TAs.getInfo();

                cout << "\nNew TAs added successfully!\n";

                break;

            case 2: //Prompts the user to select from a list to order by, and then choose to order in ascending or descending order

                TAs.sortTAS();

                TAs.modifyInfo();

                TAs.getInfo();

                break;

            case 3: //Lets the user exit the program

                cout << "\nThis program ends now\n";
                return false;
            }
        }
        catch (const invalid_argument& int_exception) {

            cout << "Error: " << int_exception.what() << endl;

        }
    }

    return 0;
}