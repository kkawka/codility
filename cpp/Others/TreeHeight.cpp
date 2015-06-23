// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(tree * T) {
    // write your code in C++11
    if (T == NULL) 
    {
        return -1;
    }
    else 
    {
        int sizeLeft = solution(T->l);
        int sizeRight = solution(T->r);
        return (sizeLeft < sizeRight) ? sizeRight + 1 : sizeLeft + 1;
    }
}
