#include <iostream>
using namespace std;

bool isUnique(string& s) {
	// assumption: string consists of only lowercase characters
	if (s.size() > 26)
		return false;

	int cnt = 0;
	for (char& c : s) {
		if (cnt & (1 << (c - 'a')))
			return false;
		else
			cnt |= (1 << (c - 'a'));
	}
	return true;
}

int main() {
	string s;
	getline(cin, s);
	cout << isUnique(s) << endl;
}
