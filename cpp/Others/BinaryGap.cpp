// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++11
    int result = 0;
    int currGap = 0; 
    bool findOne = false;
    while (N > 0)
    {
        if ( N & 0x1 )
        {
            if ( result < currGap)
            {
                result = currGap;
            }
            findOne = true;
            currGap = 0;
        }
        else 
        {
            if (findOne)
            {
                currGap++;
            }
        }
        N >>= 1;
    }
    
    return result;
}