#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> wonso(n);
	vector<int> cnt(100001, 0);

	for (int i = 0; i < n; i++) {
		cin >> wonso[i];
	}

	int left = 0;
	int length = 0;
	
	for (int right = 0; right < n; right++) {
		cnt[wonso[right]]++;

		while (cnt[wonso[right]] > k) {
			cnt[wonso[left]]--;
			left++;
		}

		length = max(length, right - left + 1);
	}

	cout << length;

	
}