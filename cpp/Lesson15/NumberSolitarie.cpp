// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11
    vector<int> partResult(A.size(), 0);
    int size = A.size();
    partResult[0] = A[0];
    
    for(int i = 1; i < size; ++i)
    {
        partResult[i] = partResult[i-1]; 
        for (int j = 2; j < 7 && i - j >= 0; ++j)
        {
            if (partResult[i] < partResult[i-j])
            {
                partResult[i] = partResult[i-j];
            }
        }
        partResult[i] += A[i];
    }
    return partResult[size-1];
}

