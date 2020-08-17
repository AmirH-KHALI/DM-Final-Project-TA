#include <bits/stdc++.h>

using namespace std;

const int N = 10000;

int n, m;
map<string, int> codes;
string intToCode[N];
vector<int> adj[N];
bool mark[N];


void dfs (int x) {
    mark[x] = true;
    for (int i = 0; i < adj[x].size(); ++i) {
        int child = adj[x][i];
        if (!mark[child]) {
            dfs(child);
        }
    }
}


int main() {


    codes.clear();
    for (int i = 0; i < N; ++i) {
        adj[i].clear();
        mark[i] = false;
        intToCode[i] = "";
    }

    cin >> n;
    cin >> m;

    string s;
    getline(cin, s);

    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        codes[s.substr(0, s.find(" "))] = i;
        //cout << i << ' ' << s.substr(0, s.find(" ")) << '\n';
    }

    //cout << "*****" << '\n';

    for (int i = 0; i < m; ++i) {
        string x, y;
        cin >> x;
        cin >> y;
        adj[codes[x]].push_back(codes[y]);
        adj[codes[y]].push_back(codes[x]);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!mark[i]) {
            dfs(i);
            ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}
