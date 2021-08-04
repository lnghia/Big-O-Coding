#include <bits/stdc++.h>

using namespace std;

int main(){
	int a[26]={};
	int n;
	string s;

	cin >> n;
	cin >> s;
	for(int i=0; i<n; ++i){
		if(s[i]<=90){
			++a[s[i]-65];
		}
		else{
			++a[s[i]-97];
		}
	}

	for(int i=0; i<26; ++i){
		if(a[i]==0){
			cout << "NO";

			return 0;
		}
	}

	cout << "YES";

	return 0;
}