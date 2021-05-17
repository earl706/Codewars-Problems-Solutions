/*
4 KYU

In this kata we want to convert a string into an integer. The strings simply represent the numbers in words.

Examples:

"one" => 1
"twenty" => 20
"two hundred forty-six" => 246
"seven hundred eighty-three thousand nine hundred and nineteen" => 783919
Additional Notes:

The minimum number is "zero" (inclusively)
The maximum number, which must be supported is 1 million (inclusively)
The "and" in e.g. "one hundred and twenty-four" is optional, in some cases it's present and in others it's not
All tested numbers are valid, you don't need to validate them

LINK: https://www.codewars.com/kata/525c7c5ab6aecef16e0001a5/train/cpp

*/
#include <string>
#include <map>
#include <vector>

std::map<std::string, int> numberSystem{
    {"one", 1}, {"two", 2}, {"three", 3},
    {"four", 4}, {"five", 5}, {"six", 6},
    {"seven", 7}, {"eight", 8}, {"nine", 9},
    {"ten", 10}, {"eleven", 11}, {"twelve", 12},
    {"thirteen", 13}, {"fourteen", 14}, {"fifteen", 15},
    {"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18},
    {"nineteen", 19}, {"twenty", 20}, {"thirty", 30},
    {"forty", 40}, {"fifty", 50}, {"sixty", 60},
    {"seventy", 70}, {"eighty", 80}, {"ninety", 90},
    {"hundred", 100}, {"thousand", 1000}, {"million", 1000000}
};

long parse_int(std::string number) {
    long res = 0, subres = 0;
    std::vector<std::string> nums, placeValues;
    std::string subStr = "";
    for(auto a:number)
    {
        if(a == ' ' or a == '-')
        {
            nums.push_back(subStr);
            if((subStr == "hundred" or subStr == "thousand") and placeValues.size() < 3)
            {
                placeValues.push_back(subStr);
            }
            subStr = "";
        }
        else
        {
            subStr += a;
        }
    }
    nums.push_back(subStr);
    if((subStr == "hundred" or subStr == "thousand") and placeValues.size() < 3)
    {
        placeValues.push_back(subStr);
    }
    if(placeValues.size() > 1)
        {
            if(placeValues[0] == "hundred" and placeValues[1] == "thousand")
            {
                res += (numberSystem[nums[0]] * 100000);
                std::reverse(nums.begin(), nums.end());
                nums.pop_back();
                nums.pop_back();
                std::reverse(nums.begin(), nums.end());
            }
        }
    for(auto a: nums)
    {
        if(a == "hundred" or a == "thousand" or a == "million")
        {
            subres *= numberSystem[a];
            res += subres;
            subres = 0;
        }
        else
        {
            subres += numberSystem[a];
        }
    }
    res += subres;
    return res;
}
