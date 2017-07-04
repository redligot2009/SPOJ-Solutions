#include <iostream>
using namespace std;

long long BIT[1000000+1] = { 0 };
long long A[1000000+1];
int N;

long long getSum(int idx)
{
	long long sum = 0;
	idx ++;
	while(idx > 0)
	{
		sum += BIT[idx];
		idx -= idx & (-idx);
	}
	return sum;
}

void update(int idx, int v)
{
	idx ++;
	while(idx <= N)
	{
		BIT[idx] += v;
		idx += idx & (-idx);
	}
}

int main() {
	// your code goes here
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		cin >> A[i];
	}
	for(int i = 1; i <= N; i ++)
	{
		BIT[i] = 0;
	}
	for(int i = 0; i < N; i ++)
	{
		update(i,A[i]);
	}
	int Q;
	cin >> Q;
	while(Q--)
	{
		char op;
		cin >> op;
		int u, v;
		cin >> u >> v;
		if(op=='q')
		{
			cout << getSum(v-1) - getSum(u-2) << endl;
		}
		else
		{
			update(u-1,v);
		}
	}
	return 0;
}