#include <functional>
#include <iostream>
#include <limits>
#include <memory>
#include <queue>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

struct Input {
    Input() = default;

    int from, to, n;
    std::vector<pair<int, int>> roads;
    unordered_map<int, std::vector<std::pair<int, int>>> adj;
};
using InputPtr = std::shared_ptr<Input>;
using iii = std::tuple<int, int, int>;

ostream& operator<<(ostream& os, const Input& input) {
    os << input.from << "," << input.to << "," << input.n << endl;
    for (const auto& r: input.roads) {
        os << (&r == &(*input.roads.begin()) ? "" : ",") << r.first << ":" << r.second;
    }
    return os;
}

void calculateDrived(const InputPtr &input) {
    for (const auto &road : input->roads) {
        input->adj[road.first].emplace_back(road.second, 0);
        input->adj[road.second].emplace_back(road.first, 1);
    }
}

InputPtr getMockInput() {
    InputPtr input = std::make_shared<Input>();
    int mode = 3;
    if (mode == 1) {
        input->from = 1;
        input->to = 3;
        input->n = 3;
        input->roads = {{1, 2}, {3, 2}};
    } else if (mode == 2) {
        input->from = 1;
        input->to = 3;
        input->n = 3;
        input->roads = {{1, 2}, {2, 3}, {3, 1}};
    } else if (mode == 3) {
        input->from = 1;
        input->to = 4;
        input->n = 4;
        input->roads = {{1, 2}, {3, 2}, {3, 4}};
    }

    calculateDrived(input);
    return input;
}

InputPtr getInput() {
    InputPtr input = std::make_shared<Input>();

    int m;
    std::cin >> input->n >> m;

    int from, to;
    for (int i = 0; i < m; i++) {
        std::cin >> from >> to;
        // input->roads.emplace_back(from, to);
        input->adj[from].emplace_back(to, 0);
        input->adj[to].emplace_back(from, 1);
    }
    std::cin >> input->from >> input->to;

    return input;
}

ostream &operator<<(ostream &os, const deque<iii> &pq) {
    for (const auto &item : pq) {
        os << (&item == &(*pq.begin()) ? "" : ",") << std::get<0>(item) << ":"
           << std::get<1>(item) << ":" << std::get<2>(item);
    }
    return os;
}

int main() {
    InputPtr input = getInput();
    // InputPtr input = getMockInput();
    // std::cout << *input << endl << endl;
    int n = input->n;
    vector<vector<int>> d(2, vector<int>(n+1, std::numeric_limits<int>::max()));
    d[0][input->from] = 0;
    d[1][input->from] = 0;

    std::set<iii> pq;
    pq.emplace(0, 1, input->from);
    pq.emplace(0, 0, input->from);

    int result;
    while (not pq.empty()) {
        // std::cout << pq << std::endl;
        int dist, isDown, city;
        std::tie(dist, isDown, city) = *pq.begin();
        pq.erase(pq.begin());
        if (city == input->to) {
            result = dist;
            break;
        }
        for (const auto &next : input->adj[city]) {
            int nextCity = next.first;
            int nextIsDown = next.second;
            int w = isDown == next.second ? 0 : 1;
            if (dist + w < d[nextIsDown][nextCity]) {
                pq.erase(std::make_tuple(d[nextIsDown][nextCity], nextIsDown, nextCity));
                d[nextIsDown][nextCity] = dist + w;
                pq.insert(std::make_tuple(d[nextIsDown][nextCity], nextIsDown, nextCity));
            }
        }
    }

    cout << result << endl;

    return 0;
}