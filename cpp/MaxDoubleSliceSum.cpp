// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11
    int currSum = 0;
    int maxSum = 0;
    int size = A.size();
    vector<int> endingSum;
    vector<int> startingSum;

    endingSum.resize(size);
    startingSum.resize(size);

    for (int i = 1; i < size; ++i)
    {
    	currSum += A[i];
    	currSum = (currSum > 0) ? currSum : 0;
    	endingSum[i] = currSum;
    }
    currSum = 0;

    for (int i = size-2; i >= 0; --i)
    {
    	currSum += A[i];
    	currSum = (currSum > 0) ? currSum : 0;
    	startingSum[i] = currSum;
    }
    currSum = 0;

    for (int i = 0; i < size; ++i)
    {
    	printf(" %d %d \n", endingSum[i], startingSum[i]);
    }

    for (int i = 1; i < size - 1; ++i)
    {
    	currSum = endingSum[i-1] + startingSum[i+1];
    	if (currSum > maxSum)
    	{
    	  maxSum = currSum;
    	}
    }

    return maxSum;    
}

################################################################

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11
    vector<int> endingSum(A.size(), 0);
    vector<int> startingSum(A.size(), 0);
    
    int currSum = 0;
    for (int i = 1; i < (int)A.size(); ++i)
    {
        currSum += A[i];
        currSum = (currSum < 0) ? 0 : currSum;
        endingSum[i] = currSum;
    }
    
    currSum = 0;
    for (int i = A.size() - 2; i >= 0; --i)
    {
        currSum += A[i];
        currSum = (currSum < 0) ? 0 : currSum;
        startingSum[i] = currSum;
    }
    
    int result = 0;
    for (int i = 1; i < (int)A.size() - 1; ++i)
    {
        int tmpSum = endingSum[i-1] + startingSum[i+1];
        result = (result < tmpSum ? tmpSum : result);
    }
    
    return result;
}

