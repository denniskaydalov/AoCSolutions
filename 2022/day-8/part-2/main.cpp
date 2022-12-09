#include <bits/stdc++.h>
#define ll long long

using namespace std;

int check_right(int i, int j);
int check_left(int i, int j);
int check_up(int i, int j);
int check_down(int i, int j);

vector<string> h;
string s;
int a { };
int main() {
    freopen("aoc.in", "r", stdin);
    freopen("aoc.out", "w", stdout);

    while(cin >> s) {
        h.push_back(s);
    }
    for(int i { }; i < h.size(); ++i) {
        for(int j { }; j < h[0].size(); ++j) {
            int v = check_right(i, j);
            v *= check_left(i, j);
            v *= check_up(i, j);
            v *= check_down(i, j);
            a = max(a, v);
        }
    }
    cout << a;
}

int check_right(int i, int j) {
    int m { }, v { }, k { j + 1 };
    for(; k < h[0].size(); ++k) {
        m = max(m, h[i][k] - '0');
        if(h[i][j] - '0' > m) v++;
        else break;
    }
    if(k != h[0].size()) v++;
    return v;
}

int check_left(int i, int j) {
    int m { }, v { }, k { j - 1 };
    for(; ~k; --k) {
        m = max(m, h[i][k] - '0');
        if(h[i][j] - '0' > m) v++;
        else break;
    }
    if(k != -1) v++;
    return v;
}

int check_up(int i, int j) {
    int m { }, v { }, k { i + 1 };
    for(; k < h.size(); ++k) {
        m = max(m, h[k][j] - '0');
        if(h[i][j] - '0' > m) v++;
        else break;
    }
    if(k != h.size()) v++;
    return v;
}

int check_down(int i, int j) {
    int m { }, v { }, k { i - 1 };
    for(; ~k; --k) {
        m = max(m, h[k][j] - '0');
        if(h[i][j] - '0' > m) v++;
        else break;
    }
    if(k != -1) v++;
    return v;
}
