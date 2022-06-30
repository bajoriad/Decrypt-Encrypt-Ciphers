/**
 * ciphers.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Divyanga Bajoria
 * bajoriad
 *
 * EECS 183: Project 3
 * Winter 2021
 *
 * Description: Wrote the program to encrypt or decrypt the user
 * entered message in accordance with the cipher type entered by the user.
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;

void ciphers()
{
    string cipher_type = "";
    cout << "Choose a cipher (Caesar, Vigenere, or Polybius): ";
    cin >> cipher_type;
    cipher_type = toUpperCase(cipher_type);
    
    //checking if the user entered cipher type is valid or not
    if (cipher_type == "C" || cipher_type == "V" || cipher_type == "P" ||
        ((cipher_type.at(0) == 'C') && (cipher_type.at(1) == 'A') &&
        (cipher_type.at(2) == 'E') && (cipher_type.at(3) == 'S') &&
        (cipher_type.at(4) == 'A') && (cipher_type.at(5) == 'R')) ||
        ((cipher_type.at(0) == 'V') && (cipher_type.at(1) == 'I') &&
        (cipher_type.at(2) == 'G') && (cipher_type.at(3) == 'E') &&
        (cipher_type.at(4) == 'N') && (cipher_type.at(5) == 'E') &&
        (cipher_type.at(6) == 'R') && (cipher_type.at(7) == 'E')) ||
        ((cipher_type.at(0) == 'P') && (cipher_type.at(1) == 'O') &&
        (cipher_type.at(2) == 'L') && (cipher_type.at(3) == 'Y') &&
        (cipher_type.at(4) == 'B') && (cipher_type.at(5) == 'I') &&
        (cipher_type.at(6) == 'U') && (cipher_type.at(7) == 'S')))
    {
        cipher_type = cipher_type;
    }
    else
    {
        cout << "Invalid cipher!";
        return;
    }
    
    string mode_type = "";
    bool mode_ed;
    cout << "Encrypt or decrypt: ";
    cin >> mode_type;
    mode_type = toUpperCase(mode_type);
    
    //checking if the user entered mode is valid or not
    if (mode_type == "D" || mode_type == "E" || ((mode_type.at(0) == 'E') &&
        (mode_type.at(1) == 'N') && (mode_type.at(2) == 'C') &&
        (mode_type.at(3) == 'R') && (mode_type.at(4) == 'Y') &&
        (mode_type.at(5) == 'P') && (mode_type.at(6) == 'T')) ||
        ((mode_type.at(0) == 'D') && (mode_type.at(1) == 'E') &&
        (mode_type.at(2) == 'C') && (mode_type.at(3) == 'R') &&
        (mode_type.at(4) == 'Y') && (mode_type.at(5) == 'P') &&
        (mode_type.at(6) == 'T')))
    {
        mode_type = mode_type;
    }
    else
    {
        cout << "Invalid mode!";
        return;
    }
   
    /*assigning a boolean variable to be true when the message is encrypted and
      false when the message is decrypted*/
    if (mode_type == "E" || ((mode_type.at(0) == 'E') &&
        (mode_type.at(1) == 'N') && (mode_type.at(2) == 'C') &&
        (mode_type.at(3) == 'R') && (mode_type.at(4) == 'Y') &&
        (mode_type.at(5) == 'P') && (mode_type.at(6) == 'T')))
    {
        mode_ed = true;
    }
    else
    {
        mode_ed = false;
    }
    
    string user_message = "";
    string key_poly_vig = "";
    int key_caesar = 0;
    string enc_decr_message = "";
    
    cout << "Enter a message: ";
    getline(cin, user_message);
    getline(cin,user_message);
    
    //checking if the user entered message is valid or not for polybius cipher
    if (cipher_type == "P" || ((cipher_type.at(0) == 'P') &&
        (cipher_type.at(1) == 'O') && (cipher_type.at(2) == 'L') &&
        (cipher_type.at(3) == 'Y') && (cipher_type.at(4) == 'B') &&
        (cipher_type.at(5) == 'I') && (cipher_type.at(6) == 'U') &&
        (cipher_type.at(7) == 'S')))
    {
        int message_length = int(user_message.size());
        for (int i = 0; i < message_length; i++)
        {
            if ((user_message.at(i) >= 'A' && user_message.at(i) <= 'Z') ||
                (user_message.at(i) >= 'a' && user_message.at(i) <= 'z') ||
                (user_message.at(i) >= '0' && user_message.at(i) <= '9') ||
                (user_message.at(i) == ' '))
            {
                user_message = user_message;
            }
            else
            {
                cout << "Invalid message!";
                return;
            }
        }
    }
    
    //encrypting or decrypting the user entered message using a caesar cipher
    if (cipher_type == "C" || ((cipher_type.at(0) == 'C') &&
        (cipher_type.at(1) == 'A') && (cipher_type.at(2) == 'E') &&
        (cipher_type.at(3) == 'S') && (cipher_type.at(4) == 'A') &&
        (cipher_type.at(5) == 'R')))
    {
        cout << "What is your key: ";
        cin >> key_caesar;
        enc_decr_message = caesarCipher(user_message, key_caesar, mode_ed);
    }
    
    //encrypting or decrypting the user entered message using a vigenere cipher
    if (cipher_type == "V" || ((cipher_type.at(0) == 'V') &&
        (cipher_type.at(1) == 'I') && (cipher_type.at(2) == 'G') &&
        (cipher_type.at(3) == 'E') && (cipher_type.at(4) == 'N') &&
        (cipher_type.at(5) == 'E') && (cipher_type.at(6) == 'R') &&
        (cipher_type.at(7) == 'E')))
    {
        cout << "What is your key: ";
        getline(cin, key_poly_vig);
        int key_length = int(key_poly_vig.size());
        int count_alpha = 0;
        //counting the number of alphabetical characters in the key
        for (int i = 0; i < key_length; i++)
        {
            if ((key_poly_vig.at(i) >= 'A' && key_poly_vig.at(i) <= 'Z') ||
                (key_poly_vig.at(i) >= 'a' && key_poly_vig.at(i) <= 'z'))
            {
                count_alpha++;
            }
        }
        //checking if the key for vigenere cipher is valid or not
        if (count_alpha == 0)
        {
            cout << "Invalid key!";
            return;
        }
        enc_decr_message = vigenereCipher(user_message, key_poly_vig, mode_ed);
    }
    
    //encrypting or decrypting the user entered message using a polybius cipher
    if (cipher_type == "P" || ((cipher_type.at(0) == 'P') &&
        (cipher_type.at(1) == 'O') && (cipher_type.at(2) == 'L') &&
        (cipher_type.at(3) == 'Y') && (cipher_type.at(4) == 'B') &&
        (cipher_type.at(5) == 'I') && (cipher_type.at(6) == 'U') &&
        (cipher_type.at(7) == 'S')))
    {
        user_message = toUpperCase(user_message);
        cout << "What is your key: ";
        getline(cin, key_poly_vig);
        key_poly_vig = toUpperCase(key_poly_vig);
        key_poly_vig = removeDuplicate(key_poly_vig);
        char grid[SIZE][SIZE];
        enc_decr_message = polybiusSquare(grid, key_poly_vig, user_message,
                                          mode_ed);
    }
    
    //printing the encrypted or decrypted message based on the user entered mode
    if (mode_ed == true)
    {
        cout << "The encrypted message is: " << enc_decr_message;
    }
    else
    {
        cout << "The decrypted message is: " << enc_decr_message;
    }
}
