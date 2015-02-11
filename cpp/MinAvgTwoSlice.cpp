// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11
    // minimal avg slice must be the size od 2 or 3 
    int result = 0;
    double minAvgSlice = (A[0] + A[1]) / 2.0;
    
    for (unsigned int i = 2; i < A.size(); ++i)
    {
        if (((A[i] + A[i-1]) / 2.0) < minAvgSlice)
        {
            result = i-1;
            minAvgSlice = (A[i] + A[i-1]) / 2.0;
        }
        
        if (((A[i] + A[i-1] + A[i-2]) / 3.0) < minAvgSlice)
        {
            result = i-2;
            minAvgSlice = (A[i] + A[i-1] + A[i-2]) / 3.0;
        }
    }
    
    return result;
}

