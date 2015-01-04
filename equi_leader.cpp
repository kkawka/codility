
#include <vector>

using namespace std; 

int solution(vector<int> &A)
{
	int currDom = A.front();
	int domCnt = 0;
	int domCntTotal = 0;
	int result = 0;
	
	for (int i = 1; i < A.size(); ++i)
	{
		if (domCnt == 0 || currDom == A[i])
		{
			++domCnt;
			currDom = A[i];
		}
		else
		{
			--domCnt;
		}
	}
	
	for (int i = 0; i < A.size(); ++i)
	{
		if (currDom == A[i])
		{
			++domCntTotal;
		}
	}
	
	domCnt = 0;
	
	for (int i = 0; i < A.size(); ++i)
	{
		if (currDom == A[i])
		{
			++domCnt;
		}
		
		int left = A.size() - (i + 1);
		if ((domCnt > (i+1)/2)
		&& (domCntTotal - domCnt) >= ((left / 2) + 1))
		{
			++result;
		}
	}
	
	return result;
}
