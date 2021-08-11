#include <bits/stdc++.h>

using namespace std;

struct Point{
    long long x, y;
    Point(long long x = 0, long long y = 0) : x(x), y(y) {}
};

bool xCompare(const Point &p1, const Point &p2){
    return p1.x < p2.x;
}

bool yCompare(const Point &p1, const Point &p2){
    return p1.y < p2.y;
}

long long distance(Point &p1, Point &p2){
    long long x = p1.x - p2.x;
    long long y = p1.y - p2.y;

    return x * x + y * y;
}

long long bruteForce(vector<Point> &point_set, int left, int right){
    long long min_dist = 1e10;

    for(int i = left; i < right; ++i){
        for(int j = i + 1; j < right; ++j){
            min_dist = min(min_dist, distance(point_set[i], point_set[j]));
        }
    }

    return min_dist;
}

long long stripClosest(vector<Point> &point_set, int left, int right, int mid, long long dist_min){
    Point point_mid = point_set[mid];
    vector<Point> splitted_points;

    for(int i = left; i < right; ++i)
        if(pow(abs(point_set[i].x - point_mid.x), 2) <= dist_min){
            splitted_points.push_back(point_set[i]);
        }

    sort(splitted_points.begin(), splitted_points.end(), yCompare);

    long long smallest = 1e10;
    int l = splitted_points.size();

    for(int i = 0; i < l; ++i){
        for(int j = i + 1; j < l && pow((splitted_points[j].y - splitted_points[i].y), 2) < dist_min; ++j){
            long long d = distance(splitted_points[i], splitted_points[j]);
            smallest = min(smallest, d);
        }
    }

    return smallest;
}

long long minimalDistance(vector<Point> &point_set, int left, int right){
    if(left >= right) return 1e9;

    if(right - left <= 3)
        return bruteForce(point_set, left, right);

    int mid = (right + left) / 2;

    long long dist_left = minimalDistance(point_set, left, mid);
    long long dist_right = minimalDistance(point_set, mid + 1, right);
    long long dist_min = min(dist_left, dist_right);

    return min(dist_min, stripClosest(point_set, left, right, mid, dist_min));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr;
    vector<int> sum;
    vector<Point> point_set;
    int n;

    cin >> n;
    arr.resize(n);
    sum.resize(n, 0);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        sum[i] = ((i > 0) ? sum[i - 1] : 0) + arr[i];
        point_set.push_back(Point(i + 1, sum[i]));
    }

    sort(point_set.begin(), point_set.end(), xCompare);

    cout << minimalDistance(point_set, 0, n);

    return 0;
}