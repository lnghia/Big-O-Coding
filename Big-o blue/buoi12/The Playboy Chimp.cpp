#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q, tmp;
	vector<int> heights;

	cin >> n;
	while(n--){
		cin >> tmp;
		heights.push_back(tmp);
	}

	sort(heights.begin(), heights.end());
	cin >> q;
	while(q--){
		cin >> tmp;
		vector<int>::iterator low=lower_bound(heights.begin(), heights.end(), tmp);
		vector<int>::iterator up=upper_bound(heights.begin(), heights.end(), tmp);
		int _low=low-heights.begin(), _up=up-heights.begin();

		--_low;
		if(_low<0){
			cout << 'X' << ' ';
		}
		else{
			while(_low>0 && heights[_low]>=tmp){
				--_low;
			}
			if(heights[_low]>=tmp){
				cout << 'X' << ' ';
			}
			else{
				cout << heights[_low] << ' ';
			}
		}
		if(_up>=heights.size()){
			cout << 'X' << '\n';
		}
		else{
			cout << heights[_up] << '\n';
		}
	}

	return 0;
}