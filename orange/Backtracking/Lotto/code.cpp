#include <bits/stdc++.h>

using namespace std;

void Generator(vector<int>& arr, int start, int len, vector<int>& rs){
    if(rs.size() == len){
        for(int i = 0; i < rs.size()-1; ++i)
            cout << rs[i] << ' ';
        cout << rs[rs.size()-1] << '\n';

        return;
    }

    for(int i = start; i < arr.size(); ++i){
        rs.push_back(arr[i]);
        Generator(arr, i+1, len, rs);
        rs.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> set;
    int k, tmp;

    while(cin >> k){
        if(k){
            vector<int> rs;
            for(int i = 0; i < k; ++i){
                cin >> tmp;
                set.push_back(tmp);
            }
            Generator(set, 0, 6, rs);
        }
        else{
            break;
        }
        cout << '\n';
    }

    return 0;
}