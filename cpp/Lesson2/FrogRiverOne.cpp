// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, vector<int> &A) {
    // write your code in C++11
    vector<int> time(X,-1);
    
    for (unsigned int i = 0; i < A.size(); ++i)
    {
        if (time[A[i] - 1] == -1)
        {
            time[A[i] - 1] = i;
        }
    }
    
    int result = -1;
    
    for (auto it = time.begin(); it != time.end(); ++it)
    {
        if (*it == -1)
            return -1;
        if (*it > result)
            result = *it;
    }
    
    return result;
}

