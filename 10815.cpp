#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void binarySearch(int n, int key, vector<int>& sang, int index, vector<int>&nani) {
	int left = 0;
	int right = n - 1;
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;
		if (sang[mid] == key) {
			nani[index] = 1;
			return;
		}
		else if (sang[mid] > key) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	nani[index] = 0;
}



int main() {
	int n;
	cin >> n;

	vector<int>sang(n);
	for (int i = 0; i < n; i++) {
		cin >> sang[i];
	}

	int m;
	cin >> m;

	vector<int> nani(m);
	for (int i = 0; i < m; i++) {
		cin >> nani[i];
	}

	sort(sang.begin(), sang.end());
	
	for (int i = 0; i < m; i++) {
		binarySearch(n, nani[i], sang, i, nani);
	}

	for (int i = 0; i < m; i++) {
		cout << nani[i] << " ";
	}
}