#include <iostream>
#include <vector>

using namespace std;

bool visited[10001] = { false, };
vector<vector<int>> graph;
int cnt = -1;

void dfs(int a, int b, int depth) {
	visited[a] = true;

	if (a == b) {
		cnt == depth
		return;
	}

	for (int next : graph[a]) {
		if (!visited[next]) { 
			dfs(next, b, depth + 1);

			if (cnt != -1) {
				return;
			}
		}
	}
}

int main() {
	int num;
	cin >> num;

	int a, b;
	cin >> a >> b;

	int m;
	cin >> m;

	graph.resize(num + 1);

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(a, b, 0);

	cout << cnt;

}