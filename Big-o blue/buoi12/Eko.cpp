#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long n, m, tmp;
	vector<long long> trees;
	vector<long long> high;
	long long ans=0;

	cin >> n >> m;
	while(n--){
		cin >> tmp;
		trees.push_back(tmp);
	}
	sort(trees.begin(), trees.end());

	long long left=0, right=trees[trees.size()-1];

	while(left<=right){
		long long mid=(left+right)/2;
		long long total=0;

		for(long long i=0; i<trees.size(); ++i){
			total+=(trees[i]-mid>=0)?trees[i]-mid:total;
		}
		if(total>=m){
			ans=max(ans, mid);
		}
		if(total>m){
			left=mid+1;
		}
		else{
			right=mid-1;
		}
	}

	cout << ans;

	return 0;
}