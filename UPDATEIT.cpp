#include <bits/stdc++.h>
using namespace std;

//Solved using Segment Tree w/ Lazy Propagation

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
	
	void update(int I, int J, int v)
	{
		propagate();
		if(I > j || J < i)
		{
			return;
		}
		if(i >= I && j <= J)
		{
			val += (j-i+1) * v;
			if(i != j)
			{
				left->lazy += v;
				right->lazy += v;
			}
			return;
		}
		left->update(I,J, v);
		right->update(I,J, v);
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
	int T;
	cin >> T;
	while(T--)
	{
		int N, U;
		cin >> N >> U;
		root = construct(0,N-1);
		while(U--)
		{
			int i, j, v;
			cin >> i >> j >> v;
			root->update(i,j,v);
		}
		int Q;
		cin >> Q;
		while(Q--)
		{
			int i;
			cin >> i;
			cout << root->query(i,i) << endl;
		}
	}
	return 0;
}