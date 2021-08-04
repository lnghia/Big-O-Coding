#include<iostream>
#include<vector>

using namespace std;

int solve(int n, vector<int> a){
	int tmp=0, ans=0, i=0;

	while(n--){
		if(a[i]-tmp<15){
			ans+=(a[i]-tmp);
			tmp=a[i++];      
    }
		else{
			ans+=15;
			return ans;      
    }    
  }	
  
	return ans;  
}

int main(){
	int n, temp;
	vector<int> a;  

	cin >> n;
	while(n--){
		cin >> temp;
		a.push_back(temp);    
  }  
	cout << solve(n, a);

	return 0;  
}