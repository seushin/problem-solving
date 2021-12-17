#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

typedef unsigned long long ull;

const string open = "({[<";
const string close = ")}]>";

ull getScore(stack<char> s)
{
	ull score = 0;

	while (!s.empty())
	{
		char c = s.top();

		s.pop();
		score *= 5;
		if (c == '(')
			score += 1;
		else if (c == '[')
			score += 2;
		else if (c == '{')
			score += 3;
		else if (c == '<')
			score += 4;
	}
	return (score);
}

int main()
{
	string input;
	vector<ull> res;
	while (1)
	{
		getline(cin, input);
		if (cin.eof())
			break;
		stack<char> s;
		bool isCorrupted = false;
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
					isCorrupted = true;
					break;
				}
			}
		}
		if (isCorrupted)
			continue;
		res.push_back(getScore(s));
	}
	sort(res.begin(), res.end());
	cout << endl << res[res.size() / 2] << endl;

	return (0);
}
