#include <iostream>

using namespace std;


void all(int& s) // 모든 숫자 포함하는 집합 만들기
{
    s = (1 << 21) - 1;
    // 21번째 비트만 1이고 나머지 다 0, 그 상태에서 1 빼기
    // 그러면 20개의 비트가 모두 1
    // {1, 2, 3 ... 20}의 모든 숫자가 들어있다고 표현 가능
}

void empty(int& s) //모든 집합 비우기
{
    s = 0; // 모두 0
}

void add(int& s, int n) // 원소 추가하기
{
    s |= (1 << n); // or 연산자, n 번째 비트를 1로 만들기
}

void remove(int& s, int n) // 원소 제거
{
    s &= ~(1 << n);
    // and 연산자, n번째 비트만 0, 나머지는 1
    // 해당 비트만 0으로 바뀌고 나머지는 유지
}

int check(int& s, int n)
{
    if (s & (1 << n)) // 해당 비트가 1이면 0이 아님 -> 존재
    {
        return 1;
    }
    else // 해당 비트가 0이면 집합에 없음
    {
        return 0;
    }
}

void toggle(int& s, int n)
{
    s ^= (1 << n);
    //xor 연산 사용, 해당 비트가 1이면 0, 해당 비트가 0이면 1
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, x, s = 0;
    string op;
    cin >> m;
    while (m--)
    {
        cin >> op;

        // x 피연산자가 입력되지 않는 연산자: all, empty
        if (op == "all")
        {
            all(s);
        }
        else if (op == "empty")
        {
            empty(s);
        }

        // x 피연산자가 입력되는 연산자: add, remove, check, toggle
        else
        {
            cin >> x;
            if (op == "add")
            {
                add(s, x);
            }
            else if (op == "remove")
            {
                remove(s, x);
            }
            else if (op == "check")
            {
                cout << check(s, x) << "\n";
            }
            else if (op == "toggle")
            {
                toggle(s, x);
            }
        }
    }
    return 0;
}