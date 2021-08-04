#include <iostream>
#include <vector>

using namespace std;

pair<int, int> solve(vector<int> a, int k){
	pair<int, int> ans;
	int tmp=a[0], i=0, count=0, r=0;
	int b[100000]={0};

	while(a[i]==tmp){
		++i;
	}
	for(int j=i-1; j<a.size(); ++j){
		count+=(b[a[j]]==0);
		//cout << count << ' ' << a[j] << ' ' << b[j] << '\n';
		++b[a[j]];
		if(count==k){
			r=j;
			break;
		}
	}

	if(count!=1 && i==1 && r+1==1){
		return ans=make_pair(-1, -1);
	}
	ans=make_pair(i, r+1);

	return ans;
}

int main(){
	vector<int> tmp;
	int t, n, k;
	int a[100000]={};

	cin >> n >> k;
	while(n--){
		cin >> t;
		tmp.push_back(t);
	}
	pair<int, int> ans=solve(tmp, k);
	cout << ans.first << ' ' << ans.second;

	return 0;
}