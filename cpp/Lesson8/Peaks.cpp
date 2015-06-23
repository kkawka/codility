// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool isPeak(int candidate, int nL, int nR)
{
    return candidate > nL && candidate > nR;
}

int solution(vector<int> &A) {
    // write your code in C++11
    // check possible solutions .. 
    
    vector<int> peaksPos;
    peaksPos.reserve(A.size()/2);

    // find peaks         
    for (unsigned int i = 1; i < A.size() - 1; ++i)
    {
        if (isPeak(A[i], A[i-1], A[i+1]))
        {
            peaksPos.push_back(i);
        }
    }
    
    // calculate possible max -> number of peaks
    if (peaksPos.size() == 0) 
    {
        return 0;
    }
    
    for (unsigned int blockSize = 2; blockSize <= A.size(); ++blockSize)
    {
        if (A.size() % blockSize != 0)
        {
            continue;
        }
        int blocksCnt = A.size() / blockSize;
        int currBlock = 0;
        
        for (auto it = peaksPos.begin(); it != peaksPos.end(); ++it)
        {        

            int peakBlock = *it / blockSize;
            if (peakBlock == currBlock)
            {
                currBlock++;
            }
            if (peakBlock > currBlock)
            {
                break;
            }
        }
        
        if (currBlock == blocksCnt)
        {
            return blocksCnt;
        }
    }
    
    return 0;
}

