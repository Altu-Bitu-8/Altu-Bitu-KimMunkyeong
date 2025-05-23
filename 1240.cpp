#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> tree;

int bfs(int start, int end, int n) {
	vector<bool>visited(n + 1, false);
	queue<pair<int, int>> q;
	q.push({ start, 0 });
	visited[start] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == end) {
			return cnt;
		}

		for (auto next : tree[cur]) {
			int nextNode = next.first;
			int height = next.second;

			if (!visited[nextNode]) {
				visited[nextNode] = true;
				q.push({ nextNode, height+cnt });
			}
		}
	}

}

int main() {
	int n, m;
	cin >> n >> m;

	tree.resize(n + 1);

	for (int i = 1; i < n; i++) {
		int node1;
		int node2;
		int height;
		cin >> node1 >> node2 >> height;

		tree[node1].push_back({ node2, height });
		tree[node2].push_back({ node1, height });

	}

	vector<int> answer;
	for (int k = 0; k < m; k++) {
		int a;
		int b;
		cin >> a >> b;

		answer.push_back(bfs(a, b, n));
	}

	for (int i : answer) {
		cout << i << '\n';
	}

	return 0;
}
