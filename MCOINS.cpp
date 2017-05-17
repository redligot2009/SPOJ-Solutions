#include <bits/stdc++.h>
using namespace std;

int winner[1000001] = {0};
int K, L, m;
int number;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> K >> L >> m;
	winner[0] = 0;
	for(int i = 1; i <= 1000000; i ++)
	{
		if(winner[i-1] == 0||winner[i - K] == 0 && i >= K||winner[i - L] == 0 && i >= L)
		{
			winner[i] = 1;
		}
	}
	while(m --)
	{
		cin >> number;
		if(winner[number] == 1)
		{
			cout << "A";
		}
		else
		{
			cout << "B";
		}
	}
	return 0;
}