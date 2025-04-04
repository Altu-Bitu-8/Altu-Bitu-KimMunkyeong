#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>

using namespace std;

int sumOfDigits(const string &s){
    int sum = 0;
    for(char ch : s){
        if(isdigit(ch)){
            sum += ch - '0';
        }
    }
    return sum;
}

bool cmp(const string &a, const string &b){
    if(a.length() != b.length()){
        return a.length() < b.length();
    }

    int sumA = sumOfDigits(a);
    int sumB = sumOfDigits(b);
    if(sumA != sumB){
        return sumA < sumB;
    }

    return a < b;

    
}

int main()
{
	int n;
    cin >> n;
    
    vector<string> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    sort(s.begin(), s.end(), cmp);

    for (const auto &str : s) {
        cout << str << "\n";
    }

    return 0;

}