#include <bits/stdc++.h>
#include <climits>
#define ll long long

using namespace std;

enum FileType {
    File,
    Directory
};

class Node {
public:
    string name;
    ll size;
    FileType fileType;
    vector<Node*> items;
    Node* parent;

    Node(string directory, ll size, FileType fileType, Node* parent) {
        name = directory;
        this->size = size;
        this->fileType = fileType;
        this->parent = parent;
    }

    ll getSize() {
        if(this->fileType == File) return size;
        else {
            ll sum { };
            for(auto item : items)
                sum += item->getSize();
            this->size = sum;
            return sum;
        }
    }

    ll sizeMin(ll sizeParam) {
        ll minSize { LONG_LONG_MAX };
        for(auto item : items){
            if(item->fileType == Directory){
                if(item->size >= sizeParam)
                    minSize = min(item->size, minSize);
                ll recursionMin { item->sizeMin(sizeParam) };
                if(recursionMin >= sizeParam)
                    minSize = min(recursionMin, minSize);
            }
        }
        return minSize;
    }

    void addItem(Node* item) {
        items.push_back(item);
    }
};

int main() {
    freopen("aoc.in", "r", stdin);
    freopen("aoc.out", "w", stdout);

    Node* root = new Node("/", 0, Directory, nullptr);
    Node* currentDir = root;
    bool skip { };
    string s;
    getline(cin, s);
    while(skip || getline(cin, s)) {
        skip = false;
        if(s[2] == 'c') {
            if(s[5] == '.' && s[6] == '.') currentDir = currentDir->parent;
            else {
                Node* newDir = new Node((currentDir->name=="/"?"":currentDir->name)+"/"+s.substr(5), 0, Directory, currentDir);
                currentDir->addItem(newDir);
                currentDir = newDir;
            }
        }
        else {
            while(getline(cin, s) && s[0] != '$') {
                if(s[0] != 'd') currentDir->addItem(new Node((currentDir->name=="/"?"":currentDir->name)+'/'+s.substr(s.find(' ') + 1), stoll(s.substr(0, s.find(' '))), File, currentDir));
                skip = true;
            }
        }
    }

    cout << root->sizeMin(30000000 - (70000000 - root->getSize()));
}
