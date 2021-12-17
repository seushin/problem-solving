#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string input;

	int count = 0;
	while (1)
	{
		getline(cin, input);
		if (cin.eof())
			break;

		vector<string> digit(14, "");

		for (int i = 0; i < 14; ++i)
		{
			int len = input.find(' ');
			string tmp = input.substr(0, len);
			if (tmp == "|")
			{
				input = input.substr(len + 1);
				len = input.find(' ');
				tmp = input.substr(0, len);
			}
			digit[i] = tmp;
			input = input.substr(len + 1);
		}
		for (int i = 0; i < 4; ++i)
		{
			int len = digit[i + 10].size();
			if (len == 1 || len == 3 || len == 4 || len == 8)
				count++;
		}
		cout << count << endl;
	}
	return (0);
}
