#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M;

int compare(string a, string b)
{
	int a_size = a.size();
	int b_size = b.size();

	if (a_size != b_size)
		return (a_size < b_size);
	for (int i = 0; i < a_size || i < b_size; ++i)
	{
		if (a[i] != b[i])
			return (a[i] < b[i]);
	}
	return (0);
}

void print_list(vector<string> *v, int start)
{
	for (int i = start; i <= N; i += 2)
	{
		for (int j = 0; j < v[i].size(); ++j)
		{
			cout << i << ' ' << v[i][j] << '\n';
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	vector<string> v[N + 1];
	while(1)
	{
		int n;
		string name;

		cin >> n >> name;
		if (n == 0)
			break ;
		if (v[n].size() < M)
			v[n].push_back(name);
	}
	for (int i = 1; i <= N; ++i)
	{
		sort(v[i].begin(), v[i].end(), compare);
	}
	print_list(v, 1);
	print_list(v, 2);
	return (0);
}
