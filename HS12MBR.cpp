// CompetitiveProgramming.cpp : Defines the entry point for the console application.
//
#include <bits/stdc++.h>
using namespace std;

struct Point
{
	int x, y;
	Point(int x, int y);
};

Point::Point(int x = 0, int y = 0)
{
	this->x = x;
	this->y = y;
}

struct Rectangle
{
	Point bottomLeft;
	Point topRight;
	Rectangle(Point bottomLeft, Point topRight);
	void Update(int x, int y);
};

Rectangle::Rectangle(Point bottomLeft, Point topRight)
{
	this->bottomLeft = bottomLeft;
	this->topRight = topRight;
}

void Rectangle::Update(int x, int y)
{
	this->bottomLeft.x = min(x, this->bottomLeft.x);
	this->bottomLeft.y = min(y, this->bottomLeft.y);
	this->topRight.x = max(x, this->topRight.x);
	this->topRight.y = max(y, this->topRight.y);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	std::ios_base::sync_with_stdio(false);
	int t;
	char shape;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		Rectangle plane = Rectangle(Point(1000, 1000), Point(-1000, -1000));
		while (n--)
		{
			cin >> shape;
			if (shape == 'p')
			{
				int x, y;
				cin >> x >> y;
				plane.Update(x, y);
			}
			else if (shape == 'l')
			{
				int x1, x2;
				int y1, y2;
				cin >> x1 >> y1 >> x2 >> y2;
				plane.Update(x1, y1);
				plane.Update(x2, y2);
			}
			else
			{
				int x, y;
				cin >> x >> y;
				int r;
				cin >> r;
				plane.Update(x + r, y + r);
				plane.Update(x - r, y - r);
			}
		}
		cout << plane.bottomLeft.x << " " << plane.bottomLeft.y << " " << plane.topRight.x << " " << plane.topRight.y << endl;
	}
	//fclose(stdin);
	//fclose(stdout);
    return 0;
}

