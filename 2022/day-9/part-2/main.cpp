#include <bits/stdc++.h>
#define ll long long

using namespace std;

void follow();
void draw();

char c;
int a;
set<pair<int, int>> l;
pair<int, int> f[10] { };
int main() {
    freopen("aoc.in", "r", stdin);
    freopen("aoc.out", "w", stdout);

    while(cin >> c >> a) {
        while(a--) {
            switch(c) {
                case 'R':
                    f[0].first++;
                    break;
                case 'L':
                    f[0].first--;
                    break;
                case 'U':
                    f[0].second++;
                    break;
                case 'D':
                    f[0].second--;
                    break;
            }
            follow();
            l.insert(f[9]);
        }
    }
    cout << l.size();
}

void follow() {
    for(int i { 1 }; i <= 9; ++i) {
        if(abs(f[i-1].first - f[i].first) <= 1 && abs(f[i-1].second - f[i].second) <= 1) return;
        else {
            if((f[i-1].first - f[i].first == 2 && f[i-1].second - f[i].second > 0) || (f[i-1].second - f[i].second == 2 && f[i-1].first - f[i].first > 0)) {
                f[i].first++;
                f[i].second++;
            }
            else if((f[i-1].first - f[i].first == -2 && f[i-1].second - f[i].second > 0) || (f[i-1].second - f[i].second == 2 && f[i-1].first - f[i].first < 0)) {
                f[i].first--;
                f[i].second++;
            }
            else if((f[i-1].second - f[i].second == -2 && f[i-1].first - f[i].first > 0) || (f[i-1].first - f[i].first == 2 && f[i-1].second - f[i].second < 0)) { 
                f[i].first++;
                f[i].second--;
            }
            else if((f[i-1].second - f[i].second == -2 && f[i-1].first - f[i].first < 0) || (f[i-1].first - f[i].first == -2 && f[i-1].second - f[i].second < 0)) {  
                f[i].first--;
                f[i].second--;
            
            }
            
            else if(f[i-1].first - f[i].first == 2) f[i].first++;
            else if(f[i-1].first - f[i].first == -2) f[i].first--;
            else if(f[i-1].second - f[i].second == 2) f[i].second++;
            else if(f[i-1].second - f[i].second == -2) f[i].second--;
        }
    }
}
