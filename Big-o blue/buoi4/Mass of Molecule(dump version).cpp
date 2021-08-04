#include <bits/stdc++.h>
#include <stack>
#include <string.h>

using namespace std;

bool isAlphabet(char t){
	return (t=='C' || t=='H' || t=='O');
}

int solve(string s){
	stack<char> a;
	int ans=0;

	for(int i=0; i<s.length(); ++i){

	}

	return ans;
}



int main(){
	string s, num="";
	int t=1, count=0;
	stack<int> c, o, h;

	cin >> s;
	for(int i=0; i<s.length(); ++i){
		if(isAlphabet(s[i])){
			if(s[i]=='C'){
				c.push(1);
			}
			if(s[i]=='H'){
				h.push(1);
			}
			if(s[i]=='O'){
				o.push(1);
			}
		}
		if(s[i]>='0' && s[i]<='9'){
			num=""; int j=i;
			while(s[j]>='0' && s[j]<='9'){
				num+=s[j++];
			}
			int temp=atoi(num.c_str());
			cout << temp << '\n';
			if(isAlphabet(s[i-1])){
				if(s[i-1]=='C'){
					c.top()*=temp;
				}
				if(s[i-1]=='H'){
					h.top()*=temp;
				}
				if(s[i-1]=='O'){
					o.top()*=temp;
				}
			}
			if(s[i-1]==')'){
				int q=i-1, c1=0, c2=0, c3=0;
				while(s[q]!='('){
					c1+=(s[q]=='C');
					c2+=(s[q]=='H');
					c3+=(s[q]=='O');
					--q;
				}	
				vector<int> cc1, cc2, cc3;
				while(--c1){
					cc1.push_back(c.top());
					c.pop();
				}
				while(--c2){
					cc2.push_back(h.top());
					h.pop();
				}
				while(--c3){
					cc3.push_back(o.top());
					o.pop();
				}
				for(int i=0; i<cc1.size(); ++i){
					cc1[i]*=temp;
					c.push(cc1[i]);
				}
				for(int i=0; i<cc2.size(); ++i){
					cc2[i]*=temp;
					h.push(cc2[i]);
				}
				for(int i=0; i<cc3.size(); ++i){
					cc3[i]*=temp;
					o.push(cc3[i]);
				}
			}
			i=j-1;
		}
	}

	int ans=0;
	while(!c.empty()){
		ans+=c.top()*12;
		c.pop();
	}
	while(!h.empty()){
		ans+=h.top();
		h.pop();
	}
	while(!o.empty()){
		ans+=o.top()*16;
		o.pop();
	}

	cout << ans;


	return 0;
}
