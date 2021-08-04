#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n, i=0;
	string t1, t2, t3;
	vector<vector<string> > b;
	map<string, int> a;
	a.insert(make_pair("Isenbaev", 0));

	cin >> n;
	b.resize(n);
	while(i<n){
		cin >> t1 >> t2 >> t3;
		b[i].push_back(t1);
		b[i].push_back(t2);
		b[i++].push_back(t3);
	}

    for(int k=0; k<100; ++k){
        for(int j=0; j<n; ++j){
            int _min=200;
            map<string, int>::iterator it1, it2, it3;

            it1=a.find(b[j][0]);
            it2=a.find(b[j][1]);
            it3=a.find(b[j][2]);
            if(it1!=a.end()){
                _min=min(_min, it1->second);
            }
            if(it2!=a.end()){
                _min=min(_min, it2->second);
            }
            if(it3!=a.end()){
                _min=min(_min, it3->second);
            }
            if(it1==a.end() || a[b[j][0]]>_min+1){
                a[b[j][0]]=_min+1;
            }
            if(it2==a.end() || a[b[j][1]]>_min+1){
                a[b[j][1]]=_min+1;
            }
            if(it3==a.end() || a[b[j][2]]>_min+1){
                a[b[j][2]]=_min+1;
            }
        }
    }

	map<string, int>::iterator it;
	for(it=a.begin(); it!=a.end(); ++it){
		if(it->second>200){
			cout << it->first << " undefined\n";
		}
		else{
			cout << it->first << ' ' << it->second << '\n';
		}
	}

	return 0;
}
