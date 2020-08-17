#include <bits/stdc++.h>
#include <fstream>

using namespace std;

const int N = 10000;

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

        //cout << f << " ";

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

    for (int k = 0; k < 40; ++k) {

        codes.clear();
        for (int i = 0; i < N; ++i) {
            adj[i].clear();
            mark[i] = false;
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
            //cout << i << ' ' << s.substr(0, s.find(" ")) << '\n';
        }

        //cout << "*****" << '\n';

        for (int i = 0; i < m; ++i) {
            string x, y;
            test_in >> x;
            test_in >> y;
            adj[codes[x]].push_back(codes[y]);
            adj[codes[y]].push_back(codes[x]);
        }

        string temp;
        test_in >> temp;
        startNode = codes[temp];

        bfs(startNode);

        ofstream test_out;
        string outputFileName = "outputs/output";
        ss.clear();
        ss<<k+1;
        ss>>ss1;
        outputFileName += ss1;
        outputFileName += ".txt";
        cout << outputFileName << '\n';
        test_out.open(outputFileName);

        for (int i = 0; i < n; ++i) {
            test_out << intToName[i] << ' ' << dist[i] << endl;
        }


        // test_out.close();
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
