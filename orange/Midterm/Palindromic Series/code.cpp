#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(vector<int>& number){
    int l = 0, r = number.size() - 1;

    while(l <= r){
        if(number[r] != number[l]) return 0;
        ++l;
        --r;
    }

    return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, sum = 0, temp = 0;
    int temp2 = 0;
    vector<int> digits;
    vector<int> number;
    string tmp = "";

    cin >> t;
    while(t--){
        temp = temp2 = 0;
        if(digits.size()){
            digits.clear();
            number.clear();
        } 
        sum = 0;
        cin >> n;
        while(n){
            sum += n % 10;
            digits.push_back(n % 10);
            n /= 10;
        }

        int j = digits.size() - 1;
        int k = 0;
        for(int i = 0; i < sum; ++i){
            number.push_back(digits[j--]);
            if(j < 0) j = digits.size() - 1;
        }

        if(isPalindrome(number)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}