#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> mat(n);
	for (int i = 0; i < n; ++i) {
		vector<int> row(n);
		for (int j = 0; j < n; ++j)
			cin >> row[j];
		mat[i] = row;
	}

	for (int layer = 0; layer < n/2; ++layer) {
		int first = layer, last = n - 1 - layer;
		for (int i = first; i < last; ++i) {
			int offset = i - first;
			int top = mat[first][i];
			mat[first][i] = mat[last-offset][first];
			mat[last-offset][first] = mat[last][last-offset];
			mat[last][last-offset] = mat[i][last];
			mat[i][last] = top;
		}
	}

	for (vector<int>& row : mat) {
		for (int& no : row)
			cout << " " << no;
		
		cout << endl;
	}
}
