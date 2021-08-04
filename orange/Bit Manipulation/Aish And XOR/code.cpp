#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    int l, r, tmp;
    vector<int> arr;
    vector<int> zero_count;
    vector<int> xor_0_i;

    cin >> n;
    zero_count.resize(n, 0);
    for(int i=0; i<n; ++i){
        cin >> tmp;
        arr.push_back(tmp);
        zero_count[i] += !tmp;
        if(i){
            zero_count[i] += zero_count[i-1];
        }
        if(!xor_0_i.size()){
            xor_0_i.push_back(tmp);
        }
        else{
            xor_0_i.push_back(xor_0_i[xor_0_i.size()-1] ^ tmp);
        }
    }

    cin >> q;
    while(q--){
        cin >> l >> r;
        cout << (xor_0_i[r-1] ^ xor_0_i[l-2]) << ' ' << zero_count[r-1] - zero_count[l-2] << '\n';
    }

    return 0;
}