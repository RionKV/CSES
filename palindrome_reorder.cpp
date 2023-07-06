#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    if(n==1) {
        cout << s << endl;
        return 0;
    }

    int i = 0;
    int j = n-1;
    while(i < j) {
        if(s[i] == s[j]) {
            i++;
            j--;
        }
        else {
            int k = j-1;
            bool flag = true;
            while(i < k) {
                if(s[k] == s[i]) {
                    swap(s[k], s[j]);
                    i++;
                    j--;
                    flag = false;
                    break;
                }
                else {
                    k--;
                }
            }
            if(flag) {
                k = i+1;
                while(k<j) {
                    if(s[k] == s[j]) {
                        swap(s[k], s[i]);
                        i++;
                        j--;
                        flag = false;
                        break;
                    }
                    else {
                        k++;
                    }
                }
                if(flag) {
                    cout << "NO SOLUTION" << endl;
                    return 0;
                }
            }
        }
    }

    cout << s << endl;
    return 0;
}