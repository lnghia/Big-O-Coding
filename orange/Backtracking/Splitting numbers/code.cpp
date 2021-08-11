#include <bits/stdc++.h>

using namespace std;

int reverse_bit(int n){
    int s = 8;
    int rev = 0;
    int i = 0;

    while(n){
        rev >>= 1;
        rev ^= (n & 1);
        n >>= 1;
        --s;
    }
    // if(s > 0){
    //     rev <<= s;
    // }

    cout << bitset<8>(rev) << '\n';

    return rev;
}

int main(){
    int t, n;
    int a = 0, b = 0;
    int i = 0;
    int len = 0;

    while(cin >> n){
        i = 1;
        a = b = 0;
        if(!n){
            break;
        }

        do{
            a <<= 1;
            b <<= 1;

            if(n & 1){
                if(i % 2 == 0){
                    b ^= 1;
                }
                else{
                    a ^= 1;
                }
                ++i;
            }
            n >>= 1;
            ++len;
        }
        while(n);
        // a <<= 1;
        // b <<= 1;

        cout << bitset<8>(a) << ' ' << len << '\n';
        cout << bitset<8>(b) << ' ' << len << '\n';

        cout << a << ' ' << b << '\n';
    }

    return 0;
}