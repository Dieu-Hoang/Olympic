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


ull mod = 1e9 + 7;
ull MOD = mod;
unordered_map<ull, ull> m;
ull m1[1000];

vector<ull> arr;

ull find_gcd(ull A, ull B)
{
	if (B == 0)
		return A;
	else
		return find_gcd(B, A % B);
}

ull lcm(ull a, ull b) {
	return (a / find_gcd(a, b)) * b;  // Tránh tràn số
}

ull findLCM(ull n) {
	ull result = 1;
	for (ull i = 2; i <= n; i++) {
		result = lcm(result, i);
		if (result > 1e18) break;  // Tránh tràn số nếu quá lớn
	}
	return result;
}

ull calc_min(ull a)
{
	if (a % 2 == 1) {
		return 2;
	}

	if (a % 2 == 0 && a % 3 != 0)
	{
		return 3;
	}

	for (ull i = 4; i <= a + 1; i++)
	{
		if (a % i != 0)
		{
			return i % mod;
		}
	}
	return 0;
}

ull solve(ull a)
{
	ull ret = 0;
	ull oddCount = (a + 1) / 2;
	ret = (2 * oddCount) % mod;
	m1[2] = oddCount;
	for (ull i = 2; i <= a; i += 2)
	{
		ull b = calc_min(i);
		m1[b]++;
		ret = (b + ret) % mod;
	}
	
	/*for (auto a : m)
	{
		cout << a.first << " = " << a.second << '\n';
	}*/

	return ret % mod;

	/*
	
	*/


	/*for (int i = 4; i < 100; i++)
	{
		cout << i << " " << findLCM(i) << '\n';
	}*/


	//return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "r", stdin);
	// Đọc input
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(7);
	arr.push_back(8);
	arr.push_back(9);
	arr.push_back(13);
	arr.push_back(16);
	arr.push_back(17);
	arr.push_back(19);
	int tc;

	cin >> tc;

	while (tc--)
	{
		ull a;
		cin >> a;
		cout << solve(a) << '\n';
	}

	return 0;
}
