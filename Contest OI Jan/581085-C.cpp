#pragma warning( disable : 4996 )

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <stdexcept>
#include <climits>

#define ll long long
#define ull unsigned long long int 
using namespace std;

bool isOk(vector<ull> a, vector<ull> b, ull hight)
{
	bool ret = true;
	int index_a = 0;
	int index_b = 0;
	//std::cout << "hight " << hight << '\n';
	vector<ull> c(a.size());
	while (index_a < a.size() && index_b < b.size())
	{
		//bool isBr = false;
		if (a[index_a] < hight)
		{

			/*if (index_b + 1 >= b.size())
			{
				break;
			}*/


			ull temp = 0;
			do
			{
				temp = a[index_a] + b[index_b];
				if (++index_b >= b.size())
				{
					break;
				}
			} while (temp < hight);
			if (temp >= hight)
			{
				c[index_a] = temp;
			}

			//index_b--;
		}
		else
		{
			c[index_a] = a[index_a];
		}
		/*if (isBr) {
			break;
		}*/
		++index_a;
	}
	//cout << "";
	for (int i = index_a; i < a.size(); i++)
	{
		c[i] = a[i];
	}
	for (int i = 0; i < c.size(); i++)
	{
		if (c[i] < hight)
		{
			return false;
		}
	}
	return true;
}

ull solve(vector<ull> a, vector<ull> b, ull min_a, ull max_a)
{
	ull ret = min_a;
	ull temp = min_a + (max_a - min_a) / 2;
	while (min_a <= max_a)
	{
		/*cout << "temp " << temp << '\n';
		cout << "min_a " << min_a << '\n';
		cout << "max_a " << max_a << '\n';*/
		bool ok = isOk(a, b, temp);

		if (ok)
		{
			ret = max(ret, temp);
			min_a = temp + 1;
		}
		else
		{
			max_a = temp - 1;
		}
		temp = min_a + (max_a - min_a) / 2;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  /*
  6
2 5 4 1 7 5
4
2 3 1 3

  */
	freopen("input.txt", "r", stdin);
	// Đọc input

	int n;

	cin >> n;
	vector<ull> a(n);

	ull min_a = 1e18;
	ull max_a = 0, max_b = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		min_a = min(min_a, a[i]);
		max_a = max(max_a, a[i]);
	}

	cin >> n;
	vector<ull> b(n);
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		max_b = max(max_b, b[i]);
	}


	cout << solve(a, b, min_a, max_a + max_b) << '\n';

	return 0;
}
