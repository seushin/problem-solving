#include <iostream>
#include <vector>
using namespace std;

vector<char> split(string str)
{
	vector<char> res;
	string::size_type pos = 0;

	for (auto &c : str)
		if (c == ',')
			c = ' ';
	while (!str.empty())
	{
		res.push_back(stol(str, &pos));
		str = str.substr(pos);
	}
	return (res);
}

int main()
{
	string input;

	getline(cin, input);

	vector<char> fish = split(input);
	int count = 0;
	for (int i = 0; i < 80; ++i)
	{
		for (auto &day : fish)
		{
			if (day == 0)
			{
				day = 6;
				count++;
			}
			else
				day--;
		}
		while (count)
		{
			fish.push_back(8);
			count--;
		}
	}
	cout << fish.size() << endl;
	return (0);
}
