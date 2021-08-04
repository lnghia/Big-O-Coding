#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k, temp;
	double ans=0;
	vector<double> accumulators; 

	cin >> n >> k;
	while(n--){
		cin >> temp;
		accumulators.push_back(temp);
	}

	sort(accumulators.begin(), accumulators.end());
	double left=0, right=1000;
	int i=0;

	while(left<=right /*&& i++<1000*/){
		double mid=(left+right)/2;
		double give=0, receive=0;

		for(int i=0; i<accumulators.size(); ++i){
			if(accumulators[i]<mid){
				receive+=mid-accumulators[i];
			}
			else{
				double temp1=accumulators[i]-mid;
				give+=temp1-temp1*k/100;
			}
		}
		if(give>=receive){
			ans=max(ans, mid);
		}
		if(give>receive){
			left=mid;
		}
		else{
			right=mid;
		}
	}

	cout << fixed << setprecision(7) << ans;

	return 0;
}