
// you can use includes, for example:
#include <algorithm>
#include <stdio.h> 

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11
    std::sort(A.begin(), A.end());
    int size = A.size(); 
    int result = 0;
    for (int i = 0; i < size - 2; ++i)
    {
        int k = i+2;
        for (int j = i+1; j < size - 1; ++j)
        {
            while k < size && (A[i] + A[j] >A[k])
            {
                k++;
            }
            result += k - j - 1;
        }
    }
    return result;
}

