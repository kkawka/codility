// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11
    std::sort(A.begin(), A.end());
    int currNum = -1000001;
    int result = 0;
    for (auto it = A.begin(); it != A.end(); ++it)
    {
        if (*it != currNum)
        {
            result++;
            currNum = *it;
        }
    }
    return result;
}

