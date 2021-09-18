#include <bits/stdc++.h>

using namespace std;

void pre(const string& P, vector<int>& prefix){
    prefix[0] = 0;
    int m = P.length();
    int i = 1;
    int j = 0;
    
    while(i < m){
        if(P[i] == P[j]){
            ++j;
            prefix[i] = j;
            ++i;
        }
        else{
            if(j){
                j = prefix[j - 1];
            }
            else{
                prefix[i] = 0;
                ++i;
            }
        }
    }
}

void search(const string& t, const string& p, const vector<int>& prefix, int& count){
    int n = t.length();
    int m = p.length();
    int i = 0, j = 0;

    while(i < n){
        if(t[i] == p[j]){
            ++j;
            ++i;
        }
        if(j == m){
            ++count;
            j = prefix[j - 1];
        }
        else if(i < n && t[i] != p[j]){
            if(j){
                j = prefix[j - 1];
            }
            else{
                i = i + 1;
            }
        }
    }
}

string generate(string& s, int l){
    string rs = "";
    int j = 0;

    for(int i = 0; i < l; ++i){
        rs += s[j];
        j = (j + 1) % s.length();
    }

    return rs;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int len;
    string s;

    while(cin >> len >> s){
        if(len == -1){
            break;
        }

        // string tmp = generate(s, len);
        vector<int> prefix(s.length(), 0);
        int count = 0;

        pre(s, prefix);

        if(len >= s.length()) count = (len - prefix.back()) / (s.length() - prefix.back());

        // search(tmp, s, prefix, count);

        cout << count << '\n';
    }

    return 0;
}