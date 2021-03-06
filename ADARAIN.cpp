#include <bits/stdc++.h>
using namespace std;

//Seg Tree Implementation w/ Lazy Propagation

int N, M;
long W;

struct tree
{
	int i, j;
	int val;
	int lazy = 0;
	tree* left;
	tree* right;
	tree(int i, int j, int val):i(i),j(j),val(val){
		left = right = NULL;
	}
	
	void propagate()
	{
		if(lazy != 0)
		{
			val += (j-i+1)*lazy;
			if(i != j)
			{
				left->lazy += lazy;
				right->lazy += lazy;
			}
			lazy = 0;
		}
	}
	
	int query(int I, int J)
	{
		propagate();
		if(i > J || j < I)
		{
			return 0;
		}
		if(i >= I && j <= J)
		{
			return val;
		}
		return left->query(I,J) + right->query(I,J);
	}
	
	void update(int I, int J)
	{
		propagate();
		if(I > j || J < i)
		{
			return;
		}
		if(i >= I && j <= J)
		{
			val += (j-i+1);
			if(i != j)
			{
				left->lazy ++;
				right->lazy ++;
			}
			return;
		}
		left->update(I,J);
		right->update(I,J);
		val = left->val + right->val;
	}
};

tree* construct(int I, int J)
{
	if(I == J)
	{
		return new tree(I,J,0);
	}
	if(I != J)
	{
		int mid = (I+J)/2;
		tree* left = construct(I, mid);
		tree* right = construct(mid+1,J);
		tree* ret = new tree(I,J,0);
		ret->left = left;
		ret->right = right;
		return ret;
	}
}

tree* root;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> W;
	root = construct(0,W-1);
	while(N--)
	{
		int i, j;
		cin >> i >> j;
		root->update(i,j);
	}
	while(M--)
	{
		int i;
		cin >> i;
		cout << root->query(i,i) << endl;
	}
	return 0;
}