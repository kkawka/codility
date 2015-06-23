// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int M, vector<int> &A) {
    // write your code in C++11
    vector<int> accessIdx (M+2, -1); 
    int size = A.size();
    int result = 0;
    
    int start = 0;
    int end = 0;
    for (; end < size; ++end)
    {
        if (accessIdx[A[end]] == -1)
        {
            accessIdx[A[end]] = end;
        }   
        else
        {
            int newStart = accessIdx[A[end]] + 1;
            result += (newStart - start) * (2*end - start - newStart + 1) / 2;
            if (result >= 1000000000)
            {
                return 1000000000;
            }
                        
            
            for (int i = start; i < newStart; ++i)
            {
                accessIdx[A[i]] = -1
            }
            accessIdx[A[end]] = end;
 
            start = newStart;
        }
    }
    int len = end - start;
    result += (len + 1) * (len + 2) / 2;
    return std::min(result, 1000000000);
}

