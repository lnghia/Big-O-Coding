#include <bits/stdc++.h>

using namespace std;

int strokesItTakes(vector<int>& arr, int l, int r, int paintedHeight){
    if(l > r) return 0;

    int lowestStrokeInd = l;

    for(int i = l; i <= r; ++i){
        if(arr[i] < arr[lowestStrokeInd]){
            lowestStrokeInd = i;
        }
    }

    int verticalStrokesItTakes = r - l + 1;

    int horitalStrokesItTakes = arr[lowestStrokeInd] - paintedHeight + strokesItTakes(arr, l, lowestStrokeInd - 1, arr[lowestStrokeInd]) + strokesItTakes(arr, lowestStrokeInd + 1, r, arr[lowestStrokeInd]);

    return min(verticalStrokesItTakes, horitalStrokesItTakes);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, tmp;
    vector<int> arr;

    cin >> n;
    while(n--){
        cin >> tmp;
        arr.push_back(tmp);
    }

    cout << strokesItTakes(arr, 0, arr.size() - 1, 0);

    return 0;
}