#include <bits/stdc++.h>

using namespace std;

int solve(int n, int k){
    vector<int> temp;
    int tmp;

    while(n--){
        cin >> tmp;

        temp.push_back(tmp);
    }

    //sort(temp.begin(), temp.end());

    int front=0, rear=front+1, count=0, ans=1, _max=temp[0], _min=temp[0];

    while(front <= temp.size()-1 && rear <= temp.size()-1){
        while(abs(_max-_min)<=k){
            _max=max(temp[rear], _max);
            _min=min(temp[rear], _min);

            cout << temp[rear] << '\n';

            ++count;
            ++rear;
        }
        cout << "-----------\n";
        ++front;
        ans=(ans<count)?count:ans;
        count=0;
        _max=_min=temp[front];
    }

    return ans;
}

int main(){
    int t, n , k, tmp, i=1;

    cin >> t;
    while(t--){
        cin >> n >> k;

        int ans=solve(n, k);

        string rs=(ans>1)?"days\n":"day\n"; 
        cout << "Case #" << i++ << ": " << ans << ' ' << rs;
    }

    return 0;
}