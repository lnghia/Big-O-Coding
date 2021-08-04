#include <bits/stdc++.h>

using namespace std;

bool isMatch(string &a, string &b){
    int i=0, count=0;

    if(a.length()!=b.length()){
        return false;
    }

    while( i<a.length()){
        a[i]=tolower(a[i]);
        b[i]=tolower(b[i]);

        count+=(a[i]!=b[i]);
        if(count>1){
            return false;
        }

        ++i;
    }

    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    string tmp;
    vector<string> messages;

    cin >> n >> m;

    for(int i=0; i<n; ++i){
        cin >> tmp;

        messages.push_back(tmp);
    }

    for(int i=0; i<m; ++i){
        cin >> tmp;
        string ans="CAN NOT FIX\n";
        for(int j=0; j<messages.size(); ++j){
            if(isMatch(tmp, messages[j])){
                ans="CAN FIX\n";

                break;
            }
        }

        cout << ans;
    }
    
}