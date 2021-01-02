#include <iostream>
#include <limits>
#include <memory>
#include <queue>
#include <utility>
#include <vector>

#ifndef DEBUG
// #define DEBUG
#endif

#ifdef DEBUG
#define pp(x) cout << x << endl
#else
#define pp(x)                                                                  \
    do {                                                                       \
    } while (0)
#endif

using namespace std;
using pii = pair<int, int>;

struct Input {
    Input() = default;
    int time;
    int cells;
    int exit;
    vector<vector<pii>> adj;
};
using InputPtr = std::shared_ptr<Input>;

ostream &operator<<(ostream &os, const Input &input) {
    os << input.cells << " " << input.exit << " " << input.time << endl;
    for (int i = 0; i < input.adj.size(); i++) {
        os << i << ": ";
        for (const auto &p : input.adj[i]) {
            os << (&p == &(*input.adj[i].begin()) ? "" : ",") << p.first << ":"
               << p.second;
        }
        os << endl;
    }
    return os;
}

InputPtr getMockInput() {
    InputPtr ptr = std::make_shared<Input>();
    vector<vector<int>> edges;
    
    int test = 2;
    if (test == 1) {
        ptr->cells = 4;
        ptr->exit = 2;
        ptr->time = 1;
        edges = {{1, 2, 1}, {1, 3, 1}, {2, 1, 1}, {2, 4, 1},
                 {3, 1, 1}, {3, 4, 1}, {4, 2, 1}, {4, 3, 1}};
    } else if (test == 2) {
        ptr->cells = 5;
        ptr->exit = 5;
        ptr->time = 2;
        edges = {{1, 5, 1}, {1, 2, 1}, {2, 1, 1},
                 {2, 3, 1}, {3, 4, 1}, {4, 5, 1}};
    }

    ptr->adj.assign(ptr->cells + 1, vector<pii>());
    for (const auto &e : edges) {
        int from = e.at(0), to = e.at(1), cost = e.at(2);
        ptr->adj.at(to).emplace_back(from, cost);
    }

    return ptr;
}

InputPtr getInput() {
    InputPtr ptr = std::make_shared<Input>();
    std::cin >> ptr->cells >> ptr->exit >> ptr->time;
    int m, from, to, cost;
    std::cin >> m;
    ptr->adj.assign(ptr->cells + 1, vector<pii>());
    for (int i = 0; i < m; i++) {
        std::cin >> from >> to >> cost;
        ptr->adj.at(to).emplace_back(from, cost);
    }

    return ptr;
}

int solve(const InputPtr &ptr) {
    pp("Info " << *ptr);
    int answer = 0;
    int n = ptr->cells;

    vector<int> d(n + 1, std::numeric_limits<int>::max());
    d[ptr->exit] = 0;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    pq.emplace(0, ptr->exit);

    while (not pq.empty()) {
        auto tmp = pq.top();
        int dist = tmp.first, node = tmp.second;
        pq.pop();
        pp("Pop out node " << node << " dist " << dist);
        if (dist != d[node]) {
            continue;
        }
        if (dist > ptr->time) {
            break;
        }
        answer++;
        for (const auto &next : ptr->adj[node]) {
            int nextNode = next.first, dd = next.second;
            pp("Next node " << nextNode);
            if (d[nextNode] > d[node] + dd) {
                d[nextNode] = d[node] + dd;
                pp("Insert node " << nextNode << " dist " << d[nextNode]);
                pq.emplace(d[nextNode], nextNode);
            }
        }
    }

    return answer;
}

int main(int argc, char *argv[]) {
#ifdef DEBUG
    InputPtr ptr = getMockInput();
#else
    InputPtr ptr = getInput();
#endif
    cout << solve(ptr) << endl;

    return 0;
}