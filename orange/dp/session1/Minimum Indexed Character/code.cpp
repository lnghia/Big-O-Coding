#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string patt;
    string str;
    string ans = "No character present";
    unordered_set<char> counting;

    cin >> t;
    while(t--){
        if(!counting.empty()) counting.clear();
        cin >> patt >> str;
        ans = "No character present";
        for(auto& c : str){
            counting.insert(c);
        }
        for(auto& c : patt){
            if(counting.find(c) != counting.end()){
                ans = c;
                break;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}