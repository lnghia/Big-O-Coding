#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    int sum = 0;
    int tmp;
    vector<int> a;
    int start_positive = -1;

    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        if(tmp > 0 && start_positive < 0) start_positive = i;
        a.push_back(tmp);
        sum += tmp;
    }

    int i = 0;
    while(i < a.size() && a[i] < 0 && k){
        sum -= a[i];
        a[i] *= -1;
        sum += a[i];
        --k;
        ++i;
    }
    
    sort(a.begin(), a.end());

    if(k){
        sum -= a[0];
        sum += a[0] * ((k % 2 == 0) ? 1 : -1);
    }

    cout << sum;

    return 0;
}