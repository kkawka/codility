// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <numeric>

int solution(vector<int> &A) {
    // write your code in C++11
    long long result = 0;
    int carsToWest = std::accumulate(A.begin(), A.end(), 0);
    
    for (auto it = A.begin(); it != A.end(); ++it) 
    {
        if (*it == 1)
        {
            --carsToWest;
        }
        else
        {
            result += carsToWest;
        }
    }
    
    if (result > 1000000000)
    {
        return -1;
    }
    
    return result;
}

