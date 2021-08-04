#include <bits/stdc++.h>
#include <stack>

using namespace std;

int main(){
	string t, t2;
	int n;
	stack<char> a;

	cin >> n;
	cin.ignore();
	while(n--){
		getline(cin, t);
		for(int i=0; i<t.length(); ++i){
			if(t[i]==')'){
				cout << a.top();
				a.pop();
			}
			if(t[i]=='+'||t[i]=='-'||t[i]=='*'||t[i]=='/'||t[i]=='^'){
				a.push(t[i]);
			}
			else if(t[i]!='(' && t[i]!=')' && t[i]!=' '){
				cout << t[i];
			}
		}
		cout  << '\n';
	}

	return 0;
}