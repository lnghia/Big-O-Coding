#include <bits/stdc++.h>

using namespace std;

double getDistance(double x, double y){
	return sqrt(x*x+y*y);
}

int main(){
	int n, s, p, i=0;
	double x, y;
	vector<pair<double, int> > a;

	cin >> n >> s;
	for(int i=0; i<n; ++i){
		cin >> x >> y >> p;
		a.push_back(make_pair(getDistance(x, y), p));
	}

	sort(a.begin(), a.end());
	while(i<a.size() && (s+a[i].second)<1e6){
		//cout << s << ' ' << a[i].first << ' ' << a[i].second << '\n';
		s+=a[i++].second;
	}

	if(i==a.size()-1 && s+a[i].second<1e6 || i>=a.size()){
		cout << -1;

		return 0;
	}

	cout << fixed << setprecision(7) << a[i].first;

	return 0;	
}