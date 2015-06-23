#include <algorithm>
#include <vector>

int solution(vector<int> &A) {

	sort(A.begin(),A.end());
	
	long long int max_neg_prod = 0;
	long long int res = -1000000000;
	long long int prod = 0;
	
	for (int i = 0; i + 2 < A.size(); ++i)
	{
		prod = A[i] * A[i+1];
		
		if (A[i] < 0 && A[i+1] < 0)
		{
			if (prod > max_neg_prod)
			{
				max_neg_prod = prod;
			}
		}
		
		prod *= A[i+2];
		if (prod > res)
		{
			res = prod;
		}
	}
	
	if (max_neg_prod * A.back() > res)
	{
		return max_neg_prod * A.back();
	}
	
	return res;
}
