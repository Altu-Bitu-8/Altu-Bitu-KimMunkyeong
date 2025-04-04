// 15662: 톱니바퀴2

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> li; //톱니바퀴 극 저장
vector<pair<int, int>> stack; // 회전시킨 톱니바퀴, 방향 저장
vector<int> visited;

void check_rotation(int current_num, int current_dir) // 몇 번째 톱니바퀴, 방향 받음
{
    if (current_num - 1 >= 0 && visited[current_num - 1] == 0) //왼쪽 톱니 바퀴 존재, 아직 방문 x
    {
        if (li[current_num][6] != li[current_num - 1][2]) // 왼쪽 바퀴의 6번 인덱스와 오른쪽 바퀴의 2번 인덱스 비교
        { // 맞닿아 있는 면이 서로 다른 극인지 체크
            stack.push_back(make_pair(current_num - 1, current_dir * -1)); // 돌린다
            visited[current_num - 1] = 1; // 방문했다
            check_rotation(current_num - 1, current_dir * -1); // 재귀를 이용해 다시 비교
        }
    }
    if (current_num + 1 < li.size() && visited[current_num + 1] == 0) // 오른쪽 톱니바퀴 존재, 아직 방문 x
    {
        if (li[current_num][2] != li[current_num + 1][6])
        { // 맞닿아 있는 면이 서로 다른 극인지 체크
            stack.push_back(make_pair(current_num + 1, current_dir * -1)); // 오른쪽 바퀴 존재, 돌린다
            visited[current_num + 1] = 1; // 방문했다
            check_rotation(current_num + 1, current_dir * -1); // 재귀를 이용해 다시 비교하기
        }
    }
}

int main()
{
    int t;
    int k;

    cin >> t; // 톱니바퀴의 개수 T 입력

    li.resize(t); // 톱니바퀴 개수만큼 resize
    for (int i = 0; i < t; ++i)
        cin >> li[i]; // 톱니바퀴 상태 입력

    cin >> k; // 회전 횟수 K 입력
    for (int i = 0; i < k; ++i)
    { // k번 돌면서 회전할 수 있는지에 대해 체크
        int num, direction;
        cin >> num >> direction; // 방향 입력 (1이면 시계 방항, -1이면 반시계 방향)
        stack.clear();
        stack.push_back(make_pair(num - 1, direction)); // 몇 번째 톱니바퀴(0부터 시작)인지, 방향 넣기
        visited.assign(t, 0); // t개만큼 0을 초기화
        visited[num - 1] = 1; // 몇 번째 톱니바퀴를 방문했는지, 방문하면 1
        check_rotation(num - 1, direction); // 로테이션 체크 (어떤 톱니를 어떤 방향으로 돌리는가 -> stack에 저장)

        while (!stack.empty()) // 회전을 다 처리할 때까지
        {
            pair<int, int> top = stack.back();
            stack.pop_back();
            int tmp_num = top.first;  // 돌려야 할 톱니바퀴의 인덱스
            int tmp_dir = top.second; // 돌릴 방향
            if (tmp_dir == 1)
            { // 시계방향으로 돌리기
                li[tmp_num] = li[tmp_num].back() + li[tmp_num].substr(0, 7);
                // 맨 마지막 문자가 맨 앞으로 옴
                // 끝문자(7번) + 0번째 글자부터 7글자(6번까지)
            }
            else
            { // 반시계방향으로 돌리기
                li[tmp_num] = li[tmp_num].substr(1) + li[tmp_num][0];
                // 첫번째 문자를 맨 뒤로 이동시킴
                // 두번째 글자부터 끝까지 + 첫번째 문자
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < t; ++i)
    {
        if (li[i][0] == '1') // 0번째 인덱스의 값이 1이라면 숫자 증가
        {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}