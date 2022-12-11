#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Monkey {
public:
    vector<ll> items;
    char operationSymbol;
    ll operationNumber;
    ll test;
    ll resultTrue;
    ll resultFalse;
    ll throws { };
};

vector<Monkey*> monkeys;

void input() {
    Monkey* current = new Monkey();
    monkeys.push_back(current);
    string s;
    char c;
    ll a;
    cin >> s >> s;
    while((cin >> s, s)[0] != 'O') current->items.push_back(stoll(s.substr(0, s.find(','))));
    cin >> s >> s >> s >> c >> s;
    if(s != "old") {
        current->operationSymbol = c;
        current->operationNumber = stoll(s);
    }
    else current->operationSymbol = '^';
    cin >> s >> s >> s >> a;
    current->test = a;
    cin >> s >> s >> s >> s >> s >> a;
    current->resultTrue = a;
    cin >> s >> s >> s >> s >> s >> a;
    current->resultFalse = a;
}
int main() {
    freopen("aoc.in", "r", stdin);
    freopen("aoc.out", "w", stdout);

    string s;
    ll x { };
    vector<ll> throwsMax;
    while(cin >> s >> s) input();
    while(x != 20) {
        for(auto monkey : monkeys) {
            for(auto item : monkey->items) {
                switch(monkey->operationSymbol) {
                    case '+':
                        item += monkey->operationNumber;
                        break;
                    case '*':
                        item *= monkey->operationNumber;
                        break;
                    case '^':
                        item *= item;
                        break;
                }
                item /= 3;
                if(!(item % monkey->test)) {
                    monkeys[monkey->resultTrue]->items.push_back(item);
                }
                else {
                    monkeys[monkey->resultFalse]->items.push_back(item);
                }
                monkey->throws++;
            }
            monkey->items.clear();
        }
        x++;
        if(x == 20) break;
    }
    for(auto monkey : monkeys) throwsMax.push_back(monkey->throws);
    sort(throwsMax.begin(), throwsMax.end());
    cout << throwsMax[throwsMax.size() - 1] * throwsMax[throwsMax.size() - 2];
}
