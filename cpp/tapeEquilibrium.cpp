// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <numeric>


int solution(vector<int> &A) {
    // write your code in C++11
    int left    = A[0];
    int right   = std::accumulate(A.begin() + 1, A.end(), 0);
    int minDiff = std::abs(left - right);
    
    for (unsigned int i = 1; i < A.size() - 1; ++i)
    {
        left  += A[i];
        right -= A[i];
        if (minDiff > std::abs(left - right))
        {
            minDiff = std::abs(left - right);
        }
    }
    
    return minDiff;
}

