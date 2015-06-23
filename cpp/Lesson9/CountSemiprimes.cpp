// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
    // write your code in C++11
    vector<int> divisors(N,0);
    for (int i=2; i <= N; ++i)
    {
        for(int j = 2 * i; j <= N; j+=i)
        {
            int num = j;
            while (num > 0 && num % i ==0)
            {
                num /= i;
                divisors[j-1] += 1;
            }
        }
    }
    
    vector<int> querryArray;
    querryArray.reserve(N+1);
    int semiPrimesCnt = 0;
    for(auto it = divisors.begin(); it != divisors.end(); ++it)
    {
        if (*it == 2)
        {
            semiPrimesCnt++;
        }
        querryArray.push_back(semiPrimesCnt);
    }
    
    int M = P.size();
    vector<int> result;
    
    for(int i = 0; i < M; ++i)
    {
        int si = Q[i]-1;
        int ei = P[i]-2 > 0 ? P[i]-2 : 0;
        result.push_back(querryArray[si] - querryArray[ei]);
    }
    return result;
}

