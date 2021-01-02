#include <deque>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#ifndef test
// #define test
#endif

#ifdef test
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
    int n;
    vector<vector<int>> adj;
    vector<pii> solidiers;
};
using InputPtr = std::shared_ptr<Input>;

ostream &operator<<(ostream &os, const Input &input) {
    os << input.n << endl;
    for (int i = 0; i < input.adj.size(); i++) {
        os << i << ":";
        for (const auto &p : input.adj[i]) {
            os << (&p == &(*input.adj[i].begin()) ? "" : ",") << p;
        }
        os << endl;
    }
    for (const auto &p : input.solidiers) {
        os << (&p == &(*input.solidiers.begin()) ? "" : ",") << p.first << ":"
           << p.second;
    }
    return os;
}

ostream &operator<<(ostream &os, const vector<InputPtr> &inputs) {
    for (const auto &ptr : inputs) {
        cout << *ptr << endl;
    }
    return os;
}

ostream &operator<<(ostream &os, const unordered_set<int> &s) {
    for (const auto &x : s) {
        cout << (&x == &(*s.begin()) ? "" : ",") << x;
    }
    return os;
}

vector<InputPtr> getMockInput() {
    InputPtr ptr = std::make_shared<Input>();
    vector<pii> adj;

    int mode = 4;
    if (mode == 1) {
        ptr->n = 3;
        adj = {{1, 2}, {2, 3}, {1, 2}};
        ptr->solidiers = {{1, 2}, {2, 0}};
    } else if (mode == 2) {
        ptr->n = 4;
        adj = {{1, 4}, {1, 2}, {1, 3}, {4, 2}, {3, 4}};
        ptr->solidiers = {{2, 1}, {3, 0}};
    } else if (mode == 3) {
        ptr->n = 4;
        adj = {{1, 2}, {2, 4}, {4, 3}, {1, 3}};
        ptr->solidiers = {{1, 0}, {3, 2}};
    } else if (mode == 4) {
        ptr->n = 4;
        adj = {{1, 2}, {1, 3}, {2, 3}, {3, 4}};
        ptr->solidiers = {{1, 2}};
    }

    //
    ptr->adj.assign(ptr->n + 1, vector<int>());
    for (const pii &p : adj) {
        ptr->adj[p.first].push_back(p.second);
        ptr->adj[p.second].push_back(p.first);
    }

    return {ptr};
}

vector<InputPtr> getInput() {
    vector<InputPtr> result;
    int t, n, r, m, from, to, k, s;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        InputPtr ptr = std::make_shared<Input>();
        std::cin >> n >> r >> m;
        ptr->n = n;
        ptr->adj.assign(n + 1, vector<int>());
        for (int j = 0; j < r; j++) {
            std::cin >> from >> to;
            ptr->adj.at(from).push_back(to);
            ptr->adj.at(to).push_back(from);
        }
        for (int j = 0; j < m; j++) {
            std::cin >> k >> s;
            ptr->solidiers.emplace_back(k, s);
        }
        result.push_back(ptr);
    }
    return result;
}

int main(int argc, char *argv[]) {
#ifdef test
    auto inputs = getMockInput();
#else
    auto inputs = getInput();
#endif

    pp(inputs);
    int count = 0;
    for (auto ptr : inputs) {
        bool valid = true;
        unordered_set<int> visited;
        for (const pii &solidier : ptr->solidiers) {
            deque<int> que;
            unordered_set<int> tmpVisited;
            int strength = solidier.second;
            pp("start working on " << solidier.first << " " << solidier.second);
            que.push_back(solidier.first);
            while (not que.empty() and strength >= 0) {
                int s = que.size();
                for (int i = 0; i < s; i++) {
                    int curr = que.front();
                    pp("Inside " << curr << " " << strength);
                    que.pop_front();
                    tmpVisited.insert(curr);
                    if (visited.find(curr) != visited.end()) {
                        valid = false;
                        pp("fail at " << curr);
                        break;
                    }
                    for (int next : ptr->adj.at(curr)) {
                        if (tmpVisited.find(next) == tmpVisited.end())
                            que.push_back(next);
                    }
                }
                if (not valid)
                    break;
                strength--;
            }
            if (not valid)
                break;
            visited.insert(tmpVisited.begin(), tmpVisited.end());
            pp("tmp visited " << tmpVisited);
        }
        // cout << ++count << " " << valid << " " << visited << endl;
        cout << ((valid and visited.size() == ptr->n) ? "Yes" : "No") << endl;
    }
    return 0;
}