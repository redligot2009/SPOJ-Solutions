#include <bits/stdc++.h>
using namespace std;
 
int grid[100+1][100+1] = {0};
 
int h, w;
//Original recursive solution
/*int solve(int row, int col, int sum = 0)
{
	if(col >= w || col < 0)
	{
		return 0;
	}
	sum += grid[row][col];
	if(row == h-1)
	{
		return sum;
	}
	return max(sum,
	max(solve(row+1,col,sum),
	max(solve(row+1,col+1,sum),
	solve(row+1,col-1,sum))));
}*/
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> h >> w;
		int sum = 0;
		for(int i = 0; i < h; i ++)
		{
			for(int j = 0; j < w; j ++)
			{
				cin >> grid[i][j];
			}
		}
		int dp[h+1][w+1] = {0};
		for(int i = 0; i < h; i ++)
		{
			for(int j = 0; j < w; j ++)
			{
				if(i==0)
				{
					dp[i][j] = grid[i][j];
				}
				else
				{
					if(j > 0 && j < w-1)
					{
						dp[i][j] = 
						max(dp[i-1][j+1] + grid[i][j],
						max(dp[i-1][j-1] + grid[i][j],
						dp[i-1][j] + grid[i][j]));
					}
					else if(j == 0)
					{
						dp[i][j] = max(
							dp[i-1][j] + grid[i][j],
							dp[i-1][j+1] + grid[i][j]);
					}
					else if(j == w-1)
					{
						dp[i][j] = max(
							dp[i-1][j-1] + grid[i][j],
							dp[i-1][j] + grid[i][j]);
					}
				}
			}
		}
		int maxval = 0;
		for(int i = 0; i < w; i ++)
		{
			maxval = max(maxval,dp[h-1][i]);
		}
		cout << maxval << endl;
	}
	return 0;
} 