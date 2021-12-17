#include <iostream>
#include <string>
using namespace std;

int main()
{
	string cmd;
	int val;
	int horizon = 0;
	int depth = 0;

	while (!cin.eof())
	{
		cin >> cmd >> val;
		if (cmd == "forward")
			horizon += val;
		else if (cmd == "down")
			depth += val;
		else if (cmd == "up")
			depth -= val;
	}
	cout << horizon * depth << endl;
	return (0);
}
