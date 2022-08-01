#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, res;
	getline(cin, s);
	
	int i = 0;
	while (i < s.size()) {
		char c = s[i];
		res.push_back(c);
		int cnt = 0;
		while (c == s[i])
			++i, ++cnt;

		res.push_back('0' + cnt);
	}
	cout << (res.size() < s.size() ? res : s) << endl;
}
