#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, tmp;
    vector<int> a, seller, buyer;
    int ans = 0;

    while(cin >> n){
        if(!n) break;

        ans = 0;
        a.resize(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            if(a[i] >= 0) buyer.push_back(i);
            else seller.push_back(i);
        }

        int buy = 0;
        for(auto& sell : seller){
            while(a[sell] < 0){
                if(!a[buyer[buy]] && buy < buyer.size()){
                    ++buy;
                    continue;
                }

                int tmp = a[sell];
                int tmp2 = a[buyer[buy]];

                ans += abs(sell - buyer[buy]) * min(tmp2, -tmp);
                a[buyer[buy]] += ((-tmp > tmp2) ? -tmp2 : tmp);
                a[sell] = (tmp2 < -tmp) ? (tmp + tmp2) : 0;
                if(!a[buyer[buy]]) ++buy;
            }
        }
        a.clear();
        buyer.clear();

        cout << ans << '\n';
    }

    return 0;
}