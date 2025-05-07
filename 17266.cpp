#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;

bool cntHeight(int h, vector<int>& lamp, int n) {
	if (lamp[0] - h > 0) {
		return false;
	}

	for (int i = 0; i < m-1; i++) {
		if (lamp[i] + h < lamp[i + 1]-h) {
			return false;
		}
	}

	if (lamp[m-1] + h < n) {
		return false;
	}

	return true;
}

int main() {
	cin >> n >> m;

	vector<int> lamp(m);
	for (int i = 0; i < m; i++) {
		cin >> lamp[i];
	}
	
	sort(lamp.begin(), lamp.end());

	int left = 0;
	int right = n-1;
	int result = n;

	while (left <= right) {
		int mid = (left + right) / 2;
		
		if (cntHeight(mid, lamp, n)) {
			result = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
		
	}

	cout << result;
}