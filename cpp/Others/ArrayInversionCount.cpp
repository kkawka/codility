// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int LIMIT = 1000000000;

void printArray(const vector<int> &A)
{
    printf(" >>>>>>>>>>>>>>>>>>>> \n");
    for(int i : A)
    {
        printf(" %d", i);
    }
    printf("\n <<<<<<<<<<<<<<<<<<<< \n");
}

int solution(vector<int> &A) {
    // write your code in C++11
    int result = 0;
    vector<int> sortedA(A);
    sort(sortedA.begin(), sortedA.end());
    
    printArray(A);
    printArray(sortedA);
    
    for (int i = 0; i < A.size(); i++)
    {
        auto itrPos = std::find(sortedA.begin(), sortedA.end(), A[i]); 
        int pos = itrPos - sortedA.begin();
        //printf("A[%d] = %d, sortedA[%d] = %d \n", i, A[i], pos, sortedA[pos]);
        if (pos > i)
        {
            result  += pos - i;
            if (result > LIMIT)
            {
                return -1;
            }
        }
    }
    return result;
}