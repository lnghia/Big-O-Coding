#include <bits/stdc++.h>

using namespace std;

bool isBad(string& t, char c){
    return t[c - 'a'] == '0';
}

int solve(string& s, string& t, int k){
    unordered_set<string> set;
    vector<int> prefixSum;
    int ans = 0;
    string key;

    prefixSum.push_back(0);
    int i = 1;
    for(auto& c : s){
        prefixSum.push_back(prefixSum[i++ - 1] + isBad(t, c));
    }

    for(int i = 1; i <= s.length(); ++i){
        key = s[i - 1];
        for(int j = i; j <= s.length(); ++j){
            if(i != j){
                key += s[j - 1];
            }
            if(prefixSum[j] - prefixSum[i - 1] <= k && set.find(key) == set.end()){
                ++ans;
                set.insert(key);
            }
        }
    }

    return ans;
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    char c;
    int r;

    srand (time(NULL));    // initialize the random number generator
    for (int i=0; i<1500; i++)
    {    r = rand() % 26;   // generate a random number
          c = 'a' + r;            // Convert to a character from a-z
          cout << c;
    }

    return 0;
}