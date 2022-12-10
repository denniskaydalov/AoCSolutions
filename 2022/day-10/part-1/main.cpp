#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    freopen("aoc.in", "r", stdin);
    freopen("aoc.out", "w", stdout);

    string s;
    int t, x { }, a { }, d { 1 };
    while(cin >> s) {
        if(s != "noop") {
            cin >> t;
            x++;
            if(x == 20 || x == 60 || x == 100 || x == 140 || x == 180 || x == 220) a += x * d; 
            x++;
            if(x == 20 || x == 60 || x == 100 || x == 140 || x == 180 || x == 220) a += x * d;
            d += t;
        }
        else {
            x++;
            if(x == 20 || x == 60 || x == 100 || x == 140 || x == 180 || x == 220) a += x * d;
        }
    }
    cout << a;
}
