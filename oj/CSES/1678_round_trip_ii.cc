/**
 * g++ <source_file> -std=c++14 -O3 -DDEBUG=1
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// ----------------
int n;
int cycleFrom = -1;
int cycleEnd = -1;
vector<vector<int>> adj;
vector<int> parents, color;

// ----------------
template<class T>
void getInputImpl(T& ts) {
    int m, c1, c2;
    ts >> n >> m;
    adj.assign(n+1, vector<int>());
    for (int i = 0; i < m; i++) {
        ts >> c1 >> c2;
        adj[c1].push_back(c2);
    }
    //
    parents.assign(n+1, -1);
    color.assign(n+1, 0);
}

void getInput() {
#ifdef DEBUG
    ifstream f("test_input.txt");
    getInputImpl(f);
#else
    getInputImpl(std::cin);
#endif
}

bool dfs(int node) {
    color[node] = 1;
    for (int next : adj[node]) {
        if (color[next] == 1) {
            cycleEnd = node;
            cycleFrom = next;
            return true;
        } else if (color[next] == 0) {
            parents[next] = node;
            if (dfs(next))
                return true;
        }
    }
    color[node] = 2;
    return false;
}

int main(int argc, char* argv[]) {
    getInput();
    for (int i = 0; i < n + 1; i++) {
        if (color[i] == 0 and dfs(i))
            break;
    }
    if (cycleFrom == -1) {
        cout << "IMPOSSIBLE" << endl;
    }  else {
        vector<int> cycle;
        for (int i =  cycleEnd; i != cycleFrom; i = parents[i]) {
            cycle.push_back(i);
        }
        cycle.push_back(cycleFrom);
        cycle.push_back(cycleEnd);
        std::reverse(cycle.begin(), cycle.end());
        cout << cycle.size() << endl;
        for (const int& i : cycle) {
            cout << (&i == &(*cycle.begin()) ? "" : " ") << i;
        }
        cout << endl;
    }

    return 0;
}