// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int K, vector<int> &A) {
    // write your code in C++11
    int size = A.size();
    int currLen = 0;
    int result = 0;
    for (int i = 0; i < size; ++i)
    {
        currLen += A[i];
        while (currLen >= K)
        {
            currLen = 0;
            result++;
        }
    }
    return result;
}

