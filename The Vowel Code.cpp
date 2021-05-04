/*
6 kyu

Step 1: Create a function called encode() to replace all the lowercase vowels in a given string with numbers according to the following pattern:

a -> 1
e -> 2
i -> 3
o -> 4
u -> 5

For example, encode("hello") would return "h2ll4". There is no need to worry about uppercase vowels in this kata.

Step 2: Now create a function called decode() to turn the numbers back into vowels according to the same pattern shown above.

For example, decode("h3 th2r2") would return "hi there".

For the sake of simplicity, you can assume that any numbers passed into the function will correspond to vowels.

LINK: https://www.codewars.com/kata/53697be005f803751e0015aa/train/cpp
*/

//MY CODE

#include <string>
#include <map>

std::map<char, int> vowels = {
    {'a', '1'},
    {'e', '2'},
    {'i', '3'},
    {'o', '4'},
    {'u', '5'}
};

std::string encode(std::string str) {
    std::string res;
    for(auto a: str)
    {
        if(vowels[a])
        {
            res += vowels[a];
        }
        else
        {
            res += a;
        }
    }
    return res;
}

std::string decode(std::string str) {
    std::map<int, char> vowelsDecode;
    std::string res;
    for(auto [key, val]: vowels)
    {
        vowelsDecode[val] = key;
    }
    for(auto a : str)
    {
        if(vowelsDecode[a])
        {
            res += vowelsDecode[a];
        }
        else
        {
            res += a;
        }
    }
    return res;
}

//BETTER SOLUTION

#include <map>
#include <string>

std::string encode(std::string s) {
  static std::map<char, char> d {{'a', '1'}, {'e', '2'}, {'i', '3'}, {'o', '4'}, {'u', '5'}};
  for (auto &x : s) if (d.count(x)) x = d[x];
  return s;
}

std::string decode(std::string s) {
  for (auto &x : s) if ('0' < x && x < '6') x = "aeiou"[x - '1'];
  return s;
}
