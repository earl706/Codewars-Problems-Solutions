/*
5 kyu 
Write an algorithm that takes an array and moves all of the zeros to the end, preserving the order of the other elements.

move_zeros({1, 0, 1, 2, 0, 1, 3}) // returns {1, 1, 2, 1, 3, 0, 0}
*/

/* my solution */
std::vector<int> move_zeroes(const std::vector<int>& input) {
    std::vector<int> res;
    int index = 0;
    for( auto a: input)
    {
        if(a != 0){
            res.push_back(a);
        }
        else
        {
            index++;
        }
    }
    for(int i = 0; i < index; i++)
    {
        res.push_back(0);
    }
    return res;
}

/* better solution */

auto move_zeroes(std::vector<int> v) {
  stable_partition(begin(v), end(v), std::negate());
  return v;
}
