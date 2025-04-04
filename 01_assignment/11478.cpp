#include <iostream>
#include <set>

using namespace std;

int main(){
    string s;
    cin >> s;

    set<string> substrings;
    int cnt;

    for(int i = 0; i < s.length(); i++){
        string temp = "";
        for(int j = i; j <s.length(); j++){
            temp += s[j];
            substrings.insert(temp);
        }
    }

    cout << substrings.size();

    return 0;

}