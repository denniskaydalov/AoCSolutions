#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	freopen("6mb.in", "r", stdin);
	freopen("aoc.out", "w", stdout);

    int x, y, z;
    string s;
    getline(cin, s);
    vector<char> c[static_cast<int>((s.length()+1)/4)];
    while(!isdigit(s[1])) {
        for(int i { }; i < (s.length()+1)/4; ++i) {
            if(s[i*4+1] != ' ') c[i].insert(c[i].begin(), s[i*4+1]);
        }
        getline(cin, s);
    }
    while(cin >> s >> x >> s >> y >> s >> z) {
        vector<char> t;
        for(int i { }; i < x; ++i) {
            t.insert(t.begin(), c[y-1].back());
            c[y-1].pop_back();
        }
        c[z-1].insert(c[z-1].end(), t.begin(), t.end());
    }
    for(auto x : c) cout << x.back();
}
