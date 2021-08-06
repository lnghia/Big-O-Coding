#include <bits/stdc++.h>

using namespace std;

long double rs_min = 9.0e5;
vector<int> ans;
unordered_set<int> visited;

int compare(vector<int>& a, vector<int>& b, vector<int>& arr){
    long long a_common = (long long)arr[a[1]] * (long long)arr[a[3]];
    long long b_common = (long long)arr[b[1]] * (long long)arr[b[3]];

    long long tmp_aa = (long long)arr[a[0]] * (long long)arr[a[3]];
    long long tmp_ac = (long long)arr[a[2]] * (long long)arr[a[1]];

    long long tmp_ba = (long long)arr[b[0]] * (long long)arr[b[3]];
    long long tmp_bc = (long long)arr[b[2]] * (long long)arr[b[1]];

    long long tmp_a = (tmp_aa >= tmp_ac) ? 1 : -1;
    long long tmp_b = (tmp_ba >= tmp_bc) ? 1 : -1;

    long long common_mau = a_common * b_common;

    long long final_aa = (long long)arr[a[0]] * tmp_a * (common_mau / arr[a[1]]) - (long long)arr[a[2]] * tmp_a * (common_mau / arr[a[3]]);
    long long final_ba = (long long)arr[b[0]] * tmp_b * (common_mau / arr[b[1]]) - (long long)arr[b[2]] * tmp_b * (common_mau / arr[b[3]]);

    if(final_aa < final_ba){
        return -1;
    }
    else if(final_aa > final_ba){
        return 1;
    }

    return 0;
}

void backtrack(vector<int>& arr, vector<int>& subset, int ind){
    for(int i = 0; i < arr.size(); ++i){
        if(visited.find(i) != visited.end()) continue;

        subset.push_back(i);
        visited.insert(i);

        if(subset.size() == 4){
            
            if(compare(ans, subset, arr) == 1){
                ans = subset;
            }

            subset.pop_back();
            visited.erase(i);
            continue;
        }

        backtrack(arr, subset, i);
        subset.pop_back();
        visited.erase(i);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr(5, 0);
    vector<int> subset;

    cin >> arr[0];
    cin >> arr[1];
    cin >> arr[2];
    cin >> arr[3];
    cin >> arr[4];

    ans = {0, 1, 2, 3};
    
    backtrack(arr, subset, 0);

    for(auto& n : ans){
        cout << n << ' ';
    }

    return 0;
}