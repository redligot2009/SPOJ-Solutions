// CompetitiveProgramming.cpp : Defines the entry point for the console application.
//
#include <bits/stdc++.h>
using namespace std;

vector<long long int> sieve;

bool checkPrime(long long int n)
{
	vector<long long int>::iterator it = sieve.begin();
	long long int root = sqrt(n);
	while (it != sieve.end() && *it <= root)
	{
		if (n % *it == 0)
		{
			return false;
		}
		it++;
	}
	return true;
}

void generateSieve()
{
	sieve.push_back(2);
	sieve.push_back(3);
	for (long long int i = 4; i <= sqrt(1000000000); i++)
	{
		if(checkPrime(i))
		{
			sieve.push_back(i);
		}
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	std::ios_base::sync_with_stdio(false);
	int t;
	long long int m, n;
	cin >> t;
	generateSieve();
	while (t--)
	{
		cin >> m >> n;
		if (m > n)
		{
			swap(m, n);
		}
		for (long long int i = m; i <= n; i++)
		{
			if (checkPrime(i) && i > 1)
			{
				cout << i << endl;
			}
		}
		cout << endl;
	}
	//fclose(stdin);
	//fclose(stdout);
    return 0;
}

