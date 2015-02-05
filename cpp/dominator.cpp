
#include <vector>

using namespace std; 

int solution(const vector<int> &A)
{
	if (A.empty())
	{
		return -1;
	}
	
    int currDominator = A.front();
	int domCnt = 1;
	int domIndex = 0;
	
	for (int i = 1; i < A.size(); ++i)
	{
		if (domCnt == 0 || currDominator == A[i])
		{
			++domCnt;
			currDominator = A[i];
			domIndex = i;
		}
		else
		{
			--domCnt;
		}
	}
	
	domCnt = 0;
	for (int i = 0; i < A.size(); ++i)
	{
		if (currDominator == A[i])
		{
			++domCnt;
		}
	}
	
	if (domCnt >= A.size()/2 + 1)
	{
		return domIndex;
	}
	
	return -1;
}

