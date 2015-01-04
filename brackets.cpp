
#include <stack>

using namespace std;

int solution(const string &S)
{
	stack<char> my_stack;
	char curr_char;
	
	for (int i = 0; i < S.size(); ++i)
	{
		curr_char = S.c_str()[i];
		switch (curr_char)
		{
			case '{':
			case '(':
			case '[':
				my_stack.push(curr_char);
				break;
			case '}':
				if (my_stack.empty() || my_stack.top() != '{')
				{
					return 0;
				}
				else
				{
					my_stack.pop();
					break;
				}
			case ')':
				if (my_stack.empty() || my_stack.top() != '(')
				{
					return 0;
				}
				else
				{
					my_stack.pop();
					break;
				}
			case ']':
				if (my_stack.empty() || my_stack.top() != '[')
				{
					return 0;
				}
				else
				{
					my_stack.pop();
					break;
				}							
			default:
				return 0;
		};
	};
	
	if (my_stack.empty())
	{
		return 1;
	}
	
	return 0;
}

