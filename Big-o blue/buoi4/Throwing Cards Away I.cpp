#include <bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;

void solve(int t){
	int i=1;
	queue<int> deck, discarded_ones, remaining_ones;

	for(int i=1; i<=t; ++i){
		deck.push(i);
	}

	while(deck.size()>=2){
		discarded_ones.push(deck.front());
		deck.pop();
		deck.push(deck.front());
		deck.pop();
	}
	cout << "Discarded cards:";
	while(!discarded_ones.empty()){
		if(discarded_ones.size()>1){
			cout << ' ' << discarded_ones.front() << ',';
		}
		else{
			cout << ' ' << discarded_ones.front();
		}
		discarded_ones.pop();
	}
	cout << '\n';
	cout << "Remaining card:";
	while(!deck.empty()){
		if(deck.size()>1){
			cout << ' ' << deck.front() << ',';
		}
		else{
			cout << ' ' << deck.front() << '\n';
		}
		deck.pop();
	}
}

int main(){
	int n, t;

	while(1){
		cin >> t;
		if(!t){
			return 0;
		}
		solve(t);
	}

	return 0;
}