// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11
    std::vector<int> B(A.size(), 0);
    for (auto it = A.begin(); it != A.end(); ++it)
    {
        if (*it > (int)A.size())
            return 0;    
        B[*it - 1] += 1;
    }
    
    for (auto it = B.begin(); it != B.end(); ++it)
    {
        if (*it != 1)
            return 0;    
    }
    
    return 1;
}

