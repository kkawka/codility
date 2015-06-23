// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

typedef vector< vector<int> > matrix_t;

void printMatrix(const matrix_t& matrix)
{
    std::cout << " --------------------------------- " << std::endl;
    for (size_t i = 0; i < matrix.size(); ++i)
    {
        for(size_t j = 0; j < (matrix[i]).size(); ++j)
        {
            printf(" %3d ", matrix[i][j]);
        }
        std::cout << std::endl;
    }
    std::cout << " --------------------------------- " << std::endl;    
}

int findMinNail(int a, int b, int limit, const matrix_t& matrix)
{
    int diff = b - a;
    int maxPowOfTwo = 0;
    while (diff > 1)
    {
        diff >>= 1;
        maxPowOfTwo++;
    }
    int result = min(matrix[maxPowOfTwo][a], matrix[maxPowOfTwo][b - (1 << maxPowOfTwo) + 1]);
    if (result == limit)
    {
        return -1;
    }
    return result;
}

int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    // write your code in C++11
   
   int nailsNum = C.size(); 
   int planksNum = A.size(); 
   int limit = 2*nailsNum+2;
   vector<int> line(2*nailsNum+1, limit);
   matrix_t matrix(16, line);

    for (int i = 0; i < nailsNum; ++i)
    {
        if( matrix[0][C[i]] > i )
        {
            matrix[0][C[i]] = i;
        }
    }

    int expo = 1;
    for (int i = 1; i < 16; ++i)
    {
        for(int j = 0; j < limit - expo; ++j)
        {
            matrix[i][j] = std::min(matrix[i-1][j], matrix[i-1][j+expo]);
        }
        expo <<= 1;
    }

    int result = 0;
    for (int i = 0; i < planksNum; ++i)
    {
        int minNailNum = findMinNail(A[i], B[i], limit, matrix);
        if (minNailNum == -1)
        {
            return -1;
        }
        else if (minNailNum > result)
        {
            result = minNailNum;
        }
    }
    return result + 1;
}

