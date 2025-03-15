#include <iostream>

using namespace std;


void all(int& s) // ��� ���� �����ϴ� ���� �����
{
    s = (1 << 21) - 1;
    // 21��° ��Ʈ�� 1�̰� ������ �� 0, �� ���¿��� 1 ����
    // �׷��� 20���� ��Ʈ�� ��� 1
    // {1, 2, 3 ... 20}�� ��� ���ڰ� ����ִٰ� ǥ�� ����
}

void empty(int& s) //��� ���� ����
{
    s = 0; // ��� 0
}

void add(int& s, int n) // ���� �߰��ϱ�
{
    s |= (1 << n); // or ������, n ��° ��Ʈ�� 1�� �����
}

void remove(int& s, int n) // ���� ����
{
    s &= ~(1 << n);
    // and ������, n��° ��Ʈ�� 0, �������� 1
    // �ش� ��Ʈ�� 0���� �ٲ�� �������� ����
}

int check(int& s, int n)
{
    if (s & (1 << n)) // �ش� ��Ʈ�� 1�̸� 0�� �ƴ� -> ����
    {
        return 1;
    }
    else // �ش� ��Ʈ�� 0�̸� ���տ� ����
    {
        return 0;
    }
}

void toggle(int& s, int n)
{
    s ^= (1 << n);
    //xor ���� ���, �ش� ��Ʈ�� 1�̸� 0, �ش� ��Ʈ�� 0�̸� 1
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

        // x �ǿ����ڰ� �Էµ��� �ʴ� ������: all, empty
        if (op == "all")
        {
            all(s);
        }
        else if (op == "empty")
        {
            empty(s);
        }

        // x �ǿ����ڰ� �ԷµǴ� ������: add, remove, check, toggle
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