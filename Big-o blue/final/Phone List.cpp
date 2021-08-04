#include <bits/stdc++.h>

using namespace std;

struct Node{
	int count;
	Node *child[10];
};

Node *makeNode(){
	Node *node=new Node;

	for(int i=0; i<10; ++i){
		node->child[i]=NULL;
	}
	node->count=0;

	return node;
}

void addNum(Node *root, string num){
	int ch;
	Node *temp=root;

	for(int i=0; i<num.length(); ++i){
		ch=num[i]-'0';

		if(temp->child[ch]==NULL)
			temp->child[ch]=makeNode();
		temp=temp->child[ch];
	}
	++temp->count;
}

int countNum(Node *root, string s){
	int ans=0;
	Node *temp=root->child[s[0]-'0'];
	stack<Node*> tmp;

	for(int i=1; i<s.length(); ++i){
		if(temp->child[s[i]-'0']==NULL){
			continue;
		}
		if(temp->child[s[i]-'0']!=NULL && temp->child[s[i]-'0']->count>0 && i!=s.length()-1){
			return 0;
		}
		if(temp->child[s[i]-'0']!=NULL)
			temp=temp->child[s[i]-'0'];
	}

	return 1;
}

string solve(int n){
	string ans="YES";
	string num;
	vector<string> nums;
	Node *root=new Node();

	while(n--){
		cin >> num;
		nums.push_back(num);
		addNum(root, num);
	}

	/*Node *tmp=root->child[9]->child[1];
	for(int i=0; i<10; ++i){
		if(tmp->child[i]==NULL){
			continue;
		}
		cout << i << ' ' << tmp->child[i]->count << '\n';
	}*/
	for(int i=0; i<nums.size(); ++i){
		if(countNum(root, nums[i])==0){
			return "NO";
		}
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;

	cin >> t;
	while(t--){
		int n;

		cin >> n;
		cout << solve(n) << '\n'; 
	}

	return 0;
}