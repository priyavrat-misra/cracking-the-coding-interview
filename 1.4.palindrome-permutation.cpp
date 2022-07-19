#include <iostream>
#include <unordered_map>
using namespace std;

bool palindromeP(string& s) {
	unordered_map<char, int> m;
	for (char& c : s)
		++m[c];

	int flag = 0;
	for (pair<const char, int>& row : m)
		if (row.second % 2)
			++flag;

	return flag == 0 || flag == 1;
}

int main() {
	string s;
	getline(cin, s);
	cout << palindromeP(s) << endl;
}
