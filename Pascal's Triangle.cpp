/*
6 kyu

In mathematics, Pascal's triangle is a triangular array of the binomial coefficients expressed with formula

(nk)=n!k!(n−k)
 
where n denotes a row of the triangle, and k is a position of a term in the row.

Pascal's Triangle

You can read Wikipedia article on Pascal's Triangle for more information.

Task
Write a function that, given a depth n, returns n top rows of Pascal's Triangle flattened into a one-dimensional list/array.

Example:
n = 1: [1]
n = 2: [1,  1, 1]
n = 4: [1,  1, 1,  1, 2, 1,  1, 3, 3, 1]
Note
Beware of overflow. Requested terms of a triangle are guaranteed to fit into the returned type, but depending on seleced method of calculations, intermediate values can be larger.

link: https://www.codewars.com/kata/5226eb40316b56c8d500030f/train/cpp
*/

std::vector<long long> pascalsTriangle(int n)
{
    std::vector<std::vector<long long>> pascalTriad;
    std::vector<long long> output;
    for(int i = 1; i<=n ; i++)
    {
        std::vector<long long> subPart;
        if(pascalTriad.size() > 1){
            subPart.push_back(1);
            for(int i = 0; i <= pascalTriad.back().size() - 2; i++)
            {
                subPart.push_back(pascalTriad.back()[i] + pascalTriad.back()[i + 1]);
            }
            subPart.push_back(1);
        }
        else if(pascalTriad.size() == 1){
            subPart.push_back(1);
            subPart.push_back(1);
        }
        else{
            subPart.push_back(1);
        }
        pascalTriad.push_back(subPart);
    }
    for(std::vector<long long> a: pascalTriad)
    {
        for(long long e: a)
        {
            output.push_back(e);
        }
    }
    return output;
}
