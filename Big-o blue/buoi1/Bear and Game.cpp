#include<iostream>

using namespace std;

int solve(int n){
	int tmp, ans=0, i=0;

	while(n--){
		cin >> tmp;    
		if(tmp-i<=15){
			ans+=(tmp-i);
			i=tmp;
			cout << ans << ' ' << i << '\n';      
    }
		else{
			ans+=15;
			cout << ans << ' ' << i << '@' << '\n';
			return ans;      
    }    
  }	
	if(90-i<=15){
		ans+=(90-i);    
		cout << ans << ' ' << i << '!' << '\n';
  }  
	else{
		ans+=15;    
		cout << ans << ' ' << i << '#' << '\n';
  }  
  
	return ans;  
}

int main(){
	int n;

	cin >> n;
	cout << solve(n);

	return 0;  
}