#pragma warning(disable  : 4996)
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string arr[4] = { "orange" , "apple", "lee", "mango"};
int cnt = 0;

void show(vector<string> a)
{
	++cnt;
	cout << cnt << ' ';
	for (string i : a)
	{
		
		cout << ' ' << i << ' ';
	}
	cout << '\n';
}

void solve(int index, int start, vector<string> a) 
{
	if (index >= 3)
	{
		show(a);
		return;
	}

	for (int i = start; i <= 3; i++)
	{
		a[index] = arr[i];
		solve(index + 1, i, a);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	vector<string> a(3);
	solve(0, 0, a);

	cout << "count = " << cnt;

	return 0;
}
