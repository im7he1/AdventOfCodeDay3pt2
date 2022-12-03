#include <vector>
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
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
    return FinalCommonLetter[0];
}
int main()
{
    std::cout << "Advent of code Puzzle Day 3 part 2.\n";
    std::cout << "----------------------------\n\n";
    std::cout << "start puzzle\n\n";

    int ThreeCounter = 1;
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
        if (ThreeCounter == 1) {
            line1 = EntireStringLine;
        }

        if (ThreeCounter == 2) {
            line2 = EntireStringLine;
        }

        if (ThreeCounter == 3) {
            line3 = EntireStringLine;
            ThreeCounter = 0;
            CommonCharacter = GetCommonLetterPostion(line1, line2, line3);

            asciiValue = CommonCharacter;
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
