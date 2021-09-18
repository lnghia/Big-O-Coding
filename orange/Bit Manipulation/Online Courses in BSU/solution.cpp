#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<int> check;
vector< vector<int> > graph;
vector<int> res;
bool cycle;

void dfs(int u){
    if (check[u] == 0){
        check[u] = 1;
        for (int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i];
            dfs(v); 
        }
        check[u] = 2;
        res.push_back(u);
    } else if (check[u] == 1){
        cycle = true;
    }
}

int main(){
    vector<int> mainCourses;
    int n, k, x, nums;
    
    cin >> n >> k;
    for (int i = 0; i < k; i++){
        cin >> x;
        mainCourses.push_back(x - 1);
    }
    graph.resize(n);
    for (int i = 0; i < n; i++){
        cin >> nums;
        for (int j = 0; j < nums; j++){
            cin >> x;
            graph[i].push_back(x - 1);
        }
    }

    check.assign(n, 0);
    cycle = false;
    for (int i = 0; i < k; i++){
        int course = mainCourses[i];
        dfs(course);
    }

    if (cycle == true){
        cout << "-1" << endl;
        return 0;
    }
    cout << res.size() << endl;
    for (int c : res){
        cout << c + 1 << " ";
    }
    return 0;
}