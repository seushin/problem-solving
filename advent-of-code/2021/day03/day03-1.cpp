#include <bitset>
#include <iostream>
#include <string>
using namespace std;

#define LEN 12

int main()
{
	string input;
	int bitsum[12] = { 0 };
	int size = 0;

	while (1)
	{
		cin >> input;
		if (cin.eof())
			break;
		for (int i = 0; i < input.size(); ++i)
		{
			int bit = input[i] - '0';

			bitsum[i] += bit;
		}
		size++;
	}
	bitset<LEN> res;
	for (int i = 0; i < LEN; ++i)
	{
		if (size / 2 < bitsum[i])
			res[LEN - i - 1] = 1;
	}
	cout << res.to_ullong() * res.flip().to_ullong() << endl;
	return (0);
}
