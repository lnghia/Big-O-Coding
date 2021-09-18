#include <iostream>
#include <vector>

using namespace std;

bool canFill(long long capacity, vector<int> &a, int m){
    long long container = 0;
    int numberOfContainer = 0;
    for (int i = 0; i < a.size(); i++){
        if (a[i] > capacity) return false;
        if (container + a[i] > capacity)
            container = 0;
        if (container == 0) numberOfContainer++;
        if (numberOfContainer > m) return false;

        container += a[i];
    }
    return true;
}

long long binarySearch(vector<int> &a, long long total, int m){
    long long low = 0;
    long long high = total;
    long long res = -1;

    while (low <= high){
        long long mid = (low + high) / 2;
        if (canFill(mid, a, m)){
            res = mid;
            high = mid - 1;
        } else low = mid + 1;
    }

    return res;
}

int main(){
    vector<int> c;
    int n, m;
    long long total;
    while (cin >> n >> m){
        c.resize(n);
        total = 0;
        for (int i = 0; i < n; i++){
            cin >> c[i];
            total += c[i];
        }
        cout << binarySearch(c, total, m) << endl;
    }
    return 0;
}