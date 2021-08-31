#include <bits/stdc++.h>

using namespace std;

int f(int n){
    int sum = 0;
    int tmp = n;

    while(n){
        sum += n % 10;
        n /= 10;
    }

    return tmp ^ sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    unordered_map<int, int> _map;
    int tmp;
    int maxVal = -1e9;
    int colls = 0;
    int mostOccurVal = 1e9;
    int occurs = -1e9;

    cin >> n;
    while(n--){
        cin >> tmp;
        int ind = f(tmp);
        cout << ind << '\n';
        if(_map.find(ind) != _map.end()){
            ++_map[ind];
            ++colls;
        }
        else{
            _map[ind] = 0;
            maxVal = max(maxVal, ind);
        }
    }

    for(auto& p : _map){
        if(p.second >= occurs){
            mostOccurVal = (p.second == occurs) ? min(mostOccurVal, p.first) : p.first;
            occurs = p.second;
        }
    }

    if(!colls){
        cout << maxVal << ' ' << colls;
    }
    else{
        cout << mostOccurVal << ' ' << colls;
    }

    return 0;
}