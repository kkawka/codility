// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int gcd(int n, int m)
{
    if (n < m) 
    {
        return gcd(m,n);
    }
    if (n == m)
    {
        return n;
    }
    if (n % m == 0)
    {
        return m;
    }
    return gcd(m,n % m);
}


int solution(int N, int M) {
    // write your code in C++11
    int iGcd = gcd(N,M);
    return N/iGcd;
}

