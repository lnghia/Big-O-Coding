#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, t;
	long long tmp;

	cin >> t;
	while(t--){
		set<long long> candies;

		cin >> n >> m;
		while(n--){
			cin >> tmp;
			candies.insert(tmp);
		}
		while(m--){
			cin >> tmp;
			set<long long>::iterator it=candies.find(tmp);
			if(it!=candies.end()){
				cout << "YES\n";
			}
			else{
				cout << "NO\n";
				candies.insert(tmp);
			}
		}
	}
	

	return 0;
}