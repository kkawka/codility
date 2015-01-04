
	// you can also use includes, for example:
	// #include <algorithm>
#include <vector>

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
	// write your code in C++98
	vector <int> a_num(S.size(), 0);
	vector <int> c_num(S.size(), 0);
	vector <int> g_num(S.size(), 0);
	vector <int> t_num(S.size(), 0);
	vector <int> res;

	int a_cnt = 0;
	int c_cnt = 0;
	int g_cnt = 0;
	int t_cnt = 0;

	for (int i = 0; i < S.size(); ++i)
	{
		switch (S.c_str()[i])
		{
		case 'A':
			++a_cnt;
			break;

		case 'C':
			++c_cnt;
			break;

		case 'G':
			++g_cnt;
			break;

		case 'T':
			++t_cnt;
			break;

		default:
			printf("error \n");
			break;
		};

		a_num[i] = a_cnt;
		c_num[i] = c_cnt;
		g_num[i] = g_cnt;
		t_num[i] = t_cnt;
	}

	for (int i = 0; i < P.size(); ++i)
	{
		if ( S.c_str()[P[i]] == 'A' || ((a_num[Q[i]] - a_num[P[i]]) > 0))
		{
			res.push_back(1);
		}
		else if (S.c_str()[P[i]] == 'C' || ((c_num[Q[i]] - c_num[P[i]]) > 0))
		{
			res.push_back(2);
		}
		else if (S.c_str()[P[i]] == 'G' || ((g_num[Q[i]] - g_num[P[i]]) > 0))
		{
			res.push_back(3);
		}
		else if (S.c_str()[P[i]] == 'T' || ((t_num[Q[i]] - t_num[P[i]]) > 0))
		{
			res.push_back(4);
		}

	}

	return res;
}