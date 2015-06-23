// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++11
    int result = 0;
    long long int i = 1;
    long long int LN = N;
    for (; i*i < LN; ++i)
    {
        if (LN % i == 0)
        {
            result += 2;
        }
    }
    if (i*i == LN)
    {
        result++;
    }
    return result;
}

