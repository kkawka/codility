// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

void generateFibNumbers(vector<int> &fibNums, int size)
{
    fibNums.push_back(1);
    fibNums.push_back(1);
    
    int fibNumPrev = 1; 
    int fibNumCurr = 1; 
    
    while (fibNumCurr < size)
    {
        int fibNumNext = fibNumPrev + fibNumCurr; 
        fibNumPrev = fibNumCurr;
        fibNumCurr = fibNumNext;
        fibNums.push_back(fibNumNext);
    }
}

void printfArray(const vector<int>& arr)
{
    printf (">>>>>>>>>>>>>>>>> \n ");
    for (int num : arr)
    {
        printf ("%d ", num);
    }
    printf ("\n >>>>>>>>>>>>>>>>> \n ");
}

int solution(vector<int> &A) {
    // write your code in C++11
    A.push_back(1);
    int size = A.size();
    int limit = size + 1;
    vector<int> fibJumps(limit, -1);
    vector<int> fibNums; 
    generateFibNumbers(fibNums, size);
    
    fibJumps[0] = 0;
    for (int currPos = 0; currPos < limit; ++currPos)
    {
        int jumpsCnt = fibJumps[currPos];
        if (jumpsCnt == -1)
        {
            continue;
        }
        for( int fibJump : fibNums ) 
        {
            int nextPos = fibJump + currPos;
            if (nextPos < limit && A[nextPos-1] == 1)
            {
                if (fibJumps[nextPos] == -1 || (fibJumps[nextPos] > jumpsCnt + 1))
                {
                    fibJumps[nextPos] = jumpsCnt + 1;
                }
            }
        }
    }

    //printfArray(A);
    //printfArray(fibNums);
    //printfArray(fibJumps);
    return fibJumps.back();
}

