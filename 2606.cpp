#include <iostream>
#include <vector>

using namespace std;

int n;
int num;
int graph[1001][1001] = { 0, };
bool visited[10001] = { false, };
int ans = 0;

void dfs(int from) {
	for (int i = 1; i <= num; i++) {
		if (graph[from][i] == 1 && !visited[i]) {
			visited[i] = true;
			ans++;
			dfs(i);
		}
	}

	return;
}

int main() {
	cin >> num;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = graph[b][a] = 1;
	}

	visited[1] = true;
	dfs(1);

	cout << ans;
}