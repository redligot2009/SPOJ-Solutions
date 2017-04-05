#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin >> T;
	while(T--)
	{
	    int n;
	    int lowerLeftX = INT_MAX, lowerLeftY = INT_MAX, upperRightX = INT_MIN, upperRightY = INT_MIN;
	    cin >> n;
	    while(n--)
	    {
	        char c;
	        cin >> c;
	        int x1, x2, y1, y2, r;
	        if(c == 'c')
	        {
	            cin >> x1 >> y1 >> r;
	            lowerLeftX = min(x1-r, lowerLeftX);
	            lowerLeftY = min(y1-r, lowerLeftY);
	            upperRightX = max(x1+r, upperRightX);
	            upperRightY = max(y1+r, upperRightY);
	        }
	        else if(c == 'p')
	        {
	            cin >> x1 >> y1;
	            lowerLeftX = min(x1, lowerLeftX);
	            lowerLeftY = min(y1, lowerLeftY);
	            upperRightX = max(lowerLeftX, upperRightX);
	            upperRightY = max(lowerLeftY, upperRightY);
	        }
	        else if(c == 'l')
	        {
	            cin >> x1 >> y1 >> x2 >> y2;
	            if(x1 < x2)
	            {
	                lowerLeftX = min(x1, lowerLeftX);
	            }
	            else
	            {
	                lowerLeftX = min(x2, lowerLeftX);
	            }
	            if(y1 < y2)
	            {
	                lowerLeftY = min(y1, lowerLeftY);
	            }
	            else
	            {
	                lowerLeftY = min(y2, lowerLeftY);
	            }
	            if(x1 > x2)
	            {
	                upperRightX = max(x1, upperRightX);
	            }
	            else
	            {
	                upperRightX = max(x2, upperRightX);
	            }
	            if(y1 > y2)
	            {
	                upperRightY = max(y1, upperRightY);
	            }
	            else
	            {
	                upperRightY = max(y2, upperRightY);
	            }
	        }
	    }
	    cout << lowerLeftX << " " << lowerLeftY << " " << upperRightX << " " << upperRightY << endl;
	}
	return 0;
}
