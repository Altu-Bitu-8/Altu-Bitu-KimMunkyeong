#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
 * [HINT]
 * 우선 m개의 줄을 만들고, 각 줄의 선두끼리 우선순위를 따져야겠네요!
 * 데카가 언제 화장실을 쓰는지 알기 위해서는 화장실에 온 순서도 기록해야 해요!
 */

struct info {
    int idx;        // 처음 줄에 선 번호
    int line_num;   // m개의 줄 중 속한 줄의 번호
    int work_days;  // 근무 일수
    int urgency;    // 급한 정도
};

struct cmp {
    bool operator()(const info& child, const info& parent) {
        if (parent.work_days != child.work_days) {
            return parent.work_days > child.work_days; // 일 수가 더 크면 우선순위를 가짐
        }
        if (parent.urgency != child.urgency) {
            return parent.urgency > child.urgency; // 더 급하면 우선순위를 가짐
        }
        return parent.line_num < child.line_num; // 숫자가 작으면 우선순위를 가짐
    }
};

int simulation(int m, int k, vector<queue<info>>& lines) {
    // 각 줄의 선두들이 저장되는 우선순위 큐
    priority_queue<info, vector<info>, cmp> pq;

    // 우선순위 큐 초기화
    for (int i = 0; i < m; i++) {
        if (!lines[i].empty()) {
            pq.push(lines[i].front()); // line 큐의 선두를 우선순위 큐에 넣어줌
            lines[i].pop(); // 넣은건 pop을 함으로써 계속 선두를 교체해줌
        }
    }

    // k 차례가 오기 전 화장실을 사용한 사람의 수
    int count = 0;

    while (!pq.empty() && pq.top().idx != k) {  // k의 차례가 되기 전까지
        int line_num = pq.top().line_num;
        pq.pop();

        if (!lines[line_num].empty()) {
            pq.push(lines[line_num].front()); // 그 line 큐에서 front를 pq에 넣고, front를 꺼낸다
            lines[line_num].pop();
        }

        count++;
    }

    return count; // 이 작업을 몇 번 했는지 (K앞에 몇 명이 있는지)
}

/**
 * [화장실의 규칙] - 우선순위 큐 & 시뮬레이션 문제
 *
 * 1. 각 사람은 (온 순서 % m) 번째 줄의 뒤에 서게 된다.
 * 2. 매 순간, 모든 줄의 앞 사람 중에 우선 순위가 가장 높은 사람부터 화장실을 이용한다.
 *
 * <우선순위>
 * 1. 근무 일자가 많은 사람
 * 2. 더 급한 사람
 * 3. 줄 번호가 앞선 사람
 *
 * ---
 * 1. 각 줄은 먼저 온 사람이 먼저 나가기 때문에, 큐를 이용해 저장한다.
 * 2. 모든 줄의 선두를 우선순위 큐에 넣고, 우선순위가 가장 앞선 사람부터 삭제한다.
 * 3. 어떤 줄의 선두가 화장실을 이용했으면, 그 줄의 선두를 우선 순위 큐에 넣는다.
 *
 * 이때, 0번부터 표기하므로 데카의 idx는 k가 된다.
 *
 * !주의! 큐에서 사람을 빼서 우선 순위 큐에 넣을 때, 항상 큐가 비어있지 않은지 확인
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k, d, h;
    cin >> n >> m >> k;

    vector<queue<info>> lines(m, queue<info>());
    // info 타입의 데이터를 담는 큐를 만들고, 큐를 원소로 가지는 벡터를 만듦
    // 여러 줄을 표현하는 벡터, lines 벡터의 크기는 m이고 빈 queue<info>로 초기화

    // 입력
    for (int i = 0; i < n; i++) {
        cin >> d >> h;
        lines[i % m].push({ i, i % m, d, h }); // m번째의 몇 번째인지(i%m) 체크, 값을 입력 받음
    }

    // 연산 & 출력
    cout << simulation(m, k, lines);

    return 0;
}