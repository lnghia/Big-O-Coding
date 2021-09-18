#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int expected = 0;
int cases = 0, valid = 0;

void recursive(int z, int val) {
	if (z == s2.size()) {
		if (val == expected) valid++;
		cases++; return;
	}
	if (s2[z] != '-') recursive(z+1, val+1);
	if (s2[z] != '+') recursive(z+1, val-1);
}

void Input() {
	cin >> s1 >> s2;
	for (int i=0; i<s1.size(); i++) {
		if (s1[i] == '+') expected++;
		else expected--;
	}
}

void Solve() {
	recursive(0, 0);
	cout << fixed << setprecision(10) << (double)valid / cases;
}

int main(int argc, char* argv[]) {
	Input(); Solve(); 
  return 0;
}