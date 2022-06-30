/**
 * vigenere.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Divyanga Bajoria
 * bajoriad
 *
 * EECS 183: Project 3
 * Winter 2021
 *
 * Description: Wrote the program to encrypt or decrypt a message
 * according to the vigenere cipher.
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include <iostream>


/*encrypting or decrypting a message using a key in accordance with the vigenere
  cipher*/
string vigenereCipher(string original, string keyword, bool encrypt)
{
    keyword = removeNonAlphas(keyword);
    keyword = toUpperCase(keyword);
    int str_length = int(original.size());
    int keyword_length = int(keyword.size());
    int index_key = 0;
    char key_charac = ' ';
    for (int i = 0; i < str_length; i++)
    {
        if ((original.at(i) >= 'A' && original.at(i) <= 'Z') || (original.at(i)
             >= 'a' && original.at(i) <= 'z' ))
        {
            key_charac = keyword.at(index_key);
            /*finding the number of characters by which the ith alphabetical
              character of the string original should be shifted*/
            int cipher_key = (static_cast<int>(key_charac)) - 'A';
            if (encrypt == false)
            {
                cipher_key = - cipher_key;
            }
            original.at(i) = shiftAlphaCharacter(original.at(i), cipher_key);
            index_key++;
            /*ensures the keyword continues to be used until string original is
              fully encrypted or decrypted*/
            if (index_key == keyword_length)
            {
                index_key = 0;
            }
        }
    }
    return original;
}
