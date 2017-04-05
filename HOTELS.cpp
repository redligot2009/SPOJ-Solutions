#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int N;
	long long M;
	std::ios::sync_with_stdio(false);
	cin >> N >> M;
	int arr[300000];
	for(int i = 0; i < N; i ++)
	{
	    cin >> arr[i];
	}
	long long currSum = 0;
	long long maxSum = 0;
	int currIndex = 0;
	for(long i = 0; i < N; i ++)
	{
	    if(maxSum < currSum && currSum < M)
	    {
    	    maxSum = currSum;
	    }
    	currSum += arr[i];
    	if(currSum == M)
    	{
    	    maxSum = currSum;
    	    break;
    	}
    	else
    	{
    	    while(currSum > M)
    	    {
    	        currSum -= arr[currIndex];
    	        if(currSum == M)
    	        {
    	            maxSum = currSum;
    	            break;
    	        }
    	        currIndex ++;
    	    }
    	}
	}
	cout << maxSum << endl;
	return 0;
}
