#include <iostream>
#include <stack>
#include <string.h>
#include <string>

using namespace std;

int main(){
	string s;
	stack<string> a;
	int ans=0;

	cin >> s;
	for(int i=0; i<s.length(); ++i){
		if(s[i]>='0' && s[i]<='9'){
			int num=0;
			while(s[i]>='0' && s[i]<='9'){
				num=num*10+(s[i]-'0');
				++i;
			}
			int tmp=atoi(a.top().c_str());
			tmp*=num;
			string t=to_string(tmp);
			a.top()=t;
		}
		if(s[i]==')'){
			int j=i, sum=0;
			while(!a.empty() && a.top()!="("){
				sum+=atoi(a.top().c_str());
				a.pop();
			}
			a.pop();
			string t=to_string(sum);
			a.push(t);
		}
		if(s[i]=='C' || s[i]=='H' || s[i]=='O'){
			if(s[i]=='C'){
                a.push("12");
			}
			if(s[i]=='H'){
                a.push("1");
			}
			if(s[i]=='O'){
                a.push("16");
			}
		}
		if(s[i]=='('){
            a.push("(");
        }
	}
	while(!a.empty()){
		ans+=atoi(a.top().c_str());
		a.pop();
	}
	cout << ans;


	return 0;
}
