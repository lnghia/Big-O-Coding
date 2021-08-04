#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*class Topic{
	int id;
	int prev;
	int current;
	int change;
public:
	Topic(){}
	Topic(int id1, int prev1, int current1){
		id=id1;
		prev=prev1;
		current=current1;
		change=current-prev;
	}
	bool operator <(const Topic &topic){
		return (change<topic.change || (change==topic.change && id<topic.id));
	}
	friend ostream& operator <<(ostream &a, const Topic &temp){
		a << temp.id << ' ' << temp.current << '\n';

		return a;
	}
};*/

struct Topic {
    int id;
    long long old_score, new_score, change;

    Topic(int _id, long long _old_score, long long _new_score) {
        id = _id;
        old_score = _old_score;
        new_score = _new_score;
        change = new_score - old_score;
    }

    bool operator<(const Topic &other) const {
        return change < other.change || (change == other.change && id < other.id);
    }
};

int main(){
	int n;
	int id, z, p, l, c, s, count=0;
	priority_queue<Topic> q; 

	cin >> n;
	while(n--){
		cin >> id >> z >> p >> l >> c >> s;
		int tmp=50*p+5*l+10*c+20*s;
		q.push(Topic(id, z, tmp));
	}

	while(!q.empty() && count<5){
		++count;
		cout << q.top().id << ' ' << q.top().new_score << '\n';
		q.pop();
	}

	return 0;
}