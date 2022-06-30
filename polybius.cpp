/**
 * polybius.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Divyanga Bajoria
 * bajoriad
 *
 * EECS 183: Project 3
 * Winter 2021
 *
 * Description: Wrote the program to encrypt or decrypt a message
 * according to the polybius cipher.
 */


#include "polybius.h"
#include <string>
using namespace std;


/*returns a string with the key at the beginning followed by all the remaining
  characters in the string ALNUM*/
string mixKey(string key)
{
    string key_modified = "";
    key_modified = key + ALNUM;
    key_modified = removeDuplicate(key_modified);
    return key_modified;
}


//fills the 6 by 6 grid with the provided string
void fillGrid(char grid[SIZE][SIZE], string content)
{
    int a = 0;
    int index_string = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j= a; j < SIZE; j++)
        {
            grid[i][j] = content.at(index_string);
            index_string++;
        }
    }
}


/*finds the coordinates of a character in the grid and returns it in the form
  of a string representation*/
string findInGrid(char c, char grid[SIZE][SIZE])
{
    string row_pos = "";
    string col_pos = "";
    string char_positon = "";
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if ((grid[i][j]) == c)
            {
                //finding the row position of the character
                row_pos = static_cast<char>(i + '0');
                //finding the column position of the character
                col_pos = static_cast<char>(j + '0');
                char_positon = row_pos + col_pos;
            }
         }
    }
    return char_positon;
}


/*encrypting or decrypting a message using a key in accordance with the polybius
  cipher*/
string polybiusSquare(char grid[SIZE][SIZE], string key, string original,
                      bool encrypt)
{
    string modified_poly = "";
    int str_length = int(original.size());
    string modified_alnum = mixKey(key);
    fillGrid(grid, modified_alnum);
    //encrypting the message using the polybius cipher
    if (encrypt == true)
    {
        for (int i = 0; i < str_length; i++)
        {
            //spaces in the string original remain as spaces
            if ((original.at(i)) == ' ')
            {
                modified_poly = modified_poly + original.at(i);
            }
            else
            {
               modified_poly = modified_poly + findInGrid(original.at(i),grid);
            }
        }
    }
    //decrypting the message using the polybius cipher
    else if (encrypt == false)
    {
        for (int i = 0; i < str_length; i = i + 2)
        {
            //spaces in the string original remain as spaces
            if (original.at(i) == ' ')
            {
                modified_poly = modified_poly + original.at(i);
                i--;
            }
            else
            {
                int row_pos = charToInt(original.at(i));
                int col_pos = charToInt(original.at(i + 1));
                char alpha_pos = grid[row_pos][col_pos];
                modified_poly = modified_poly + alpha_pos;
            }
        }
    }
    return modified_poly;
}
