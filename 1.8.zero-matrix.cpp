#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> mat;
	for (int i = 0; i < m; ++i) {
		vector<int> row(n);
		for (int j = 0; j < n; ++j)
			cin >> row[j];

		mat.push_back(row);
	}

	unordered_set<int> zcol;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j) {
			bool zrow = false;
			if (!mat[i][j]) {
				zrow = true;
				zcol.insert(j);
			}
			if (zrow)
				for (int& e : mat[i])
					e = 0;
		}

	for (const int& col : zcol)
		for (int i = 0; i < m; ++i)
			mat[i][col] = 0;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j)
			cout << " " << mat[i][j];
		
		cout << endl;
	}
}
