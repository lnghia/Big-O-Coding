#include <iostream>
#include <math.h>

using namespace std;

int solve(string s){
	string tmp;
	char pos='a';
	int ans=0, temp=0;

	cin >> tmp;
	for(int i=0; i<tmp.length(); ++i){
		temp=abs(pos-tmp[i]);
		if(temp>13){
			ans+=26-temp;
		}
		else{
			ans+=temp;
		}
		pos=tmp[i];
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	string tmp="abcdefghijklmnopqrstuvwxyz";

	cout << solve(tmp);

	return 0;
}