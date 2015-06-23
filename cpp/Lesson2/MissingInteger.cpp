// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11
    vector<int> positiveNum(A.size() + 2, 0);
    for (auto it = A.begin(); it != A.end(); ++it)
    {
        // check if item is in bounds
        if (*it > 0 && *it < positiveNum.size())
        {
            positiveNum[*it] = 1;
        }
    }
    for (unsigned int i = 1; i < positiveNum.size(); ++i)
    {
        if (positiveNum[i] == 0)
        {
            return i;
        }
    }
    
    // should never happen
    return 1;
}

