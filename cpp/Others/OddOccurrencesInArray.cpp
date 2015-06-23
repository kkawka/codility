// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11
    int result = 0;
    for (int i : A)
    {
        result ^= i;
    }
    return result;
}