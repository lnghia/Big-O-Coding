#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int x=1, y=1, v=1;
	map<int, pair<int, int> > graph;
	int l1[6]={0, 1, 4, 5, 16, 17};
	int l2[6]={0, 2, 3, 6, 15, 18};
	int l3[6]={0, 9, 8, 7, 14, 19};
	int l4[6]={0, 10, 11, 12, 13, 20};
	int l5[6]={0, 25, 24, 23, 22, 21};

	for(int i=1; i<=5; ++i){
		graph[l1[i]]=make_pair(1, i);
	}

	for(int i=1; i<=5; ++i){
		graph[l2[i]]=make_pair(2, i);
	}

	for(int i=1; i<=5; ++i){
		graph[l3[i]]=make_pair(3, i);
	}

	for(int i=1; i<=5; ++i){
		graph[l4[i]]=make_pair(4, i);
	}

	for(int i=1; i<=5; ++i){
		graph[l5[i]]=make_pair(5, i);
	}

	int i=1;

	cin >> n;
	while(n--){
		long long tmp;

		cin >> tmp;
		map<int, pair<int, int> >::iterator it;
		if(tmp>1e9){
			tmp/=1e9;
		}
		if(tmp%25==0){
			it=graph.find(25);
		}
		else 
			it=graph.find(tmp%25);
		cout << "Case " << i++ << ": " << it->second.second << ' ' << it->second.first << '\n';
	}

	return 0;
}