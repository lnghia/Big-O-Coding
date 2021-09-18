#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
#define INF 1e9
 
struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};
 
bool xCompare(const Point &p1, const Point &p2) {
    return p1.x < p2.x;
}
 
bool yCompare(const Point &p1, const Point &p2) {
    return p1.y < p2.y;
}
 
double distance(Point &p1, Point &p2) {
    double x = p1.x - p2.x;
    double y = p1.y - p2.y;
    return sqrt(x * x + y * y);
}
 
double bruteForce(vector<Point> &point_set, int left, int right) {
    double min_dist = INF;
    for (int i = left; i < right; ++i) {
        for (int j = i + 1; j < right; ++j) {
            min_dist = min(min_dist, distance(point_set[i], point_set[j]));
        }
    }
    return min_dist;
}
 
double stripClosest(vector<Point> &point_set, int left, int right, int mid, double dist_min) {
    Point point_mid = point_set[mid];
    vector<Point> splitted_points;
    for (int i = left; i < right; i++) {
        if (abs(point_set[i].x - point_mid.x) <= dist_min) {
            splitted_points.push_back(point_set[i]);
        }
    }
 
    sort(splitted_points.begin(), splitted_points.end(), yCompare);
 
    double smallest = INF;
    int l = splitted_points.size();
    for (int i = 0; i < l; i++) {
        for (int j = i + 1; j < l && (splitted_points[j].y - splitted_points[i].y) < dist_min; j++) {
            double d = distance(splitted_points[i], splitted_points[j]);
            smallest = min(smallest, d);
        }
    }
    return smallest;
}
 
double closestUtil(vector<Point> &point_set, int left, int right) {
    if (right - left <= 3)
        return bruteForce(point_set, left, right);
 
    int mid = (right + left) / 2;
    double dist_left = closestUtil(point_set, left, mid);
    double dist_right = closestUtil(point_set, mid + 1, right);
    double dist_min = min(dist_left, dist_right);
 
    return min(dist_min, stripClosest(point_set, left, right, mid, dist_min));
}
 
int main() {
    int n;
    double x, y;
    while (true)
    {
        cin >> n;
        if (n == 0)
	break;
        vector<Point> point_set;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            point_set.push_back(Point(x, y));
        }
 
        sort(point_set.begin(), point_set.end(), xCompare);
        double ans = closestUtil(point_set, 0, n);
        if (ans < 10000)
            cout << fixed << setprecision(4) << ans << endl;
        else
            cout << "INFINITY" << endl;
    }
 
    return 0;
}