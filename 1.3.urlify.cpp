#include <iostream>
using namespace std;

string urlify(string& s) {
	int spaceCnt = 0;
	for (char& c : s)
		if (c == ' ')
			++spaceCnt;

	string ans(s.size() + 2 * spaceCnt, ' ');
	string::reverse_iterator i = s.rbegin(), j = ans.rbegin();
	while (i != s.rend()) {
		if (*i == ' ') {
			*j = '0';
			*(j + 1) = '2';
			*(j + 2) = '%';
			j += 3;
		} else {
			*j = *i;
			j += 1;
		}
		++i;
	}
	return ans;
}

int main() {
	string s;
	getline(cin, s);
	cout << urlify(s) << endl;
}
