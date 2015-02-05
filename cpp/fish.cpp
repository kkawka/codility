
#include<stack>
#include<utility>

using namespace std;

typedef pair<int, int> pair_ii;

bool currEatLast(pair_ii currFish, pair_ii lastFish)
{
	if (lastFish.second > currFish.second &&
		lastFish.first < currFish.first)
	{
		return true;
	}
	return false;
}

bool canAddFish(stack<pair_ii> &fishes, pair_ii currFish)
{
	return (fishes.empty() ||
		fishes.top().second <= currFish.second);		
}

int solution(vector<int> &A, vector<int> &B)
{
	stack<pair_ii> fishes;
	pair_ii lastFish;
	pair_ii currFish;
	
	for (int i = 0; i < A.size(); ++i)
	{
		currFish = make_pair(A[i], B[i]);
		if (canAddFish(fishes, currFish))
		{
			fishes.push(currFish);
		}
		else
		{
			lastFish = fishes.top();
			while (currEatLast(currFish, lastFish))
			{
				fishes.pop();
				if (fishes.empty())
				{
					break;
				}
				else
				{
					lastFish = fishes.top();
				}
			}
			if (canAddFish(fishes, currFish))
			{
				fishes.push(currFish);
			}	
		}
	}
	return fishes.size();
}
                