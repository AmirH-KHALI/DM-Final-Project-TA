#include <bits/stdc++.h>
#include <fstream>

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
double X[N];
double Y[N];
int startNode;
int endNode;

double getH (int i, int j) {
    double deltaX = X[i] - X[j];
    double deltaY = Y[i] - Y[j];
    return sqrt(deltaX * deltaX + deltaY * deltaY);
}

void shortestPath(int src, int trg) 
{ 
    priority_queue< pair<double, int>, vector <pair<double ,int>> , greater<pair<double, int>> > pq; 
  
    pq.push(make_pair(0, src)); 
    dist[src] = 0; 
  
    while (!pq.empty()) 
    { 
        int u = pq.top().second; 
        pq.pop(); 

        if (u == trg)
            return;

        for (int i = 0; i < adj[u].size(); ++i) { 

            int v = adj[u][i]; 
            double weight = w[u][i]; 

            if (dist[v] == -1 || dist[v] > dist[u] + weight) 
            { 
                par[v] = u;
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v] + getH(v, trg), v)); 
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

    //cout << n << ' ' << m << '\n' << "*****" << '\n';

    for (int i = 0; i < n; ++i) {
        string code;
        string name;
        cin >> code;
        cin >> X[i];
        cin >> Y[i];
        getline(cin, name);
        codes[code] = i;
        intToName[i] = name;
        intToCode[i] = code;
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

    shortestPath(startNode, endNode);

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