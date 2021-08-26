#include <bits/stdc++.h>

using namespace std;

void Eurathos(vector<int>& primes, int n){
    vector<bool> mark;

    mark.resize(n + 1, 1);
    mark[0] = mark[1] = 0;

    for(int i = 2; i*i <= n; ++i){
        if(mark[i]){
            for(int j = i * i; j <= n; j += i){
                mark[j] = 0;
            }
        }
    }
    primes.push_back(1);
    for(int i = 2; i <= n; ++i){
        if(mark[i]){
            primes.push_back(i);
        }
    }
  	primes.push_back(n);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, c;
    vector<int> primes;
    int f, s, l, len, tmp;

    Eurathos(primes, 1000);

    while(cin >> n >> c){
        vector<int>::iterator it = lower_bound(primes.begin(), primes.end(), n);

        if(*it > n){
            --it;
        }
        f = 0;
        s = it - primes.begin();
        l = s + 1;
        len = (l % 2 == 0) ? 2 * c : 2 * c - 1;
        tmp = (l - len) / 2;

        if(len > l){
            cout << n << ' ' << c << ':';
            for(int i = 0; i <= (it - primes.begin()); ++i){
                cout << ' ' << primes[i];
            }
            cout << '\n' << '\n';
            continue;
        }

        f += tmp;
        s -= tmp;
        cout << n << ' ' << c << ':';
        while(f <= s){
            cout << ' ' << primes[f++];
        }
        cout << '\n' << '\n';
    }

    return 0;
}