/**
 * caesar.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Divyanga Bajoria
 * bajoriad
 *
 * EECS 183: Project 3
 * Winter 2021
 *
 * Description: Wrote the program to encrypt or decrypt a message
 * according to the ceasar cipher.
 */

#include "caesar.h"
#include <iostream>

/* Requires: a is an uppercase or lowercase alphabetical character
   Modifies: Nothing
   Effect: returns a shifted by n characters
           If a is uppercase, it will remain in uppercase
           If a is lowercase, it will remain in lowercase
*/
char shift(char a, int n);


//shifts the character c by n characters
char shiftAlphaCharacter(char c, int n)
{
    char shift_charac = ' ';
    //shifts the character c by n characters when n is positive or equal to zero
    if (n >= 0)
    {
        //shifts the character c by n characters when c is an uppercase alphabet
        if (c >= 'A' && c <= 'Z')
        {
            int ascii_c = static_cast<int>(c);
            /*shifts the character c by n characters when the sum of the ascii
             value of character c and the key is less than or equal to the
             ascii value of 'Z'*/
            if ((c + n) <= 'Z')
            {
                shift_charac = shift(c, n);
            }
            /*shifts the character c by n characters when the sum of the ascii
             value of character c and the key is greater than the ascii value
             of 'Z'*/
            else if ((c + n) > 'Z')
            {
                int ascii_diff = 'Z' - '@';
                int diff_zascii = 'Z' - ascii_c;
                /*finding how many times does the character completely shift
                  from A to Z*/
                int shift_num = (n - diff_zascii) % (ascii_diff);
                if (shift_num == 0)
                {
                    shift_num = shift_num + ascii_diff;
                }
                //computing the ascii value of the character after shifting it
                int ascii_c_shift = ascii_c + diff_zascii - ascii_diff +
                                    shift_num;
                /*converting the ascii value of the shifted character to its
                  char representation*/
                shift_charac = static_cast<char>(ascii_c_shift);
            }
        }
        //shifts the character c by n characters when c is a lowercase alphabet
        else if (c >= 'a' && c <= 'z')
        {
            int ascii_c = static_cast<int>(c);
            /*shifts the character c by n characters when the sum of the ascii
             value of character c and the key is less than or equal to the
             ascii value of 'z'*/
            if ((c + n) <= 'z')
            {
                shift_charac = shift(c, n);
            }
            /*shifts the character c by n characters when the sum of the ascii
             value of character c and the key is greater than the ascii value
             of 'z'*/
            else if ((c + n) > 'z')
            {
                int ascii_diff = 'z' - '`';
                int diff_zascii = 'z' - ascii_c;
                /*finding how many times does the character completely shift
                  from a to z*/
                int shift_num = (n - diff_zascii) % (ascii_diff);
                if (shift_num == 0)
                {
                    shift_num = shift_num + ascii_diff;
                }
                int ascii_c_shift = ascii_c + diff_zascii - ascii_diff +
                                    shift_num;
                shift_charac = static_cast<char>(ascii_c_shift);
            }
        }
    }
    //shifts the character c by n characters when n is negative
    else if (n < 0)
    {
        //shifts the character c by n characters when c is an uppercase alphabet
        if (c >= 'A' && c <= 'Z')
        {
            int ascii_c = static_cast<int>(c);
            /*shifts the character c by n characters when the sum of the ascii
             value of character c and the key is greater than or equal to the
             ascii value of 'A'*/
            if ((c + n) >= 'A')
            {
                shift_charac = shift(c, n);
            }
            /*shifts the character c by n characters when the sum of the ascii
             value of character c and the key is less than the ascii value of
             'A'*/
            else if ((c + n) < 'A')
            {
                int ascii_diff = 'Z' - '@';
                int diff_asciia = ascii_c - 'A';
                /*finding how many times does the character completely shift
                  from Z to A, negative sign used to make the key positive*/
                int shift_num = (- n - diff_asciia) % (ascii_diff);
                if (shift_num == 0)
                {
                    shift_num = shift_num + ascii_diff;
                }
                //finding the ascii value of the character after shifitng it
                int ascii_c_shift = ascii_c - diff_asciia + ascii_diff -
                                    shift_num;
                /*converting the ascii value of the shifted character to its
                  char representation*/
                shift_charac = static_cast<char>(ascii_c_shift);
            }
        }
        //shifts the character c by n characters when c is a lowercase alphabet
        else if (c >= 'a' && c <= 'z')
        {
            int ascii_c = static_cast<int>(c);
            /*shifts the character c by n characters when the sum of the ascii
             value of character c and the key is greater than or equal to the
             ascii value of 'a'*/
            if ((c + n) >= 'a')
            {
                shift_charac = shift(c, n);
            }
            /*shifts the character c by n characters when the sum of the ascii
             value of character c and the key is less than the ascii value of
             'a'*/
            else if ((c + n) < 'a')
            {
                int ascii_diff = 'z' - '`';
                int diff_asciia = ascii_c - 'a';
                /*finding how many times does the character completely shift
                  from z to a, negative sign used to make the key positve*/
                int shift_num = (- n - diff_asciia) % (ascii_diff);
                if (shift_num == 0)
                {
                    shift_num = shift_num + ascii_diff;
                }
                int ascii_c_shift = ascii_c - diff_asciia + ascii_diff -
                                    shift_num;
                shift_charac = static_cast<char>(ascii_c_shift);
            }
        }
    }
    return shift_charac;
}


/*encrypting or decrypting a message using a key in accordance with the ceaser
  cipher*/
string caesarCipher(string original, int key, bool encrypt)
{
    int key_copy = 0;
    int str_length = int(original.size());
    if (encrypt == true)
    {
        key_copy = key;
    }
    else if (encrypt == false)
    {
        key_copy = - key;
    }
    /*shifting the alphabetical characters of the string by the number of
      characters mentioned in the key by calling the shiftAlphacharacter
      function*/
    for (int i = 0; i < str_length; i++)
    {
        if ((original.at(i) >= 'A' && original.at(i) <= 'Z') || (original.at(i)
             >= 'a' && original.at(i) <= 'z'))
           {
               original.at(i) = shiftAlphaCharacter(original.at(i), key_copy);
           }
    }
    return original;
}


//shifts the character a by n characters
char shift(char a, int n)
{
    int ascii_c = static_cast<int>(a);
    int ascii_c_shift = ascii_c + n;
    char shift_cha = static_cast<char>(ascii_c_shift);
    return shift_cha;
}
