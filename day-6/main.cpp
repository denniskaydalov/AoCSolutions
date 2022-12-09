#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    freopen("aoc.in", "r", stdin);
    freopen("aoc.out", "w", stdout);

    string s;
    cin >> s;
    for(int i { }; i < s.length()-14; ++i) {
        int c[200] { }, u { };
        for(int j { }; j < 14; ++j) {
            if(!c[s[j+i]]++) {
                u++;
            }
        }
        if(u == 14) {
            cout << i+14;
            break;
        }
    }
}
