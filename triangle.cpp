#include <algorithm>
#include <vector>

int solution(const vector<int> &A) {
    // write your code in C++98
	vector<long long int> B(A.begin(), A.end());
	sort(B.begin(), B.end());
	
	long long int pq = 0;
	long long int r = 0;
	
	for(int i = 0; i + 2 < B.size(); ++i)
	{
		pq =  B[i];
		pq +=  B[i+1];
		r =  B[i+2];
		if (r < pq)
		{
			return 1;
		}
	}
	
	return 0;
}

