#include <iostream>
#include <deque>
using namespace std;

int main()
{
	deque<int> sum;
	int input;
	int prev = 0, curr;
	int counter = 0;

	while (input)
	{
		cin >> input;
		sum.push_back(input);
		if (sum.size() > 3)
		{
			sum.pop_front();
			curr = 0;
			for (int a : sum)
				curr += a;
			if (prev != 0 && prev < curr)
				counter++;
			prev = curr;
		}
	}
	cout << counter << endl;
	return (0);
}
