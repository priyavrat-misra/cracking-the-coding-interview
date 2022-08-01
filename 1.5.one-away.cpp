#include <iostream>
using namespace std;

bool oneReplaceAway(string& s1, string& s2) {
	bool foundDiff = false;
	for (int i = 0; i < s1.size(); ++i)
		if (s1[i] != s2[i]) {
			if (foundDiff)
				return false;
			foundDiff = true;
		}
	return true;
}

bool oneInsertAway(string& s1, string& s2) {
	int i1 = 0, i2 = 0;
	while (i1 < s1.size() && i2 < s2.size()) {
		if (s1[i1] != s2[i2]) {
			if (i1 != i2)
				return false;
			++i2;
		} else {
			++i1;
			++i2;
		}
	}
	return true;
}

int main() {
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	if (s1.size() == s2.size())
		cout << oneReplaceAway(s1, s2) << endl;
	else if (s1.size() + 1 == s2.size())
		cout << oneInsertAway(s1, s2) << endl;
	else if (s1.size() - 1 == s2.size())
		cout << oneInsertAway(s2, s1) << endl;
}
