/*
 * tester.cpp
 */

#include <bits/stdc++.h>
#include <fstream>

const int N = 100000;

using namespace std;
int main(int argc, char const *argv[])
{

	ifstream test_in(argv[1]);
	ifstream test_out(argv[2]);
	ifstream user_out(argv[3]);

    // ifstream test_in("in/input1.txt");
	// ifstream test_out("out/output1.txt");
	// ifstream user_out("out/output1.txt");

    int n;
    test_in >> n;
    int dist[N];
    map<string, int> nameToInt;
    bool mark[N];
    for (int i = 0; i < N; ++i) {
        mark[i] = false;
        dist[i] = -1;
    }

    for (int k = 0; k < n; ++k) {
        string s;
        getline(user_out, s);
        istringstream iss(s);
        vector<string> result((istream_iterator<string>(iss)),
                                 istream_iterator<string>());
        string name = "";
        for (int i = 0; i < result.size() - 1; i++) {
            name += result[i];
            if (i < result.size() - 2) name += " ";
        }
        nameToInt[name] = k;
        stringstream geek(result[result.size() - 1]);
        geek >> dist[k];
    }

    for (int k = 0; k < n; ++k) {
        string s;
        if (test_out.peek()!=EOF) {
            getline(test_out, s);
            istringstream iss(s);
            vector<string> result((istream_iterator<string>(iss)),
                                     istream_iterator<string>());
            string name = "";
            for (int i = 0; i < result.size() - 1; i++) {
                name += result[i];
                if (i < result.size() - 2) name += " ";
            }
            int x;
            stringstream geek(result[result.size() - 1]);
            geek >> x;

            if (dist[nameToInt[name]] != x) {
                return 0;
            }
            if (mark[nameToInt[name]]) {
                return 0;
            } else {
                mark[nameToInt[name]] = true;
            }
        } else {
            return 0;
        }
    }

    if (user_out.peek()!=EOF) {return 0;}

    return 1;
}
