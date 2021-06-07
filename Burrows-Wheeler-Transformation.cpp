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
