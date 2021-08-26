#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

#define ff first

#define ss second

#define mp make_pair

#define ph push_back

#define mod 1000000007

#define debug 0

/* error check */

/*


1->varible range over flow 


2-> typecasting


3-> set  operation overflow


*/

int main()

{

    int t;

    cin >> t;

    while (t--)

    {

        int n;

        cin >> n;

        int has1[33]; // no of number  updated having ith bit 1

        int has0[33]; // no of number  updated having ith bit 0

        for (int i = 0; i <= 32; i++)

        {

            has0[i] = 1; // since initiall we consider a null set

            has1[i] = 0;
        }

        lli xr = 0;

        lli ans = 0;

        for (int i = 0; i < n; i++)

        {

            lli num;

            scanf("%lld", &num);

            num = num ^ xr;

            xr = num; // xor from 0 ot i..

            for (int j = 30; j >= 0; j--) // calculation of ans

            {

                int f1 = 0, f0 = 0; // flag  for  keeping ith bit is on of off

                if (num & (1 << j))

                {

                    if (has0[j])

                    {

                        ans += has0[j] * lli(1 << j);

                        //has0[j] number on number from( xor  0 to l)                                                     // have  ith bit off  and lli(1<<j)  is equivalent

                        // value  of  jth index
                    }

                    f1 = 1;
                }

                else

                {

                    if (has1[j])

                    {

                        ans = ans + (has1[j] * lli(1 << j));
                    }

                    f0 = 1;
                }

                if (f1)
                    has1[j]++;

                if (f0)
                    has0[j]++;
            }
        }

        cout << ans << endl;
    }
}
