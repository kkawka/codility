// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool areOverlapping (int a1, int b1, int a2, int b2)
{
    return ((a1 <= a2) && (a2 <= b1)) || ((a2 <= a1) && (a1 <= b2));
}

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++11
    int result = 0;
    if (A.size() > 0)
    {
        ++result;
        int cIdx = 0;
        for (unsigned i = 1; i < A.size(); ++i)
        {
            if (areOverlapping(A[cIdx], B[cIdx], A[i], B[i]))
            {
                
                //printf("areOverlapping %d %d %d %d \n", A[cIdx], B[cIdx], A[i], B[i]);
                continue;
            }
            cIdx = i;
            ++result;
        }
    }
    return result;
}

