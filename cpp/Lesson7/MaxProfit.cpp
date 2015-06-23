// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11
    int result = 0;
    
    if (A.size() > 0)
    {
        int currMin = A.front(); 
        for (auto it = A.begin(); it != A.end(); ++it)
        {
            if (*it < currMin)
            {
                currMin = *it;
            }
            else
            {
                int tmpVal = *it - currMin;
                result = result < tmpVal ? tmpVal : result; 
            }
        }
    }
    return result;
}

