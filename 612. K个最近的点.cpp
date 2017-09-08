#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
struct Point
{
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};
*/

struct PointWithDistance
{
	Point point;
	int distance;
	PointWithDistance(Point a, int b) : point(a), distance(b) {}
};

bool operator <(const PointWithDistance &p1, const PointWithDistance &p2)
{
	return p1.distance > p2.distance;
}

class Solution
{
public:
	vector<Point> kClosest(vector<Point>& points, Point& origin, int k)
	{
		priority_queue<PointWithDistance> q;
		for (int i = 0; i < points.size(); ++i)
		{
			int distance = getDistance(points[i], origin);
			PointWithDistance real_point(points[i], distance);
			q.push(real_point);
		}
		vector<Point> result;
		for (int i = 0; i < k; ++i)
		{
			auto real_point = q.top();
			q.pop();
			result.push_back(real_point.point);
		}
		return result;
	}
private:
	int getDistance(Point point_a, Point point_b)
	{
		return (point_a.x - point_b.x) * (point_a.x - point_b.x) + (point_a.y - point_b.y) * (point_a.y - point_b.y);
	}
};
