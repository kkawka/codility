#include <algorithm>
#include <vector>
#include <stdint.h>

typedef long long int llint;

int solution(const vector<int> &A) {
    // write your code in C++98
	
	vector<llint> open_seg(A.size(), 0);
	vector<llint> close_seg(A.size(), 0);
	
	llint open = 0;
	llint close = 0;
	llint size = A.size();
	
	llint open_cnt = 0;
	llint res = 0;
	
	for (int i = 0; i < size; ++i)
	{
		open = (i - A[i] > 0) ? i - A[i] : 0;
		close = (i + A[i] > size) ? size : i + A[i];
		open_seg[open] += 1;
		close_seg[close] += 1;
	}
	
	for (int i = 0; i < size; ++i)
	{
		open_cnt += open_seg[i];
		while (close_seg[i] > 0)
		{
			res += --open_cnt;
			close_seg[i] -= 1;
		}
	}
	
	if (res > 10000000)
	{
		return -1;
	}
	
	return res;
	
}

