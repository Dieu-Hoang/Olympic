#pragma warning(disable  : 4996)
#include <iostream>
#include <vector>

using namespace std;

/** input
5 5
2 1 6 3 8

*/
int sumVec(vector<int> b) 
{
	int ret = 0;
	for (int it : b)
	{
		ret += it;
	}
	return ret;
}

void show(vector<int> b)
{
	for (int it : b)
	{
		if (it == 0)
		{
			break;
		}
		cout << it << ' ';
	}
	cout << '\n';
}

void solve(int index, vector<int> a, int m, vector<int> b, int start) 
{
	int sum = sumVec(b);
	if (sum == m)
	{
		show(b);
		return;
	}
	if (sum > m)
	{
		/*cout << "sum = " << sum << '\n';
		show(b);*/
		return;
	}

	if (index >= a.size())
	{
		return;
	}
	
	for (int i = start; i < a.size(); i++)
	{
		b[index] = a[i];
		solve(index + 1, a, m, b, i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "r", stdin);
	int m, n;
	cin >> n >> m;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = 0;
	}
	solve(0, a, m, b, 0);

	return 0;
}
