#include <iostream>
#include <string>
#include <stack>
using namespace std;

typedef unsigned long long ull;

const string open = "({[<";
const string close = ")}]>";

int getScore(char c)
{
	int score = 0;

	if (c == ')')
		score = 3;
	else if (c == ']')
		score = 57;
	else if (c == '}')
		score = 1197;
	else if (c == '>')
		score = 25137;
	return (score);
}

int main()
{
	string input;
	ull res = 0;
	while (1)
	{
		getline(cin, input);
		if (cin.eof())
			break;
		stack<char> s;
		for (auto c : input)
		{
			if (open.find(c) != string::npos)
				s.push(c);
			else
			{
				int idx = open.find(s.top());

				s.pop();
				if (close[idx] != c)
				{
					res += getScore(c);
					break;
				}
			}
		}
	}
	cout << endl << res << endl;

	return (0);
}
