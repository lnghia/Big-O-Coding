#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, ans=0;
	string type_of_penguin;
	map<string, int> penguins;

	penguins["Emperor Penguin"]=0;
	penguins["Macaroni Penguin"]=0;
	penguins["Little Penguin"]=0;
	cin >> n;
	cin.ignore();
	while(n--){
		getline(cin, type_of_penguin);
		++penguins[type_of_penguin];
		ans=max(ans, penguins[type_of_penguin]);
	}
	map<string, int>::iterator it;
	for(it=penguins.begin(); it!=penguins.end(); ++it){
		if(it->second==ans){
			cout << it->first;
		}
	}

	return 0;
}