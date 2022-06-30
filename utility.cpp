/**
 * utility.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Divyanga Bajoria
 * bajoriad
 *
 * EECS 183: Project 3
 * Winter 2021
 *
 * Descrption: Wrote the program for the helper fucntions used in encrypting
 * or decrypting messages according to the different cipher types.
 */

#include "utility.h"
#include <iostream>


/*returns a string with all its alphabetical characters converted to the
  uppercase*/
string toUpperCase(string original)
{
    int str_length = int(original.size());
    for (int i = 0; i < str_length; i++)
    {
        if ((original.at(i) >= 'A' && original.at(i) <= 'Z') || (original.at(i)
             >= 'a' && original.at(i) <= 'z'))
        {
            if (original.at(i) >= 'a' && original.at(i) <= 'z')
            {
                original.at(i) = original.at(i) - ' ';
            }
        }
    }
    return original;
}


//removes all the non-alphabetical characters from a string 
string removeNonAlphas(string original)
{
    int str_length = int(original.size());
    string alpha_string = "";
    for (int i = 0; i < str_length; i++)
    {
        if ((original.at(i) >= 'A' && original.at(i) <= 'Z') || (original.at(i)
             >= 'a'&& original.at(i) <= 'z'))
        {
            alpha_string = alpha_string + original.at(i);
        }
    }
    return alpha_string;
}


//removes any duplicate characters in the string
string removeDuplicate(string original)
{
    string copy_original = original;
    int str_length = int(copy_original.size());
    string not_duplicate = "";
    not_duplicate = copy_original.at(0);
    for (int i = 1 ; i < str_length; i++)
    {
        //replaces a recurring character with zero in the string
        for (int j = 0; j < i; j++)
        {
            if (copy_original.at(i) == copy_original.at(j))
            {
                copy_original.at(i) = 0;
            }
        }
       //prints a new string leaving out the zero or recurring characters
        if (copy_original.at(i) != 0)
        {
        not_duplicate = not_duplicate + copy_original.at(i);
        }
    }
    return not_duplicate;
}


// converts a character into its integer representation
int charToInt(char original)
{
    int integer_form = 0;
    integer_form = static_cast<int>(original) - '0';
    return integer_form;
}

////////////////////////////////////////////////////////////////////////////////
// Do not touch code below. ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void printGrid(const char grid[SIZE][SIZE])
{
    for (int col = 0; col < SIZE; col++) {
        cout << " ---";
    }
    cout << endl;
    for (int row = 0; row < SIZE; row++) {
        cout << "| ";
        for (int col = 0; col < SIZE; col++) {
            cout << string(1, grid[row][col]) + " | ";
        }
        cout << endl;
        for (int col = 0; col < SIZE; col++) {
            cout << " ---";
        }
        cout << endl;
    }
}
