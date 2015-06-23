// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // write your code in C++11
    int openBrackets = 0; 
    for (auto it = S.begin(); it != S.end(); ++it)
    {
        if (*it == '(')
        {
            openBrackets++;
        }
        else
        {
            openBrackets--;
            if (openBrackets < 0)
            {
                return 0;
            }
        }
    }
    if (openBrackets == 0)
    {
        return 1;
    }
    return 0;
}
