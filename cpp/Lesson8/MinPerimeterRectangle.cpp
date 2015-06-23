// you can use includes, for example:
#include <limits.h>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++11
    long long int result = LLONG_MAX;
    for (int i = 1; i*i <= N; ++i)
    {
        if (N % i == 0)
        {
            int A = N / i;
            int perimeter = 2*(A+i);
            if (perimeter < result) 
            {
                result = perimeter;
            }
        }
    }
    return result;
}

