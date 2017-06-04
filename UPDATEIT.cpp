#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M, W;
	cin >> N >> M >> W;
	int A[W], T[W+1];
	int count = 0;
	for(int i = 0; i <= W; i ++)
	{
		T[i] = 0;
	}
	int low, high, val;
	for(int i = 0; i < N; i++)
  	{
   		cin >> low >> high;
   		T[low] ++;
   		T[high+1] --;
  	}
	for(int i = 0; i < W; i++)
  	{
   		count+=T[i];
   		A[i]=count;
  	}
  	int query;
  	for(int i = 0; i < M; i++)
	{
		cin >> query;
   		cout << A[query] << endl;
  	}
	return 0;
}