/**
 * test.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * EECS 183: Project 3
 * Winter 2021
 *
 * Divyanga Bajoria
 * bajoriad
 *
 *
 * Description: Testing functions for your ciphers.cpp implementation by testing
 * functions declared in utility.h , caesar.h, vigenere.h & polybius.h
 *
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>

using namespace std;

void testtoUpperCase();
void testremoveNonAlphas();
void testremoveDuplicate();
void testcharToInt();
void testshiftAlphaCharacter();
void testcaesarCipher();
void testvigenereCipher();
void testfillGrid();
void testmixKey();
void testfindInGrid();
void testpolybiusSquare();


void startTests()
{
    
    testtoUpperCase();
    testremoveNonAlphas();
    testremoveDuplicate();
    testcharToInt();
    testshiftAlphaCharacter();
    testcaesarCipher();
    testvigenereCipher();
    testfillGrid();
    testmixKey();
    testfindInGrid();
    testpolybiusSquare();
    
    return;
}


void testtoUpperCase()
{
    cout << " Expected: HELLO, Actual: " << toUpperCase("Hello") << endl;
    cout << " Expected: HELLO, Actual: " << toUpperCase("HELLO") << endl;
    cout << " Expected: I WAS BORN IN 1999, Actual: " << toUpperCase("I was born in 1999") << endl;
    cout << "Expected: HIS NAME IS SAM PETER99, Actual: " << toUpperCase("HIS name is Sam Peter99") << endl;
    cout << "Expected: HELLO FROM EECS 183!, Actual: " << toUpperCase("Hello from EECS 183!") << endl;
    return;
}


void testremoveNonAlphas()
{
    cout << " Expected: Iamyearsold, Actual: " << removeNonAlphas("I am 10 years old/") << endl;
    cout << " Expected: Myemailidissamgmailcom, Actual: " << removeNonAlphas("My email_id is sam99@gmail.com.") << endl;
    cout << "Expected: She is, Actual: " << removeNonAlphas("She is %$^&, 99") << endl;
    cout << "Expected:  , Actual: " << removeNonAlphas("8888888888") << endl;
    cout << "Expected: UNO , Actual: " << removeNonAlphas("!~`$^&*()_+{}|UNO") << endl;
    cout << "Expected: Indiana, Actual: " << removeNonAlphas(";;'_',.,.?<>Indiana") << endl;
    cout << "Expected: INdIA , Actual: " << removeNonAlphas("I_N'[d+-I<>A") << endl;
    return;
}


void testremoveDuplicate()
{
    cout << "Expected: HELO, Actual: " << removeDuplicate("HELLO") << endl;
    cout << "Expected: HELO1, Actual: " << removeDuplicate("HELLO111") << endl;
    cout << "Expected: ABCD9876, Actual: " << removeDuplicate("AABBCDB998766") << endl;
    cout << "Expected: COMENTAR89, Actual: " << removeDuplicate("COMMMENTATOR8899") << endl;
    cout << "Expected: 8HARY, Actual: " << removeDuplicate("88888HARRRRYYYY") << endl;
    return;
}


void testcharToInt()
{
    cout << "Expected: 0, Actual: " << charToInt('0') << endl;
    cout << "Expected: 1, Actual: " << charToInt('1') << endl;
    cout << "Expected: 3, Actual: " << charToInt('3') << endl;
    cout << "Expected: 5, Actual: " << charToInt('5') << endl;
    cout << "Expected: 6, Actual: " << charToInt('6') << endl;
    cout << "Expected: 7, Actual: " << charToInt('7') << endl;
    cout << "Expected: 8, Actual: " << charToInt('8') << endl;
    cout << "Expected: 9, Actual: " << charToInt('9') << endl;
    cout << "Expected: 2, Actual: " << charToInt('2') << endl;
    cout << "Expected: 4, Actual: " << charToInt('4') << endl;
    return;
}


void testshiftAlphaCharacter()
{
    cout << "Expected: K, Actual: " << shiftAlphaCharacter('A', 10) << endl;
    cout << "Expected: V, Actual: " << shiftAlphaCharacter('B', 20) << endl;
    cout << "Expected: C, Actual: " << shiftAlphaCharacter('X', 5) << endl;
    cout << "Expected: X, Actual: " << shiftAlphaCharacter('X', 26) << endl;
    cout << "Expected: X, Actual: " << shiftAlphaCharacter('X', -26) << endl;
    cout << "Expected: V, Actual: " << shiftAlphaCharacter('X', 50) << endl;
    cout << "Expected: A, Actual: " << shiftAlphaCharacter('A', 0) << endl;
    cout << "Expected: Z, Actual: " << shiftAlphaCharacter('Z', 0) << endl;
    cout << "Expected: A, Actual: " << shiftAlphaCharacter('A', 26) << endl;
    cout << "Expected: Z, Actual: " << shiftAlphaCharacter('Z', 26) << endl;
    cout << "Expected: A, Actual: " << shiftAlphaCharacter('A', -26) << endl;
    cout << "Expected: Z, Actual: " << shiftAlphaCharacter('Z', -26) << endl;
    cout << "Expected: T, Actual: " << shiftAlphaCharacter('D', -10) << endl;
    cout << "Expected: G, Actual: " << shiftAlphaCharacter('E', -50) << endl;
    cout << "Expected: k, Actual: " << shiftAlphaCharacter('a', 10) << endl;
    cout << "Expected: v, Actual: " << shiftAlphaCharacter('b', 20) << endl;
    cout << "Expected: c, Actual: " << shiftAlphaCharacter('x', 5) << endl;
    cout << "Expected: x, Actual: " << shiftAlphaCharacter('x', 26) << endl;
    cout << "Expected: x, Actual: " << shiftAlphaCharacter('x', -26) << endl;
    cout << "Expected: v, Actual: " << shiftAlphaCharacter('x', 50) << endl;
    cout << "Expected: a, Actual: " << shiftAlphaCharacter('a', 0) << endl;
    cout << "Expected: z, Actual: " << shiftAlphaCharacter('z', 0) << endl;
    cout << "Expected: a, Actual: " << shiftAlphaCharacter('a', 26) << endl;
    cout << "Expected: z, Actual: " << shiftAlphaCharacter('z', 26) << endl;
    cout << "Expected: a, Actual: " << shiftAlphaCharacter('a', -26) << endl;
    cout << "Expected: z, Actual: " << shiftAlphaCharacter('z', -26) << endl;
    cout << "Expected: t, Actual: " << shiftAlphaCharacter('d', -10) << endl;
    cout << "Expected: u, Actual: " << shiftAlphaCharacter('e', 16) << endl;
    return;
}


void testcaesarCipher()
{
    cout << "Expected: Cuuj cu qj jxu Tyqw qj 11 f.c., Actual: " << caesarCipher("Meet me at the Diag at 11 p.m.", 42, true) << endl;
    cout << "Expected: Meet me at the Diag at 11 p.m., Actual: " << caesarCipher("Cuuj cu qj jxu Tyqw qj 11 f.c.", 42, false) << endl;
    return;
}


void testvigenereCipher()
{
    cout << "Expected: Euyb dv ee lxy Lzrk ll 11 f.g., Actual: " << vigenereCipher("Meet me at the Diag at 11 p.m.", "Squirrel!", true) << endl;
    cout << "Expected: Meet me at the Diag at 11 p.m., Actual: " << vigenereCipher("Euyb dv ee lxy Lzrk ll 11 f.g.", "Squirrel!", false) << endl;
    return;
}


void testfillGrid()
{
    char grid[SIZE][SIZE];
    
    fillGrid(grid, ALNUM);
    printGrid(grid);
    
    fillGrid(grid, "abcdefghijklmnopqrstuvwxyzabcdefghij");
    printGrid(grid);
    
    fillGrid(grid, "012345678910111213141516171819202122");
    printGrid(grid);
    
    fillGrid(grid, "0123456789101112131tuvwxyzabcdefghij");
    printGrid(grid);
    return;
}


void testmixKey()
{
    cout << "Expected: POLYBIUSACDEFGHJKMNQRTVWXZ0123456789, Actual: " << mixKey("POLYBIUS") << endl;
    cout << "Expected: DIVYANGBCEFHJKLMOPQRSTUWXZ0123456789, Actual: " << mixKey("DIVYANG") << endl;
    cout << "Expected: DIVY02468ABCEFGHJKLMNOPQRSTUWXZ13579, Actuak: " << mixKey("DIVY02468") << endl;
    return;
}


void testfindInGrid()
{
    char grid[SIZE][SIZE];
    fillGrid(grid, ALNUM);
    cout << "Expected: 00, Actual: " << findInGrid('A', grid) << endl;
    fillGrid(grid, ALNUM);
    cout << "Expected: 14 ,Actual: " << findInGrid('K', grid) << endl;
    fillGrid(grid, ALNUM);
    cout << "Expected: 45 ,Actual: " << findInGrid('3', grid) << endl;
    fillGrid(grid, "POLYBIUSACDEFGHJKMNQRTVWXZ0123456789");
    cout << "Expected: 12 ,Actual: " << findInGrid('A', grid) << endl;
    return;
}


void testpolybiusSquare()
{
    char grid[SIZE][SIZE];
    cout << "Expected: 11110533 000102 1533 341411 04113334, Actual: " << polybiusSquare(grid, "183", "EECS 183 IS THE BEST", true) << endl;
    cout << "Expected: EECS 183 IS THE BEST, Actual: " << polybiusSquare(grid, "183", "11110533 000102 1533 341411 04113334", false) << endl;
    return;
}
