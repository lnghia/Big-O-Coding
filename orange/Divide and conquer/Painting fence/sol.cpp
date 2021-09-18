#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
 
int n;
vector<int> a;
 
int strokesNeeded(int left, int right, int paintedHeight) {
    if (left > right)
        return 0;
 
    // find the index of the elements with the smallest value
    int mini = left;
    for (int i = left; i <= right; ++i) {
        if (a[i] < a[mini])
            mini = i;
    }
 
    // if we tried all vertical strokes
    int allVertical = right - left + 1;
 
    // if we tried horizontal strokes first then recursion
    int recursive = a[mini] - paintedHeight + strokesNeeded(left, mini - 1, a[mini]) + strokesNeeded(mini + 1, right, a[mini]);
 
    return min(allVertical, recursive);
}
 
int main() {
    scanf("%d", &n);
    int tmp;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tmp);
        a.push_back(tmp);
    }
    printf("%d", strokesNeeded(0, n - 1, 0));
    return 0;
}