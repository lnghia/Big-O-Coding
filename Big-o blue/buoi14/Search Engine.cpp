#include <bits/stdc++.h>

using namespace std;

struct Node
{	
	Node *child[26];
	int countWord;
};

Node *newNode(){
	Node *node=new Node;

	node->countWord=0;
	for(int i=0; i<26; ++i){
		node->child[i]=NULL;
	}

	return node;
}

void addWord(Node *root, string s, int weight){
	int ch;
	Node *temp=root;

	for(int i=0; i<s.size(); ++i){
		ch=s[i]-'a';
		if(temp->child[ch]==NULL){
			temp->child[ch]=newNode();
		}
		temp=temp->child[ch];
	}
	temp->countWord=weight;
}

struct Node *findWord(Node *root, string s){
	int ch;
	Node *temp=root;

	for(int i=0; i<s.size(); ++i){
		ch=s[i]-'a';
		if(temp->child[ch]==NULL){
			return NULL;
		}
		temp=temp->child[ch];
	}

	return temp;
}

int findbestWord(Node *root, string s){
	int ans=-1;
	Node *temp=findWord(root, s);
	stack<Node*> tmp;

	if(temp!=NULL){
		tmp.push(temp);
		while(!tmp.empty()){
			Node *node=tmp.top();
			tmp.pop();
			for(int j=0; j<26; ++j){
				if(node->child[j]!=NULL){
					tmp.push(node->child[j]);
					ans=max(ans, node->child[j]->countWord);
				}
			}
		}
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q, weight, temp;
	string str, query;
	Node *root=newNode();

	cin >> n >> q;
	while(n--){
		cin >> str >> weight;
		addWord(root, str, weight);
	}

	while(q--){
		cin >> query;
		temp=findbestWord(root, query);
		cout << temp << '\n';
	}

	return 0;
}