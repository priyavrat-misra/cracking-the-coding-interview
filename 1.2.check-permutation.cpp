#include <iostream>
#include <vector>
using namespace std;

bool checkPermutation(string& s1, string& s2) {
	vector<int> cnt(128);
	for (char& c : s1)
		++cnt[c];
	for (char& c : s2) {
		--cnt[c];
		if (cnt[c] < 0)
			return false;
	}
	return true;
}

int main() {
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	cout << checkPermutation(s1, s2) << endl;
}
