// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // write your code in C++11
    int size = S.size(); 
    
    if (size % 2 == 0) // even number
    {
        return -1;
    }
    
    int index = size / 2;
    
    for (int i = 1; i + index < size; ++i)
    {
        if (S[index - i] != S[index + i])
        {
            return -1;
        }
    }
    return index;
}