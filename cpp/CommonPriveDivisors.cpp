// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int gcd (int a, int b)
{
    if (a < b)
    {
        return gcd (b, a);
    }
    
    if (a % b == 0)
    {
        return b;
    }
    return gcd(b, a % b);
}

bool haveTheSameDivisors(int a, int b)
{
    int commGcd = gcd(a, b);
    
    int aGcd = gcd(a, commGcd);
    int bGcd = gcd(b, commGcd);
    
    while (a != 1 && aGcd != 1)
    {
        a /= aGcd;
        aGcd = gcd(a, commGcd);
    }
    if (a != 1)
    {
        return false;
    }
    
    while (b != 1 && bGcd != 1)
    {
        b /= bGcd;
        bGcd = gcd(b, commGcd);
    }
    if (b != 1)
    {
        return false;
    }
    
    return true;
}

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++11
    unsigned int size = A.size();
    int result = 0;
    for(unsigned int i = 0; i < size; ++i)
    {
        if (haveTheSameDivisors(A[i], B[i]))
        {
            ++result;
        }
    }
    return result;
}
