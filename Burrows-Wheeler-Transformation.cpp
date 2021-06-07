/*
4 KYU

Motivation
When compressing sequences of symbols, it is useful to have many equal symbols follow each other, because then they can be encoded with a run length encoding. For example, RLE encoding of "aaaabbbbbbbbbbbcccccc" would give something like 4a 11b 6c.

(Look here for learning more about the run-length-encoding.)

Of course, RLE is interesting only if the string contains many identical consecutive characters. But what bout human readable text? Here comes the Burrows-Wheeler-Transformation.

Transformation
There even exists a transformation, which brings equal symbols closer together, it is called the Burrows-Wheeler-Transformation. The forward transformation works as follows: Let's say we have a sequence with length n, first write every shift of that string into a n x n matrix:

Input: "bananabar"

b a n a n a b a r
r b a n a n a b a
a r b a n a n a b
b a r b a n a n a
a b a r b a n a n
n a b a r b a n a
a n a b a r b a n
n a n a b a r b a
a n a n a b a r b
Then we sort that matrix by its rows. The output of the transformation then is the last column and the row index in which the original string is in:

               .-.
a b a r b a n a n
a n a b a r b a n
a n a n a b a r b
a r b a n a n a b
b a n a n a b a r <- 4
b a r b a n a n a
n a b a r b a n a
n a n a b a r b a
r b a n a n a b a
               '-'

Output: ("nnbbraaaa", 4)
Of course we want to restore the original input, therefore you get the following hints:

The output contains the last matrix column.
The first column can be acquired by sorting the last column.
For every row of the table: Symbols in the first column follow on symbols in the last column, in the same way they do in the input string.
You don't need to reconstruct the whole table to get the input back.
Goal
The goal of this Kata is to write both, the encode and decode functions. Together they should work as the identity function on lists. (Note: For the empty input, the row number is ignored.)

Further studies
You may have noticed that symbols are not always consecutive, but just in proximity, after the transformation. If you're interested in how to deal with that, you should have a look at this Kata.


LINK:https://www.codewars.com/kata/54ce4c6804fcc440a1000ecb/train/cpp

*/

#include <string>
#include <vector>

std::pair<std::string, int> encode(const std::string &s) {
    std::string str = "";
    std::pair<std::string, int> res;
    std::vector<std::string> matrix;
    for(size_t i = 0; i < s.length(); i++)
    {
        std::string tempStr = "";
        for(size_t e = 0; e < s.length(); e++)
        {
            tempStr += s[(i+e)%s.length()];
        }
        matrix.push_back(tempStr);
    }
    std::sort(matrix.begin(), matrix.end());
    for(size_t i = 0; i < matrix.size(); i++)
    {
        str += matrix[i][s.length() - 1];
    }
    for(size_t i = 0; i < s.length(); i++)
    {
        if(matrix[i] == s)
        {
            res.second = i;
        }
    }
    res.first = str;
    return res;
}

std::string decode(const std::string &s, int n) {
    std::string res = "";
    std::vector<std::string> cols;
    for(auto a:s)
    {
        cols.push_back(std::to_string(a));
    }
    std::sort(cols.begin(), cols.end());
    for(size_t i = 0; i < s.length(); i++)
    {
        for(size_t e = 0; e < s.length(); e++)
        {
            cols.at(e).insert(cols.at(e).begin(), s[e]);
        }
        std::sort(cols.begin(), cols.end());
        res += cols[n][i];
    }
    return res;
}
