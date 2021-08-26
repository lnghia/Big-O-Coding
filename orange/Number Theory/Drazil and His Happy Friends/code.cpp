#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int b, tmp;
    vector<int> bs, gs;
    bool ans = 1;

    cin >> n >> m;
    bs.resize(n, 0);
    gs.resize(m, 0);
    cin >> b;
    for(int i = 0; i < b; ++i){
        cin >> tmp;
        bs[tmp] = 1;
    }
    cin >> b;
    for(int i = 0; i < b; ++i){
        cin >> tmp;
        gs[tmp] = 1;
    }

    for(int i = 0; i < n * m; ++i){
        bs[i % n] = gs[i % m] = (bs[i % n] | gs[i % m]);
    }

    for(auto& n : bs){
        if(!n){
            cout << "No";
            return 0;
        } 
    }

    for(auto& n : gs){
        if(!n){
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";

    return 0;
}