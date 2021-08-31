#include <bits/stdc++.h>

using namespace std;

struct Trie{
    Trie *next[26];
    bool val = 0;
};

bool isBad(string& t, char c){
    return t[c - 'a'] == '0';
}

int solve(string& s, string& t, int k){
    unordered_set<string> set;
    vector<int> prefixSum;
    int ans = 0;
    string key;

    prefixSum.push_back(0);
    int _i = 1;
    for(auto& c : s){
        prefixSum.push_back(prefixSum[_i++ - 1] + isBad(t, c));
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

int solve_using_trie(string& s, string& t, int k){
    Trie* root = new Trie();
    Trie* curr;
    int ans = 0;
    int badOnes = 0;

    for(int i = 0; i < s.length(); ++i){
        if(!root->next[s[i] - 'a']){
            root->next[s[i] - 'a'] = new Trie();
        }
        curr = root->next[s[i] - 'a'];
        badOnes = isBad(t, s[i]);
        for(int j = i; j < s.length(); ++j){
            if(i != j){
                badOnes += isBad(t, s[j]);

                if(!curr->next[s[j] - 'a']){
                    curr->next[s[j] - 'a'] = new Trie();
                }
                curr = curr->next[s[j] - 'a'];
            }
            
            ans += (!curr->val && badOnes <= k);
            curr->val = 1;
        }
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, t;
    int k;

    cin >> s >> t >> k;
    cout << solve_using_trie(s, t, k);

    return 0;
}