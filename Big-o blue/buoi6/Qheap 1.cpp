#include <bits/stdc++.h>

using namespace std;

void del(priority_queue<int, vector<int>, greater<int> > &q, int t){
	priority_queue<int, vector<int>, greater<int> > temp;

	while(q.top()!=t){
		temp.push(q.top());
		q.pop();
	}
	q.pop();
	while(!q.empty()){
		temp.push(q.top());
		q.pop();
	}
	q=temp;
}

int main(){
	int t, n, l;
	int option;
	priority_queue<int, vector<int>, greater<int> > q;

	cin >> n;
	while(n--){
		cin >> option;

		if(option==1){
			cin >> t;
			q.push(t);
		}
		else if(option==2){
			cin >> t;
			del(q, t);
		}
		else if(option==3){
			cout << q.top() << '\n';
		}
	}

	return 0;
}