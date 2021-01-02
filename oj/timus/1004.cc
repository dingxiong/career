#include <iostream>
#include <memory>
#include <utility>
#include <vector>

using namespace std;
using pii = std::pair<int, int>;

struct Input {
    Input() = default;
    int n;
    vector<vector<pii>> adj;
};
using InputPtr = std::shared_ptr<Input>;

vector<InputPtr> getInput() {
    int n, m, from, to, dist;
    vector<InputPtr> result;
    while (true) {
        std::cin >> n;
        if (n == -1) {
            break;
        }
        InputPtr ptr = std::make_shared<Input>();
        ptr->n = n;
        ptr->adj.assign(n, vector<pii>());
        std::cin >> m;
        for (int i = 0; i < m; i++) {
            std::cin >> from >> to >> dist;
            ptr->adj.at(from).emplace_back(to, dist);
        }
        result.push_back(ptr);
    }
    return result;
}

int main() {
    vector<InputPtr> inputs = getInput();

    return 0;
}