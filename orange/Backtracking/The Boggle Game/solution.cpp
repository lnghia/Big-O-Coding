#include <iostream>
#include <string.h>
#include <set>
#include <vector>
using namespace std;

const string VOWELS = "AEOYIU";
const pair<int, int> DIRs[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int count_vowels(const string& word) {
    int res = 0;
    for (char c : word) {
        res += (VOWELS.find(c) != string::npos);
    }
    return res;
}

/**
 * board: current board to find words
 * x, y: current cell
 * cur_word: current cummulative word
 * visited: visiting state for each cell
 * found_words: target location for legal words
**/
void find_words(char board[4][4], int x, int y, const string& cur_word, bool visited[4][4], set<string>& found_words) {
    if (cur_word.length() == 4) {
        if (count_vowels(cur_word) == 2) {
            found_words.insert(cur_word);
        }
        return;
    }
    
    visited[x][y] = true;
    for (auto d : DIRs) {
        int nx = x + d.first, ny = y + d.second;
        if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && !visited[nx][ny]) {
            string new_cur_word = cur_word + board[nx][ny];
            find_words(board, nx, ny, new_cur_word, visited, found_words);
        }
    }
    visited[x][y] = false;
}

bool start = true; // just for checking whether to print new lines between test cases

void solve() {
    char board[2][4][4];
	char ch;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 8; ++j) {
			cin >> ch;
			if (ch == '#') exit(0);
            board[j >> 2][i][j & 3] = ch; // characters 0..3 -> board[0][i][0..3], characters 4..7 -> board[1][i][0..3]
        }
    }
    
    if (!start) {
        cout << endl;
    }
    start = false;
    
    // find words for both boards
    bool visited[4][4];
	memset(visited, 0, sizeof(visited));

    set<string> words[2];
    for (int board_id : {0, 1}) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                string cur_word(1, board[board_id][i][j]);
                find_words(board[board_id], i, j, cur_word, visited, words[board_id]);
            }
        }
    }
    
    vector<string> common_words;
    for (const string& word : words[0]) {
        if (words[1].find(word) != words[1].end()) {
            common_words.push_back(word);
        }
    }
    
    if (common_words.size() == 0) {
        cout << "There are no common words for this pair of boggle boards.\n";
    }
    else {
        for (const string& word : common_words) {
            cout << word << endl;
        }
    }
}

int main() {
    while (true) {
        solve();
    }
}