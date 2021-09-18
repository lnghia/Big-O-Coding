#include <iostream>
#include <set>
using namespace std;
const int MAX = 10;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

char graph[MAX][MAX];
bool visited[MAX][MAX];
int n;
set<long long> octaves;

bool onBoard(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void dfs(int sx, int sy, int step, long long bits) {
    visited[sx][sy] = true;
    bits |= 1LL << (sx * n + sy);

    if (step == 8) {
        octaves.insert(bits);
    }
    else {
        for (int i = 0; i < 4; i++) {
            int x = sx + dx[i];
            int y = sy + dy[i];

            if (onBoard(x, y) && !visited[x][y] && graph[x][y] == 'X') {
                dfs(x, y, step + 1, bits);
            }
        }
    }

    bits &= ~(1 << (sx * n + sy));
    visited[sx][sy] = false;
}

int main() {
    int t;
    long long bits;
    cin >> t;

    for (int tc = 0; tc < t; tc++) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> graph[i][j];
                visited[i][j] = false;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == 'X') {
                    bits = 0;
                    dfs(i, j, 1, bits);
                }
            }
        }

        cout << octaves.size() << endl;
        octaves.clear();
    }
    return 0;
}