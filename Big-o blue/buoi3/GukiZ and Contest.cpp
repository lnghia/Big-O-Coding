#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, t, rs;
	vector<int> a, ans, t2;

	cin >> n;
	int t1=n;
	while(n--){
		cin >> t;
		a.push_back(t);
	}
	t2=a;
	sort(a.begin(), a.end());
	for(int i=0; i<t2.size(); ++i){
		int j=i;
		vector<int>::iterator up;
		up=upper_bound(a.begin(), a.end(), t2[i]);
		if(up==a.end()){
			rs=0;
		}
		else{
			rs=t1-(up-a.begin());
		}
		ans.push_back(rs+1);
		while(t2[i+1]==t2[j]){
			ans.push_back(rs+1);
			++i;
		}
	}

	for(int i=0; i<ans.size(); ++i){
		cout << ans[i] << ' ';
	}

	return 0;
}