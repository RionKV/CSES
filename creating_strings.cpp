#include <bits/stdc++.h>
using namespace std;

set<string> solve(string& s) {
    set<string> bag;

    // Base case
    if (s.empty()) {
        bag.insert("");
        return bag;
    }

    char ch = s.back();
    s.pop_back();
    set<string> rec = solve(s);

    for (string str : rec) {
        int l = str.length();
        for (int i = 0; i <= l; i++) {
            string new_str = str;
            new_str.insert(i, 1, ch);  //at index "i" insert "ch" -> "1" time
            bag.insert(new_str);
        }
    }

    return bag;
}

int main() {
    string s;
    cin >> s;

    set<string> ans = solve(s);

    int k = ans.size();
    cout << k << endl;
    for (string str : ans) {
        cout << str << endl;;
    }

    return 0;
}
