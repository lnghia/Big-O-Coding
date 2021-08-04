#include <bits/stdc++.h>

using namespace std;

int solve(int n){
	int tmp, ans=1e9;
	int left=1, right=1e7;
	vector<int> steps;

	while(n--){
		cin >> tmp;
		steps.push_back(tmp);
	}

	sort(steps.begin(), steps.end());
	while(left<=right){
		int mid=(left+right)/2;
		int energy=mid, temp=0;

		for(int i=0; i<steps.size(); ++i){
			if(energy<steps[i]-temp){
				energy=-1;
				break;
			}
			energy-=(energy<=steps[i]-temp);
			temp=steps[i];
		}
		if(!energy){
			return mid;
		}
		if(energy>0){
			ans=min(mid, ans);
			right=mid-1;
		}
		if(energy<0){
			left=mid+1;
		}
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, i=1;

	cin >> t;
	while(t--){
		int n, tmp;

		cin >> n;
		cout << "Case " << i++ << ": " << solve(n) << '\n';
	}

	return 0;
}