// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
bool canTakeFlags(const vector<int> &peaks, int N)
{
    int cnt = 1;
    int lastPeak = peaks.front();
    for (auto it = peaks.begin()+1; it != peaks.end(); ++it)
    {
        //printf(" %d %d %d %d \n",(*it),lastPeak,cnt,N);
        if (((*it) - lastPeak) > N)
        {
            if (++cnt >= N)
            {
                return true;
            }
        }
    }
    return false;
}

int solution(vector<int> &A) {
    // write your code in C++11
    int size = A.size();
    vector<int> peaks; 
    for (int i = 1; i < size - 1; ++i)
    {
        if (A[i-1] < A[i] && A[i+1] < A[i])
        {
            //printf(" %d %d %d %d \n",A[i-1],A[i],A[i+1],i);
            peaks.push_back(i);
        }
    }
    int peaksSize = peaks.size();
    int best = 0;
    for (int i = 1; i < peaksSize; i++)
    {
        if(canTakeFlags(peaks, i))
        {
            best = i;
        }
        else
        {
            break;
        }
    }
    return best;
}   
