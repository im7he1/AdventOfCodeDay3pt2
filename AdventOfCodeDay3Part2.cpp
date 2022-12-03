// AdventOfCodeDay3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
using namespace std;


char GetCommonLetterPostion(string S1, string S2, string S3)
{
    vector<char> v1(S1.begin(), S1.end());
    vector<char> v2(S2.begin(), S2.end());
    vector<char> v3(S3.begin(), S3.end());
    vector<char> CommonLetters;
    vector<char> FinalCommonLetter;
    
    for (const char& c1 : v1) {
        for (const char& c2 : v2) {
            if (c1 == c2) { CommonLetters.push_back(c1); }
        }
    }

    for (const char& c3 : v3) {
        for (const char& c4 : CommonLetters) {
            if (c3 == c4) { FinalCommonLetter.push_back(c4); }
        }
    }

    std::cout << "Final Common Letter is:  " << FinalCommonLetter[0] << "\n";
    return FinalCommonLetter[0];


   

}

int main()
{
    std::cout << "Advent of code Puzzle Day 3 part 2.\n";
    std::cout << "----------------------------\n\n";

    int ThreeCounter = 1;

    std::cout << "start puzzle\n\n";

    string EntireStringLine;
    char CommonCharacter;
    int asciiValue;
    int runningTotal = 0;

    string line1;
    string line2;
    string line3;

    //load input file
    std::ifstream infile("AC3.csv", std::ios::in);

    while (infile >> EntireStringLine)
    {
        std::cout << "The Entire String line is: " << EntireStringLine << "\n";
        if (ThreeCounter == 1) {
            line1 = EntireStringLine;
            std::cout << "line 1 is: " << line1 << "\n"; 
        }

        if (ThreeCounter == 2) {
            line2 = EntireStringLine;
            std::cout << "line 2 is: " << line2 << "\n";
        }

        if (ThreeCounter == 3) {
            line3 = EntireStringLine;
            std::cout << "line 3 is: " << line3 << "\n";
            ThreeCounter = 0;
            CommonCharacter = GetCommonLetterPostion(line1, line2, line3);

            asciiValue = CommonCharacter;
            std::cout << "ascci value is : " << asciiValue << "\n";
            if (asciiValue >= 65 && asciiValue <= 90)
                asciiValue = asciiValue - 64 + 26;
            else
            {
                asciiValue = asciiValue - 96;
            }

            runningTotal += asciiValue;

        }
        ThreeCounter++;



        
    }

    std::cout << "Total Value of shared items is : " << runningTotal << "\n";

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
