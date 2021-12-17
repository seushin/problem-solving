#include <iostream>
using namespace std;

int main()
{
	int counter = 0;
	int prev, curr;
	cin >> prev;
	while (curr)
	{
		cin >> curr;
		if (prev < curr)
			counter++;
		prev = curr;
	}
	cout << counter << endl;
	return (0);
}
