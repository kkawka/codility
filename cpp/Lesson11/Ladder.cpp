// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A, vector<int> &B) {
    // write your code in C++11
    int maxEl = *std::max_element(A.begin(), A.end()); 
    int maxB =  *std::max_element(B.begin(), B.end()); 
    int maxModulo = 1 << maxB;
    vector<long long> results(maxEl + 1, 0); 
    results[0] = 0;
    results[1] = 1;
    results[2] = 2;
    for (unsigned int i = 3; i < maxEl + 1; ++i)
    {
        results[i] = (results[i-1] + results[i-2]) % maxModulo;
    }
    
    vector<int> result; 
    for (unsigned int i = 0; i < A.size(); ++i)
    {
        result.push_back(results[A[i]] % (1 << B[i]));
    }
    return result;
}
