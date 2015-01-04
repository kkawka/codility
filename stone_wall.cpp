
#include <stack>
#include <vector>

using namespace std;

int solution(const vector<int> &H)
{
    stack<int> openedH;
	int result = 0;
	
	for (vector<int>::const_iterator it = H.begin(); it != H.end(); ++it)
	{
		if (openedH.empty() || openedH.top() < (*it))
		{
			openedH.push(*it);
		}
		else if (openedH.top() > (*it))
		{
			while (!openedH.empty() && openedH.top() > (*it))
			{
				++result;
				openedH.pop();
			}
			
			if (openedH.empty() || openedH.top() < (*it))
			{
				openedH.push(*it);
			}
		}
	}
	result += openedH.size();
	
	return result;
}
