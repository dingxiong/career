#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

/**
 *  I learn a lesson from this problem:
 *   Recursion with reference arguments is very slow. Make these arguments as global variables.
 */

#ifdef DEBUG
#define pp(x) cout << x << endl
#else
#define pp(x)                                                                  \
    do {                                                                       \
    } while (0)
#endif

using namespace std;

struct Input {
    Input() = default;

    int n;
    unordered_map<int, vector<int>> adj;
};

ostream &operator<<(ostream &os, const vector<int> &v) {
    for (const auto &i : v) {
        os << (&i == &(*v.begin()) ? "" : ",") << i;
    }
    return os;
}

ostream &operator<<(ostream &os, const unordered_map<int, int> &v) {
    for (const auto &i : v) {
        os << (&i == &(*v.begin()) ? "" : ",") << i.first << ":" << i.second;
    }
    return os;
}

template <class T>
Input getInput(T &ts) {
    Input input{};

    int n, m, from, to;
    ts >> n >> m;
    input.n = n;
    for (int i = 0; i < m; i++) {
        ts >> from >> to;
        input.adj[from].push_back(to);
        input.adj[to].push_back(from);
    }

    return input;
}

Input getMockInput() {
    Input input;
    vector<pair<int, int>> edges;

    int test = 4;
    if (test == 1) {
        input.n = 5;
        edges = {{1, 3}, {1, 2}, {5, 3}, {1, 5}, {2, 4}, {4, 5}};
    } else if (test == 2) {
        input.n = 100000;
        edges = {{99998, 99999}, {99999, 100000}, {100000, 99998}};
    } else if (test == 3) {
        input.n = 5;
        edges = {{1, 2}, {2, 3}, {3, 1}, {3, 4}, {5, 4}, {3, 5}};
    } else if (test == 4) {
        ifstream f("test_input.txt");
        return getInput(f);
    }

    //
    for (const auto &p : edges) {
        int from = p.first, to = p.second;
        input.adj[from].push_back(to);
        input.adj[to].push_back(from);
    }

    return input;
}

int cycleStart = -1;
int cycleEnd = -1;
unordered_map<int, vector<int>> adj;
unordered_map<int, int32_t> parents;
unordered_map<int, int> color;

void dfs(int node, int parent) {
    // pp("Node : " << node <<  " " << parent);
    color[node] = 1;
    for (int next : adj.at(node)) {
        if (next == parent)
            continue;
        if (color[next] == 0) {
            parents[next] = node;
            dfs(next, node);
            if (cycleStart != -1)
                return;
        } else if (color[next] == 1) {
            cycleStart = next;
            cycleEnd = node;
            pp("Found: " << cycleStart << " " << cycleEnd);
        }
    }
}

int main(int argc, char *argv[]) {
#ifdef DEBUG
    Input input = getMockInput();
#else
    Input input = getInput(std::cin);
#endif
    int n = input.n;
    for (const auto &kv : input.adj) {
        parents[kv.first] = -1;
        color[kv.first] = 0;
    }
    adj = input.adj;
    for (const auto &kv : input.adj) {
        int node = kv.first;
        if (color[node] == 0) {
            dfs(node, parents[node]);
            if (cycleStart != -1)
                break;
        }
    }
    // pp("parents: " << parents);
    // pp("color: " << color);
    pp("start " << cycleStart << " end " << cycleEnd);
    if (cycleStart == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> cycle;
        for (int i = cycleEnd; i != cycleStart; i = parents[i]) {
            cycle.push_back(i);
        }
        cycle.push_back(cycleStart);
        cycle.push_back(cycleEnd);
        std::reverse(cycle.begin(), cycle.end());
        cout << cycle.size() << endl;
        for (int i : cycle)
            cout << (&i == &(*cycle.begin()) ? "" : " ") << i;
    }

    return 0;
}