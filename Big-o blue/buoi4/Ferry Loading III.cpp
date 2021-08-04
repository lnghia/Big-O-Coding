#include <bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;

void solve(long long cap, long long trav, long long m){
	queue< pair< long long, long long> > left_waiting, left_coming, right_waiting, right_coming;
	long long ans[10001]={};
	bool side=0;
	long long time=0, t=1e18;
	string tmp;
	long long count=0;

	for(long long i=0; i<m; ++i){
		cin >> t >> tmp;
		if(tmp=="left"){
			left_coming.push(make_pair(t, i));
		}
		else{
			right_coming.push(make_pair(t, i));
		}	
	}
	while(!left_coming.empty() || !left_waiting.empty() || !right_coming.empty() || !right_waiting.empty()){
		while(!left_coming.empty() && left_coming.front().first<=time){
			left_waiting.push(left_coming.front());
			left_coming.pop();
			//cout << "=================" << '\n';
			//cout << left_waiting.front().first << '\n';
		}
		while(!right_coming.empty() && right_coming.front().first<=time){
			right_waiting.push(right_coming.front());
			right_coming.pop();
			//cout << "++++++++++++++++++" << '\n';
			//cout << right_waiting.front().first << '\n';
		}
		if(left_waiting.empty() && right_waiting.empty()){
			if(!left_coming.empty() && !right_coming.empty())
				time=min(left_coming.front().first, right_coming.front().first);
			else{
				if(!left_coming.empty()){
					time=left_coming.front().first;
				}
				if(!right_coming.empty()){
					time=right_coming.front().first;
				}
			}
			continue;
			//cout << "---------------" << '\n';
			//cout << time << '\n';
			//cout << left_coming.front().first << ' ' << right_coming.front().first << ' ' << time << '\n';
		}
		if(side==0){
			count=0;
			while(!left_waiting.empty() && count<cap){
				//cout << "111111111111111111111111111" << '\n';
				//cout << left_waiting.front().first << '\n';
				ans[left_waiting.front().second]=time+trav;
				++count;
				left_waiting.pop();
			}	
			time+=trav;
			side=1;
			count=0;
			/*if(left_waiting.empty() && left_coming.empty()){
				time+=trav;
			}*/
		}
		else{
			count=0;
			while(!right_waiting.empty() && count<cap){
				//cout << "222222222222222222222222222222" << '\n';
				//cout << right_waiting.front().first << '\n';
				ans[right_waiting.front().second]=time+trav;
				++count;
				right_waiting.pop();
			}
			side=0;
			time+=trav;
			count=0;
			/*if(right_coming.empty() && right_waiting.empty()){
				time+=trav;
			}*/
		}
		
		//cout << "time " << time << '\n';
	}
	long long j=0;
	for(long long i=0; i<10001; ++i){
		if(ans[i]!=0){
			++j;
			cout << ans[i] << '\n';
		}
	}
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long n;
	long long capacity, traveling_time, m;

	cin >> n;
	while(n){
		--n;
		cin >> capacity >> traveling_time >> m;
		solve(capacity, traveling_time, m);
		if(n!=0){
			cout << '\n';
		}
	}

	return 0;
}