#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    int n, h;
    string bits="";

    cin >> t;
    while(t--){
        bits = "";

        cin >> n >> h;

        for(int i = 0; i < (n - h); ++i){
            bits += '0';
        }
        for(int i = 0; i < h; ++i){
            bits += '1';
        }

        do {
            cout << bits << '\n';
        } while (next_permutation(bits.begin(), bits.end()));
        cout << '\n';
    }

    return 0;
}