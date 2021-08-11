#include <bits/stdc++.h>

using namespace std;

bool canFill(vector<int>& arr, long long capacity, int m){
    long long container = 0;
    int containerNum = 0;

    for(int i  = 0; i < arr.size(); ++i){
        if(arr[i] > capacity) return 0;
        if(arr[i] + container > capacity) container = 0;
        containerNum += (!container);
        if(containerNum > m) return 0;

        container += arr[i];
    }

    return 1;
}

long long binSearch(vector<int>& arr, long long total, int m){
    long long low = 0;
    long long high = total;
    long long rs = 0;

    while(low <= high){
        long long mid = (low + high) / 2;

        if(canFill(arr, mid, m)){
            rs = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    
    return rs;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    while(cin >> n >> m){
        vector<int> arr;
        long long totalCapacity = 0;

        arr.resize(n);
        for(int i = 0; i < n ; ++i){
            cin >> arr[i];
            totalCapacity += arr[i];
        }

        cout << binSearch(arr, totalCapacity, m) << '\n';
    }

    return 0;
}