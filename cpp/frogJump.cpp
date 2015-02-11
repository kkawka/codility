// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, int Y, int D) {
    // write your code in C++11
    int distance  = Y - X;
    int result = distance / D + ((distance % D) > 0 ? 1 : 0 ); 
    
    return result;
}

