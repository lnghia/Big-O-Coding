#include <iostream>
#include <set>
#include <map>
#include <queue> 

using namespace std; 
const long long limit = 1000000000; 

set <long long> mark; 
map <long long, int> dist; 
long long x0, y0, x1, y1; 
int n; 
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1}; 
int dy[] = {1, -1, 0, 0, 1, -1, -1, 1}; 

long long calc(long long x, long long y) {
	long long val = x; 
	val = val * 1000000000LL + y; 
	return val; 
}

void bfs() {
	queue <long long> myqueue;
	long long S = calc(x0, y0);
	myqueue.push(S);
	dist[S] = 0;

	while (!myqueue.empty()) {
		long long u = myqueue.front(); 
		myqueue.pop(); 
		long long x = u / limit; 
		long long y = u % limit;
		for (int i = 0; i < 8; i++) {
			long long xx = x + dx[i]; 
			long long yy = y + dy[i];
			long long v = calc(xx, yy);  
			if (xx >= 1 && xx <= limit && yy >= 1 && yy <= limit && (mark.find(v) != mark.end())) {
				if (dist.find(v) == dist.end()) {
					dist[v] = dist[u] + 1;          
					if (v == calc(x1, y1)) {
		        cout << dist[v]; 
						return; 
					}

					myqueue.push(v); 
				}
			}
		}
	}

  cout << -1;                            
}

int main () {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	cin >> x0 >> y0 >> x1 >> y1; 
	mark.insert(calc(x0, y0));   
	mark.insert(calc(x1, y1)); 

	cin >> n; 
	for (int i = 1; i <= n; i++) {
		long long r, a, b; 
		cin >> r >> a >> b; 
		for (long long j = a; j <= b; j++) {
			mark.insert(calc(r, j)); 
		}
	}
                             
  bfs();
  return 0; 
}