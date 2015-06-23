// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11
    vector<long long> openDiskPos(A.size() + 2, 0);
    vector<long long> closeDiskPos(A.size() + 2, 0);
    
    for (long long i = 0; i < (long long)A.size(); ++i )
    {
        long long openDisk = i - A[i] < 0 ? 0 : i - A[i];
        long long closeDisk = i + A[i] < (long long)A.size() ? i + A[i] : A.size();
        openDiskPos[openDisk] += 1;
        closeDiskPos[closeDisk] += 1;
    }

    long long result = 0 ;    
    long long openDisksCnt = 0;
    
    for (unsigned int i = 0; i < openDiskPos.size(); ++i)
    {
        openDisksCnt += openDiskPos[i];
        while (closeDiskPos[i] > 0)
        {
            result += --openDisksCnt;
            closeDiskPos[i] -= 1;
        }
    }
    
    if (result > 10000000)
    {
        return -1;
    }
    
    return result;
}

