#include <bits/stdc++.h>

using namespace std;

vector<int> dir_x = {1, -1, 0, 0};
vector<int> dir_y = {0, 0, 1, -1};
unordered_set<string> paths;
vector<pair<int, int>> path;

bool comparator(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first < b.first)
    {
        return 1;
    }
    if (a.first > b.first)
    {
        return 0;
    }

    return a.second <= b.second;
}

string hash_func(vector<pair<int, int>> &_path)
{
    string rs = "";

    for (auto &p : _path)
    {
        rs += to_string(p.first);
        rs += ':';
        rs += to_string(p.second);
        rs += '-';
    }

    return rs;
}

void dfs(vector<vector<char>> &map, vector<vector<bool>> &visited, int x, int y, int len, int &count)
{
    visited[x][y] = 1;
    path.push_back({x, y});

    // for (auto &p : path)
    // {
    //     cout << p.first << '-' << p.second << ' ';
    // }
    // cout << x << " = " << y << '\n';

    if (path.size() == 8)
    {
        // for (auto &p : path)
        // {
        //     cout << p.first << '-' << p.second << ' ';
        // }
        vector<pair<int, int>> tmp_path = path;
        sort(tmp_path.begin(), tmp_path.end(), comparator);
        string key = hash_func(tmp_path);
        if (paths.find(key) == paths.end())
        {
            paths.insert(key);
            ++count;
        }
        // cout << '\n';

        return;
    }

    for (int k = 0; k < 4; ++k)
    {
        int nxtX = x + dir_x[k];
        int nxtY = y + dir_y[k];

        if (nxtX >= 0 && nxtX < map.size() && nxtY >= 0 && nxtY < map.size() && !visited[nxtX][nxtY] && map[nxtX][nxtY] == 'X')
        {
            dfs(map, visited, nxtX, nxtY, len + 1, count);
            visited[nxtX][nxtY] = 0;
            path.pop_back();
            // cout << "==> ";
            // for (auto &p : path)
            // {
            //     cout << p.first << '-' << p.second << ' ';
            // }
            // cout << x << " = " << y << " + " << nxtX << " = " << nxtY << '\n';
        }
    }
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int t;

    cin >> t;
    while (t--)
    {
        int n;
        vector<vector<char>> map;
        vector<vector<bool>> visited;

        char tmp;
        int count = 0;

        cin >> n;
        map.resize(n);
        visited.resize(n, vector<bool>());

        for (auto &i : visited)
        {
            i.resize(n, 0);
        }

        path.clear();
        paths.clear();

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> tmp;
                map[i].push_back(tmp);
            }
        }

        for (int i = 0; i < map.size(); ++i)
        {
            for (int j = 0; j < map.size(); ++j)
            {
                if (map[i][j] == 'X')
                {
                    // if(path.size()) p
                    dfs(map, visited, i, j, 0, count);
                    if(path.size()) path.clear();
                    visited[i][j] = 0;
                    // if(path.size()) path.pop_back();
                }
            }
        }

        cout << count << '\n';
    }

    return 0;
}
