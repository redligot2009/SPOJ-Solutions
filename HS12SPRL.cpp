#include <bits/stdc++.h>
using namespace std;

int ulam[400][400] = {0};
int curr = 1;
char dir = 'r';

void ulamify(int x, int y, int size)
{
    if((ulam[x + 1][y] != 0||x==size) && (ulam[x - 1][y] != 0||x==1) && (ulam[x][y + 1]!= 0||y==size) && (ulam[x][y - 1] != 0||y == 1))
    {
        ulam[x][y] = curr;
        return;
    }
    if(dir == 'r')
    {
        if(ulam[x + 1][y] == 0 && x < size)
        {
            ulam[x][y] = curr;
            curr ++;
            x ++;
            ulamify(x,y,size);
        }
        else if(ulam[x+1][y] != 0||x == size)
        {
            ulam[x][y] = curr;
            curr ++;
            y ++;
            dir = 'd';
            ulamify(x,y,size);
        }
    }
    else if(dir == 'd')
    {
        if(ulam[x][y+1] == 0 && y < size)
        {
            ulam[x][y] = curr;
            curr ++;
            y ++;
            ulamify(x,y,size);
        }
        else if(ulam[x][y + 1] != 0 || y == size)
        {
            ulam[x][y] = curr;
            curr ++;
            x --;
            dir = 'l';
            ulamify(x,y,size);
        }
    }
    else if(dir == 'l')
    {
        if(ulam[x-1][y] == 0 && x > 1)
        {
            ulam[x][y] = curr;
            curr ++;
            x --;
            ulamify(x,y,size);
        }
        else if(ulam[x-1][y] != 0||x == 1)
        {
            ulam[x][y] = curr;
            curr ++;
            y --;
            dir = 'u';
            ulamify(x,y,size);
        }
    }
    else if(dir == 'u')
    {
        if(ulam[x][y-1] == 0 && y > 1)
        {
            ulam[x][y] = curr;
            curr ++;
            y --;
            ulamify(x,y,size);
        }
        else if(ulam[x][y-1] != 0||y == 1)
        {
            ulam[x][y] = curr;
            curr ++;
            x ++;
            dir = 'r';
            ulamify(x,y,size);
        }
    }
}

int main() {
	// your code goes here
	int T;
	cin >> T;
	while(T--)
	{
	    memset(&ulam,0,sizeof(ulam));
	    curr = 1;
	    dir = 'r';
	    int size;
	    cin >> size;
	    int x = 1, y = 1;
	    ulamify(x, y, size);
	    for(int i = 1; i <= size; i ++)
	    {
	        for(int j = 1; j <= size; j ++)
	        {
	            cout << setw(5);
	            cout << ulam[j][i] << " ";
	        }
	        cout << endl;
	    }
	    if(T > 0)
	    {
	        cout << endl;
	    }
	}
	return 0;
}
