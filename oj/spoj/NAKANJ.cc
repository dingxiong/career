#include <deque>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_set>
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
    vector<pair<pii, pii>> tests;
};
using InputPtr = std::shared_ptr<Input>;

InputPtr getInput() {
    int t;
    string from, to;
    std::cin >> t;
    InputPtr ptr = std::make_shared<Input>();
    for (int i = 0; i < t; i++) {
        std::cin >> from >> to;
        pii loc1(from[0] - 'a', from[1] - '1');
        pii loc2(to[0] - 'a', to[1] - '1');
        ptr->tests.emplace_back(loc1, loc2);
    }
    return ptr;
}

InputPtr getMockInput() {
    InputPtr ptr = std::make_shared<Input>();
    vector<pair<std::string, std::string>> pairs = {
        {"a1", "h8"}, {"a1", "c2"}, {"h8", "c3"}};

    //
    for (const auto &p : pairs) {
        const string &from = p.first;
        const string &to = p.second;
        pii loc1(from[0] - 'a', from[1] - '1');
        pii loc2(to[0] - 'a', to[1] - '1');
        ptr->tests.emplace_back(loc1, loc2);
    }

    return ptr;
}

int dirs[8][2] = {{-1, 2},  {1, 2},  {-2, 1},  {2, 1},
                  {-2, -1}, {2, -1}, {-1, -2}, {1, -2}};

bool valid(int x, int y) { return x >= 0 and x < 8 and y >= 0 and y < 8; }

int dfs(const pii &from, const pii &to) {
    unordered_set<int> visited;
    std::deque<pii> que;
    que.push_back(from);
    int level = 0;
    while (not que.empty()) {
        int s = que.size();
        for (int i = 0; i < s; i++) {
            pii curr = que.front();
            que.pop_front();
            if (curr == to) {
                return level;
            }
            visited.insert(curr.first * 8 + curr.second);
            for (int i = 0; i < 8; i++) {
                int newx = curr.first + dirs[i][0];
                int newy = curr.second + dirs[i][1];
                if (not valid(newx, newy)) {
                    continue;
                }
                if (visited.find(newx * 8 + newy) != visited.end()) {
                    continue;
                }
                que.emplace_back(newx, newy);
            }
        }
        level++;
    }
    return -1;
}

int main(int argc, char *argv[]) {
#ifdef DEBUG
    InputPtr ptr = getMockInput();
#else
    InputPtr ptr = getInput();
#endif
    for (const auto& t : ptr->tests) {
        int steps = dfs(t.first, t.second);
        cout << steps << endl;
    }

    return 0;
}