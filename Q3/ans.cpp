#include <bits/stdc++.h>

using namespace std;

const int N = 10000;

int n, m;
map<string, int> codes;
string intToCode[N];
string intToName[N];
vector<int> adj[N];
vector<double> w[N]; 
bool mark[N];
int par[N];
double dist[N];
int startNode;
int endNode;


void shortestPath(int src) 
{ 
    priority_queue< pair<double, int>, vector <pair<double ,int>> , greater<pair<double, int>> > pq; 
  
    pq.push(make_pair(0, src)); 
    dist[src] = 0; 
  
    while (!pq.empty()) 
    { 
        int u = pq.top().second; 
        pq.pop(); 

        for (int i = 0; i < adj[u].size(); ++i) { 

            int v = adj[u][i]; 
            double weight = w[u][i]; 

            if (dist[v] == -1 || dist[v] > dist[u] + weight) 
            { 
                par[v] = u;
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    } 
} 


int main() {

    codes.clear();
    for (int i = 0; i < N; ++i) {
        adj[i].clear();
        w[i].clear();
        mark[i] = false;
        par[i] = -1;
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
        intToCode[i] = s.substr(0, s.find(" "));
    }

    for (int i = 0; i < m; ++i) {
        string x, y;
        double val;
        cin >> x;
        cin >> y;
        cin >> val;
        adj[codes[x]].push_back(codes[y]);
        w[codes[x]].push_back(val);
        adj[codes[y]].push_back(codes[x]);
        w[codes[y]].push_back(val);
    }

    string temp;
    cin >> temp;
    startNode = codes[temp];
    cin >> temp;
    endNode = codes[temp];

    shortestPath(startNode);

    printf("%.2lf\n", dist[endNode]);
    if (dist[endNode] != -1) {
        vector<string> ans;
        while (endNode != -1) {
            ans.push_back(intToCode[endNode]);
            endNode = par[endNode];
        }
        for (int i = ans.size() - 1; i >= 0; --i) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }

}
