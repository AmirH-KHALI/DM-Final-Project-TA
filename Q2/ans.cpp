#include <bits/stdc++.h>

using namespace std;

const int N = 100000;

int n, m;
map<string, int> codes;
string intToCode[N];
string intToName[N];
vector<int> adj[N];
bool mark[N];
int dist[N];
int startNode;


void bfs(int u) {
    queue<int> q;

    q.push(u);
    mark[u] = true;
    dist[u] = 0;

    while (!q.empty()) {

        int f = q.front();
        q.pop();

        for (auto i = adj[f].begin(); i != adj[f].end(); i++) {
            if (!mark[*i]) {
                dist[*i] = dist[f] + 1;
                q.push(*i);
                mark[*i] = true;
            }
        }
    }
}


int main() {

    codes.clear();
    for (int i = 0; i < N; ++i) {
        adj[i].clear();
        mark[i] = false;
        intToCode[i] = "";
        intToName[i] = "";
        dist[i] = -1;
    }

    cin >> n;
    cin >> m;

    string s;
    getline(cin, s);

    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        codes[s.substr(0, s.find(" "))] = i;
        intToName[i] = s.substr(s.find(" ") + 1, s.size() - s.find(" ") - 2);
    }


    for (int i = 0; i < m; ++i) {
        string x, y;
        cin >> x;
        cin >> y;
        adj[codes[x]].push_back(codes[y]);
        adj[codes[y]].push_back(codes[x]);
    }

    string temp;
    cin >> temp;
    startNode = codes[temp];

    bfs(startNode);

    for (int i = 0; i < n; ++i) {
        cout << intToName[i] << ' ' << dist[i] << endl;
    }

}
