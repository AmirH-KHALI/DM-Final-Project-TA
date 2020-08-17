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

    for (int k = 0; k < 45; ++k) {

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

        //open input file
        ifstream test_in;
        string inputFileName = "inputs/input";
        stringstream ss;
        ss<<k+1;
        string ss1;
        ss>>ss1;
        inputFileName += ss1;
        inputFileName += ".txt";
        test_in.open(inputFileName);

        test_in >> n;
        test_in >> m;

        //cout << n << ' ' << m << '\n' << "*****" << '\n';

        string s;
        getline(test_in, s);

        for (int i = 0; i < n; ++i) {
            getline(test_in, s);
            codes[s.substr(0, s.find(" "))] = i;
            intToName[i] = s.substr(s.find(" ") + 1, s.size() - s.find(" ") - 2);
            intToCode[i] = s.substr(0, s.find(" "));
            //cout << i << ' ' << s.substr(0, s.find(" ")) << '\n';
        }

        //cout << "*****" << '\n';

        for (int i = 0; i < m; ++i) {
            string x, y;
            double val;
            test_in >> x;
            test_in >> y;
            test_in >> val;
            adj[codes[x]].push_back(codes[y]);
            w[codes[x]].push_back(val);
            adj[codes[y]].push_back(codes[x]);
            w[codes[y]].push_back(val);
        }

        string temp;
        test_in >> temp;
        startNode = codes[temp];
        test_in >> temp;
        endNode = codes[temp];

        shortestPath(startNode);

        ofstream test_out;
        string outputFileName = "outputs/output";
        ss.clear();
        ss<<k+1;
        ss>>ss1;
        outputFileName += ss1;
        outputFileName += ".txt";
        cout << outputFileName << '\n';
        test_out.open(outputFileName);

        cout << "****\n";
        test_out << dist[endNode] << endl;
        cout << dist[endNode] << '\n';
        if (dist[endNode] != -1) {
            vector<string> ans;
            while (endNode != -1) {
                ans.push_back(intToCode[endNode]);
                endNode = par[endNode];
            }
            for (int i = ans.size() - 1; i >= 0; --i) {
                test_out << ans[i] << ' ';
                cout << ans[i] << ' ';
            }
            test_out << endl;
        }   
        test_out.close();
        test_in.close();
    }
    //
	// ifstream test_in("inputs/");    /* This stream reads from test's input file   */
	// ifstream test_out(argv[2]);   /* This stream reads from test's output file  */
	// ifstream user_out(argv[3]);   /* This stream reads from user's output file  */
    //
	// /* Your code here */
	// /* If user's output is correct, return 0, otherwise return 1       */
	// /* e.g.: Here the problem is: read n numbers and print their sum:  */
    //
	// int sum, user_output;
	// user_out >> user_output;
    //
	// if ( test_out.good() ) // if test's output file exists
	// {
	// 	test_out >> sum;
	// }
	// else
	// {
	// 	int n, a;
	// 	sum=0;
	// 	test_in >> n;
	// 	for (int i=0 ; i<n ; i++){
	// 		test_in >> a;
	// 		sum += a;
	// 	}
	// }
    //
	// if (sum == user_output)
	// 	return 0;
	// else
	// 	return 1;

}
