#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    freopen("aoc.in", "r", stdin);
    freopen("aoc.out", "w", stdout);

    string s;
    int t, x { }, d { 1 };
    while(cin >> s) {
        if(s != "noop") {
            cin >> t;
            if(x == 40) {
                cout << '\n';
                x = 0;
            }
            if(x == d-1 || x == d || x == d+1) cout << "█"; else cout << "░";
            x++;
            if(x == 40) {
                cout << '\n';
                x = 0;
            }
            if(x == d-1 || x == d || x == d+1) cout << "█"; else cout << "░";
            x++;
            d += t;
        }
        else {
            if(x == 40) {
                cout << '\n';
                x = 0;
            }
            if(x == d-1 || x == d || x == d+1) cout << "█"; else cout << "░";
            x++;
        }
    }
}
