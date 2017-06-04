#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int T;
	cin >> T;
	while(T--)
	{
		cin >> s;
		stack<int> st;
		stack<char> ops;
		string finals;
		for(int i = 0; i < s.size(); i ++)
		{
			if(s[i] == '(')
			{
				st.push(0);
			}
			else if(s[i] == ')')
			{
				while(st.top() > 0)
				{
					finals += ops.top();
					ops.pop();
					st.top() --;
				}
				st.pop();
			}
			else if(s[i] == '+' || s[i]=='*' || s[i] == '-' || s[i] == '/' || s[i] == '^')
			{
				st.top() ++;
				ops.push(s[i]);
			}
			else if(s[i] >= 'a' && s[i] <= 'z')
			{
				finals += s[i];
			}
		}
		cout << finals << endl;
	}
	return 0;
}