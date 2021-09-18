#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> InputNames() {
    int n;
    cin >> n;
    
    string cache;
    getline(cin, cache);

    vector<string> names(n, string());
    for (int i = 0; i < n; ++i) {
        getline(cin, names[i]);
    }
    return names;
}

vector<vector<int>> SetupLexicographical(const vector<string> & names) {
    vector<vector<int>> lexicographical(26, vector<int>());
    vector<vector<bool>> relation(26, vector<bool>(26, false));

    bool flag;

    for (int i = 0; i < names.size() - 1; ++i) {
        flag = false;
        int minSize = names[i].length() < names[i + 1].length() ? names[i].length() : names[i + 1].length();
        for (int j = 0; j < minSize; ++j) {
            if (names[i][j] != names[i + 1][j]) {
                relation[names[i][j] - 97][names[i + 1][j] - 97] = true;
                flag = true;
                break;
            }
        }
        if (!flag && (names[i].length() > names[i + 1].length())) {
            cout << "Impossible";
            exit(0);
        }
    }

    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (relation[i][j]) {
                lexicographical[i].emplace_back(j);
            }
        }
    }

    return lexicographical;
}

pair<bool, string> TopoSort(vector<vector<int>> & lexicographical) {
    vector<int> inDegrees(26, 0);
    pair<bool, string> result;
    vector<int> zeroInDegree;

    for (int u = 0; u < 26; ++u) {
        vector<int>::iterator it;
        for (it = lexicographical[u].begin(); it != lexicographical[u].end(); ++it) {
            inDegrees[*it]++;
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (inDegrees[i] == 0) {
            zeroInDegree.emplace_back(i);
        }
    }

    while (!zeroInDegree.empty()) {
        int u = zeroInDegree.back();
        zeroInDegree.pop_back();
        result.second.push_back(u + 97);
        vector<int>::iterator it;
        for (it = lexicographical[u].begin(); it != lexicographical[u].end(); ++it) {
            inDegrees[*it]--;
            if (inDegrees[*it] == 0) {
                zeroInDegree.emplace_back(*it);
            }
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (inDegrees[i] != 0) {
            return pair<bool, string>(false, string());
        }
    }

    result.first = true;
    return result;
}

int main() {
    vector<string> names = InputNames();
    vector<vector<int>> lexicographical = SetupLexicographical(names);
    pair<bool, string> result = TopoSort(lexicographical);
    if (!result.first) {
        cout << "Impossible";
    }
    else {
        for (auto & i : result.second) {
            cout << i;
        }
    }
    return 0;
}