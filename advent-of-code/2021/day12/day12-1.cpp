#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Cave
{
	string name;
	vector<string> adj;
	bool upper;
	bool visited;

	Cave(string name_, string next) : name(name_)
	{
		if (isupper(name_[0]))
			upper = true;
		adj.push_back(next);
	}
};

vector<Cave> v;

int main()
{
	return (0);
}
