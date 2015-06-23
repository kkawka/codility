#include <vector>
#include <string>
#include <set>
#include <algorithm>
 
typedef vector<int> v_i;
typedef v_i::iterator it_v_i;
 
typedef pair<int, int> pair_ii;
typedef vector< pair_ii > v_pair_ii;
typedef v_pair_ii::iterator it_v_pair_ii;
 
vector<int> solution(int N, vector<int> &A) {
// write your code in C++98
 
	v_pair_ii counters(N+1, make_pair(0,0));
	int curr_max = 0;
	pair_ii last_max_cnt = make_pair(0,0);
	v_i res;

	for (int i = 0; i < A.size(); ++i)
	{
		if (A[i] <= N)
		{
			//update curr value
			if (counters[A[i]].second < last_max_cnt.second)
			{
				counters[A[i]] = last_max_cnt;	
			}
 
			counters[A[i]].first += 1;
			counters[A[i]].second = i;
			if (counters[A[i]].first > curr_max)
			{
				curr_max = counters[A[i]].first;
			}
		}
		else // increase all counters
		{
			last_max_cnt.first = curr_max;
			last_max_cnt.second = i;
		}
	}
	
	for (int i = 1; i < counters.size(); ++i)
	{
		if (counters[i].second < last_max_cnt.second)
		{
			res.push_back(last_max_cnt.first);
		}
		else
		{
			res.push_back(counters[i].first);
		}
	}
	
	return res;
}







############################


// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A) {
    // write your code in C++11
    vector <int> result (N, 0); 
    int maxValue = 0;
    int maxCommonValue = 0;
    
    for (unsigned int i = 0; i < A.size(); ++i)
    {
        if (A[i] == N+1)
        {
            maxCommonValue = maxValue;
        }
        else
        {
            result[A[i]-1] = result[A[i]-1] < maxCommonValue ? maxCommonValue + 1 : result[A[i]-1] + 1;
            maxValue = maxValue < result[A[i]-1] ? result[A[i]-1] : maxValue;
        }
    }
    
    for (auto it = result.begin(); it != result.end(); ++it)
    {
        if (*it < maxCommonValue)
        {
            *it = maxCommonValue;
        }
    }
    
    return result;    
}

