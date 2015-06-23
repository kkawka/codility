// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int getBlocksCnt(const vector<int> &A, int sumLimit)
{
    int result = 1;
    int currSum = 0;
    for (int i = 0; i < (int)A.size(); ++i)
    {
        if (currSum + A[i] > sumLimit)
        {
            currSum = A[i];
            result++;
        }
        else
        {
            currSum += A[i];
        }
    }
    return result;
}

int solution(int K, int M, vector<int> &A) {
    // write your code in C++11
    
    int maxPossibleSum = std::accumulate(A.begin(), A.end(), 0);
    int minPossibleSum = *std::max_element(A.begin(), A.end());
    
    if (K == 1) return maxPossibleSum;
    if (K > (int)A.size() ) return minPossibleSum;
    
    int result = 0;
    
    while (minPossibleSum <= maxPossibleSum)
    {
        int median = (maxPossibleSum + minPossibleSum) / 2;
        if (getBlocksCnt(A, median) <= K)
        {
            result = median;
            maxPossibleSum = median - 1;
        }
        else
        {
            minPossibleSum = median + 1;
        }
    }
    
    return result;
}

