#include <bits/stdc++.h>
#include <queue>

using namespace std;

void cp1(queue<int> &a, queue<int> &b, int k=0){
	while(!a.empty() && a.front()!=k){
		b.push(a.front());
		a.pop();
	}
}

void solve(int p, int c, int k){
	char c1;
	int c2=0, t, o=1;
	queue<int> a, ans;

	t=(p>2000)?2000:p;
	for(int i=1; i<=t; ++i){
		a.push(i);
	}
	//cin.ignore();
	while(c--){
		queue<int> b;

		cin >> c1;
		c2=0;
		if(c1=='E'){
			cin >> c2;
			//cin.ignore();
		}
		if(c2>2000){
			while(!a.empty()){
				b.push(a.front());
				a.pop();
			}
			a.push(c2);
			while(!b.empty()){
				a.push(b.front());
				b.pop();
			}
			//cout << 1 << '\n';
		}
		else if(c2!=0){
			cp1(a, b, c2);
			a.pop();
			cp1(a, b);
			a.push(c2);
			cp1(b, a);
		}
		if(c1=='N'){
			//cout << 4 << '\n';
			if(t>2000)
				ans.push(o++);
			else{
				a.push(a.front());
				ans.push(a.front());
			}
			a.pop();
		}
	}
	cout << "Case " << k << ":\n";
	while(!ans.empty()){
		cout << ans.front() << '\n';
		ans.pop();
	}
}

int main(){
	int p, c1, k=1;
	char c;

	while(1){
		cin >> p >> c1;
		if(p==0 && c1==0){
			return 0;
		}
		solve(p, c1, k++);
	}

	return 0;
}