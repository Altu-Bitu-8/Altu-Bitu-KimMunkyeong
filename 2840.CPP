#include <iostream>
#include <vector>

using namespace std;

string printPan(int n, int index, vector<char>& wheel) {
	string pan = "";

	for (int i = index + n; i > index; i--) {
		pan += wheel[i % n];
	}

	return pan;
}

string calPan(int n, int k, vector<pair<int, char>>& pan) {
	vector<char> wheel(n, '?');
	vector<bool> duplicate(26, false);

		int index = 0;

	for (int i = 0; i < k; i++) {
		int s;
		char ch;

		pan.push_back({ s, ch });

		index = (index + s) % n;

		if (wheel[index] == ch) {
			continue;
		}

		if (wheel[index] != '?' || duplicate[ch - 'A']) {
			return "!";
		}

		wheel[index] = ch;
		duplicate[ch - 'A'] = true;
	}

	return printPan(n, index, wheel);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	vector<pair<int, char>> pan;

	for (int i = 0; i < k; i++) {
		int num;
		char ch;
		cin >> num >> ch;
		pan.push_back({ num, ch });
	}

	cout << calPan(n, k, pan);
}