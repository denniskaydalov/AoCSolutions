#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    freopen("aoc.in", "r", stdin);
    freopen("aoc.out", "w", stdout);

    vector<string> h;
    string s;
    int a { };
    vector<vector<bool>> b;
    while(cin >> s) {
        h.push_back(s);
        b.push_back(vector<bool>(s.length()));
    }
    for(int i { }; i < h.size(); ++i) {
        int m { };
        for(int j { }; j < h[i].length(); ++j) {
            if((h[i][j] - '0' > m || (!(h[i][j] - '0') && (!i || !j || i == h[i].length()-1 || j == h.size()-1))) && !b[i][j]) {
                a++;
                b[i][j] = true;
            }
            m = max(h[i][j] - '0', m);
        }
    }
    for(int i { }; i < h.size(); ++i) {
        int m { };
        for(int j { static_cast<int>(h[i].length() - 1) }; ~j; --j) {
            if(h[i][j] - '0' > m && !b[i][j]) {
                a++;
                b[i][j] = true;
            }
            m = max(h[i][j] - '0', m);
        }
    }
    for(int i { }; i < h[0].length(); ++i) {
        int m { };
        for(int j { }; j < h.size(); ++j) {
            if(h[j][i] - '0' > m && !b[j][i]) {
                a++;
                b[j][i] = true;
            }
            m = max(h[j][i] - '0', m);
        }
    }
    for(int i { }; i < h[0].length(); ++i) {
        int m { };
        for(int j { static_cast<int>(h.size() - 1)}; ~j; --j) {
            if(h[j][i] - '0' > m && !b[j][i]) {
                a++;
                b[j][i] = true;
            }
            m = max(h[j][i] - '0', m);
        }
    }
    cout << a;
}
