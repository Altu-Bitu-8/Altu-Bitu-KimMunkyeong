#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	int a[1001], dp[1001];
	int len;
	int max_len = 0;
	int max_idx = -1;
	vector<int> tntwk;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		len = 0;

		for (int j = 0; j < i; j++) {
			if (a[i] > a[j]) {
				len = max(dp[j], len);
			}
		}

		dp[i] = len + 1;

		if (max_len < dp[i]) {
			max_len = dp[i];
			max_idx = i;
		}

	}

	
	for (int i = max_idx; i >= 0; i--) {
		if (max_len == dp[i]) {
			tntwk.push_back(a[i]);
			max_len--;
		}
	}

	int size = tntwk.size();
	cout << size;
}