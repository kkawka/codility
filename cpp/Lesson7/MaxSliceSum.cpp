// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11
    long long int result = A.front();
    long long int currSum = 0;
    for (auto it = A.begin(); it != A.end(); ++it)
    {
        currSum += *it;
        if (currSum > result)
        {
            result = currSum;
        }
        if (0 > currSum)
        {
            currSum = 0;
        }
    }
    return result;
}

