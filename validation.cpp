/*****************************************************************************
 * Function name: validation
 * Author:        Chi Hin Ng
 * Date:          31/10/2019
 * Description:   This file contain a function that validate the input as
 *                integers.
*****************************************************************************/
#include "validation.hpp"

using std::string;
using std::cin;
using std::cout;
using std::endl;

/*****************************************************************************
 * Description:   The valdation function is designed to make sure any input
 *                from the user is an integer. It will save the input as a
 *                string and check all the characters in the string to see if
 *                there are any non-integer characters (i.e. not 0-9). If
 *                there are any non-integer characters, ask the user to input
 *                a new string again. If only integers are found, convert the
 *                integer characters to an int variable and return it.
 * Arguments:     None
 * Returns:       the reply of the user as an int variable
*****************************************************************************/
int validation()
{
    bool valid = false; //to check if the whole line of the input is int
    bool check = true; //to check if the current input is a valid one
    string input; //for saving the input from user
    int output = 0; //for storing the numbers from the input as an int

    do {
        std::getline(cin, input); //save the input from user

        for (unsigned int i = 0; i < input.size(); i++)
        {
            if (input[i] == '0' || input[i] == '1' || input[i] == '2' ||
                input[i] == '3' || input[i] == '4' || input[i] == '5' ||
                input[i] == '6' || input[i] == '7' || input[i] == '8' ||
                input[i] == '9')
            {
                valid = true;
                check = false;
            }
            else
            {
                valid = false;
                check = true;
                cout << "Error! Please enter an integer only." << endl;
                cout << "Int: ";
                break; //break the loop if any characters is not an int
            }
        }

        if (valid == true)
        {
            output = std::stoi(input); // convert the string to int
        }
    } while (check == true);

    return output;
}
