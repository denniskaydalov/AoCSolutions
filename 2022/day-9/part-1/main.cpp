#include <bits/stdc++.h>
#define ll long long

using namespace std;

void follow();

char c;
int a;
set<pair<int, int>> l;
pair<int, int> p { 0, 0 }, f { 0, 0 };
int main() {
    freopen("aoc.in", "r", stdin);
    freopen("aoc.out", "w", stdout);

    while(cin >> c >> a) {
        while(a--) {
            //cout << f.first << ' ' << f.second << '\n';
            switch(c) {
                case 'R':
                    p.first++;
                    break;
                case 'L':
                    p.first--;
                    break;
                case 'U':
                    p.second++;
                    break;
                case 'D':
                    p.second--;
                    break;
            }
            follow();
            l.insert(f);
        }
    }

    //for(auto x : l) cout << x.first << ' ' << x.second << '\n';
    cout << l.size();
}

void follow() {
    //if(p.first != f.first && p.second != f.second && abs(p.first - f.first) > 1 && abs(p.second - f.second) > 1) {
    if(abs(p.first - f.first) == 1 && abs(p.second - f.second) == 1) return;
    if(abs(p.first - f.first) == 2 || abs(p.second - f.second) == 2) {
    switch(c) {
        case 'R':
            f = { p.first - 1, p.second };
            break;
        case 'L':
            f = { p.first + 1, p.second };
            break;
        case 'U':
            f = { p.first, p.second - 1 };
            break;
        case 'D':
            f = { p.first, p.second + 1 };
            break;

    }
    }
    //}
    //if(abs(p.first-f.first) > 1) {

    //}
}
