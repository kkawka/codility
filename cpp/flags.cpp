// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <math.h>
#include <algorithm>  

bool isPeak (int nL, int p, int nR)
{
    return (nL < p && nR < p);
}

bool canTakeKFlags(int k, vector<int> &peaks)
{
    int lastFlagPos = peaks.front();
    int flagsLeft = k - 1;
    for (auto it = peaks.begin(); it != peaks.end(); ++it)
    {
        if (*it - lastFlagPos >= k)
        {
            //set new flag
            flagsLeft--;
            lastFlagPos = *it;
        }
        if (flagsLeft == 0)
        {
            return true;
        }
    }
    
    return false;
}

int solution(vector<int> &A) {
    // write your code in C++11
    
    vector<int> peaks; 
    peaks.reserve(A.size());
    
    for (unsigned int i = 1; i < A.size() - 1; ++i)
    {
        if (isPeak(A[i-1],A[i],A[i+1]))
        {
            peaks.push_back(i);
        }
    }
    
    int possibleMaxFlags = static_cast<int> (sqrt(A.size()) + 1);
    if (possibleMaxFlags > (int)peaks.size())
    {
        possibleMaxFlags = peaks.size();
    }

    for (unsigned int i = possibleMaxFlags; i > 0; --i)
    {
        if (canTakeKFlags(i, peaks))
        {
            return i;
        }
    }
    
    return 0;
}

