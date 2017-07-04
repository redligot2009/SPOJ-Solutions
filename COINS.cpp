#include <bits/stdc++.h>
using namespace std;
 
unordered_map<long long, long long> dp;
 
long long maxCoins(long long n)
{
	if(n == 0)
	{
		return 0;
	}
	if(dp[n])
	{
		return dp[n];
	}
	return dp[n] = max(n,maxCoins(n/2) + maxCoins(n/3) + maxCoins(n/4));
}
 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;
	while(cin >> n)
	{
		cout << maxCoins(n) << endl;
	}
	return 0;
} 