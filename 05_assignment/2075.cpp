#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int t;
            cin >> t;
            if (min_heap.size() < n) {
                min_heap.push(t);
            }
            else if (t > min_heap.top()){
                min_heap.pop();
                min_heap.push(t);
            }
        }
    }

    cout << min_heap.top();
    
}