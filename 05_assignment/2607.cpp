#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void parseInt(string word, vector<int> &arr) {
	for (size_t j = 0; j < word.length(); j++) {
		int num = word[j] - 'A';
		arr[num]++;
	}
}

bool isSimilar(vector<int>& arr, vector<int>& temp, int len1, int len2) {
	int cnt = 0;
	int diffAlpha = abs(len1 - len2);

	for (int i = 0; i < 26; i++) {
		if (arr[i] != temp[i]) {
			cnt += abs(arr[i] - temp[i]);
		}
	}

	return (cnt == 0 || cnt == 1 || (cnt == 2 && diffAlpha == 0));
}

int main() {
	int n;
	vector<int> cmp;

	cin >> n;

	string word;
	vector<int> arr(26, 0);

	cin >> word;
	parseInt(word, arr);

	int num = 0;

	for (int i = 0; i < n - 1; i++) {
		vector<int> temp(26, 0);
		string wordword;
		cin >> wordword;

		parseInt(wordword, temp);

		if (isSimilar(arr, temp, word.length(), wordword.length())) {
			num++;
		}
	}

	cout << num;

	return 0;
}