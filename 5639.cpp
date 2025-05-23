#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, pair<int, int>> tree;
vector<int> input;

void binary(int root, int child) {
	if (root > child) {
		if (tree[root].first == 0) {
			tree[root].first = child;
		}
		else {
			binary(tree[root].first, child);
		}
	}
	else {
		if (tree[root].second == 0) {
			tree[root].second = child;
		}
		else {
			binary(tree[root].second, child);
		}
	}
}

void postorder(int node) {
	if (node == 0) {
		return;
	}
	postorder(tree[node].first);
	postorder(tree[node].second);
	cout << node << "\n";
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	while (cin >> n) {
		input.push_back(n);
	}

	int root = input[0];

	for (int index = 1; index < input.size(); index++) {
		binary(root, input[index]);
	}

	postorder(root);

	return 0;
}