#include <iostream>
#include <string>
using namespace std;

int main()
{
	string cmd;
	int val;
	int aim = 0;
	int horizon = 0;
	int depth = 0;

	while (1)
	{
		cin >> cmd >> val;
		if (cin.eof())
			break;
		if (cmd == "forward")
		{
			horizon += val;
			depth += val * aim;
		}
		else if (cmd == "down")
			aim += val;
		else if (cmd == "up")
			aim -= val;
	}
	cout << horizon * depth << endl;
	return (0);
}
