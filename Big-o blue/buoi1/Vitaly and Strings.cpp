#include <iostream>

using namespace std;

int compare(string a, string b){
	for(int i=0; i<a.size(); ++i){
		if(a[i]<b[i]){
			return -1;
		}
		if(a[i]>b[i]){
			return 1;
		}
	}

	return 0;
}

string reverse(string a){
	string ans="";

	for(int i=a.length()-1; i>=0; --i){
		ans+=a[i];
	}

	return ans;
}

string solve(string a, string b){
	int i=a.length()-1;
	string ans="";
	int t, t1=1;
	string tmp="abcdefghijklmnopqrstuvwxyz";

	for(int i=a.length()-1; i>=0; --i){
		if(t1==1){
			t=a[i]-97+t1;
			if(t>25){
				t1=1;
				t%=26;
			}
			else{
				t1=0;
			}
			ans+=tmp[t];
		}
		else{
			ans+=a[i];
		}
	}
	ans=reverse(ans);
	if(compare(ans, b)!=-1){
		return "No such string";
	}
	
	return ans;
}

int main(){
	string a, b;

	cin >> a >> b;
	cout << solve(a, b);

	return 0;
}