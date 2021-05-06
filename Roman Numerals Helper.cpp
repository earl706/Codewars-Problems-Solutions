/*
4 kyu

Create a RomanNumerals class that can convert a roman numeral to and from an integer value. It should follow the API demonstrated in the examples below. Multiple roman numeral values will be tested for each helper method.

Modern Roman numerals are written by expressing each digit separately starting with the left most digit and skipping any digit with a value of zero. In Roman numerals 1990 is rendered: 1000=M, 900=CM, 90=XC; resulting in MCMXC. 2008 is written as 2000=MM, 8=VIII; or MMVIII. 1666 uses each Roman symbol in descending order: MDCLXVI.

Examples
RomanNumerals.toRoman(1000); // should return 'M'
RomanNumerals.fromRoman('M'); // should return 1000
Help
Symbol	Value
I	1
V	5
X	10
L	50
C	100
D	500
M	1000

LINK:https://www.codewars.com/kata/51b66044bce5799a7f000003/train/cpp
*/

//MY SOLUTION
#include <cmath>
#include <string>
#include <vector>
#include <map>

class RomanNumerals{
public:
  std::map<std::string, int> numerals =
    {
        {"I", 1},
        {"IV", 4},
        {"V", 5},
        {"IX", 9},
        {"X", 10},
        {"XL", 40},
        {"L", 50},
        {"XC", 90},
        {"C", 100},
        {"CD", 400},
        {"D", 500},
        {"CM", 900},
        {"M", 1000}
    };
    std::string to_roman(int n);
    int from_roman(std::string s);
};

std::string RomanNumerals::to_roman(int n)
{
    std::string res;
    std::vector<int> keys = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::vector<std::string> values = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    while(n != 0)
    {
        for(size_t i = 0; i < keys.size(); i++)
        {
            int num = floor(n/keys[i]);
            for(int j = 0; j < num; j++)
            {
                res += values[i];
            }
            n -= (num * keys[i]);
        }
    }
    return res;
}

int RomanNumerals::from_roman(std::string s)
{
    int res = 0;
    for(size_t i = 0; i < s.length(); i++)
    {
        if(numerals[(s.substr(i, 1) + s.substr(i + 1, 1))])
        {
            res += numerals[s.substr(i, 1) + s.substr(i + 1, 1)];
            i++;
        }
        else
        {
            res += numerals[s.substr(i, 1)];
        }
    }
    return res;
}

RomanNumerals RomanNumerals;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//BETTER SOLUTION
#include <unordered_map>

using namespace std;

class RNHelper {
public:
    string to_roman(int num) {
        string r[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int n[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string rnum = "";
        for (int i = 0 ; i < 13; ++i) {
            while (num >= n[i]) {
                num -= n[i];
                rnum += r[i];
            }
        }
        return rnum;
    }
    
    int from_roman(string rnum) {
        unordered_map<char, int> ri = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int n = rnum.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            if (i + 1 < n && ri[rnum[i]] < ri[rnum[i+1]])
                res -= ri[rnum[i]];
            else res += ri[rnum[i]];
        }
        return res;
    }
};

RNHelper RomanNumerals;
