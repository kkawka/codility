// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <numeric>      // std::accumulate

int solution(vector<int> &A) {
    // write your code in C++11
    long long size = A.size() +1; 
    long long expectedSum = size * (1 + size) / 2;
    long long calculatedSum = std::accumulate(A.begin(), A.end(), 0);
    return expectedSum - calculatedSum;
}

