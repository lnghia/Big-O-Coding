#include <bits/stdc++.h>

using namespace std;

bool isPowerOf2(int val)
{
    return (val && !(val & (val - 1)));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    bool flag = 0;

    cin >> t;
    while (t--)
    {
        int n, tmp;
        vector<int> arr;

        cin >> n;
        while (n--)
        {
            cin >> tmp;
            arr.push_back(tmp);
            flag = isPowerOf2(tmp);
        }

        if (flag)
        {
            cout << "YES\n";
            continue;
        }

        for (int i = 0, e = 1; i < 31; ++i, e <<= 1)
        {
            int and_subset = 0xFFFFFFFF;

            for (auto &num : arr)
            {
                if (num & e)
                {
                    and_subset &= num;
                }
            }
            
            if (isPowerOf2(and_subset))
            {
                flag = 1;
                break;
            }
        }

        cout << (flag ? "YES" : "NO") << '\n';
    }

    return 0;
}