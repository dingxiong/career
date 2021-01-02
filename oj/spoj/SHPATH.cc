#include <iostream>
#include <limits>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

struct Input {
    Input() = default;
    std::vector<std::string> cities;
    std::unordered_map<std::string, int> cityIndices;
    std::vector<vector<std::pair<int, int>>> costs;
    std::vector<pair<std::string, std::string>> queries;
};

using InputPtr = std::shared_ptr<Input>;

ostream& operator<<(ostream& os, const Input& input) {
    for (const auto& c: input.cities) {
        os << (&c == &(*input.cities.begin()) ? "" : ",") << c;
    }
    os << endl;
    for (const auto& p : input.cityIndices) {
        os << (&p == &(*input.cityIndices.begin()) ? "" : ",") << p.first << ":" << p.second;
    }
    os << endl;
    for (const auto& c : input.costs) {
        for (const auto& p: c) {
            os << (&p == &(*c.begin()) ? "" : ",") << p.first << ":" << p.second;
        }
        os << endl;
    }
    for (const auto& p : input.queries) {
        os << (&p == &(*input.queries.begin()) ? "" : ",") << p.first << ":" << p.second;
    }
    os << endl;
    return os;
}

ostream& operator<<(ostream& os, const std::vector<InputPtr>& v) {
    for (const auto& x : v) {
        os << *x << std::endl;
    }
    return os;
}

std::vector<InputPtr> getInput() {
    string line;
    std::getline(std::cin, line);
    int num_tests = std::stoi(line);
    std::vector<InputPtr> result;
    for (int i = 0; i < num_tests; i++) {
        InputPtr input = std::make_shared<Input>();
        std::getline(std::cin, line);
        int num_cities = std::stoi(line);
        for (int j = 0; j < num_cities; j++) {
            std::getline(std::cin, line);
            input->cities.push_back(line);
            std::getline(std::cin, line);
            int p = std::stoi(line);
            input->costs.push_back(vector<std::pair<int, int>>());
            for (int k = 0; k < p; k++) {
                std::getline(std::cin, line);
                stringstream ss(line);
                string tmp;
                std::getline(ss, tmp, ' ');
                int idx = std::stoi(tmp);
                std::getline(ss, tmp, ' ');
                int cost = std::stoi(tmp);
                input->costs.back().emplace_back(idx, cost);
            }
        }
        std::getline(std::cin, line);
        int r = std::stoi(line);
        for (int i = 0; i < r; i++) {
            std::getline(std::cin, line);
            stringstream ss(line);
            string tmp;
            std::getline(ss, tmp, ' ');
            string from = tmp;
            std::getline(ss, tmp, ' ');
            string to = tmp;
            input->queries.emplace_back(from, to);
        }

        for (int i = 0; i < input->cities.size(); i++) {
            input->cityIndices[input->cities[i]] = i;
        }

        result.push_back(input);
        std::getline(std::cin, line); // empty line
    }

    return result;
}

std::vector<InputPtr> getInputTest() {
    InputPtr input = std::make_shared<Input>();
    input->cities = {"gdansk", "bydgoszcz", "torun", "warszawa"};
    input->cityIndices = {
        {"gdansk", 0}, {"bydgoszcz", 1}, {"torun", 2}, {"warszawa", 3}};
    input->costs = {{{2, 1}, {3, 3}},
                    {{1, 1}, {3, 1}, {4, 4}},
                    {{1, 3}, {2, 1}, {4, 1}},
                    {{2, 4}, {3, 1}}};
    input->queries = {{"gdansk", "warszawa"}, {"bydgoszcz", "warszawa"}};

    return {input};
}

int main() {
    std::vector<InputPtr> inputs = getInput();
    // std::vector<InputPtr> inputs = getInputTest();
    // std::cout << inputs << endl;
    for (const auto &input : inputs) {
        int n = input->cities.size();
        vector<int> result;
        for (const auto &query : input->queries) {
            int from = input->cityIndices.at(query.first);
            int to = input->cityIndices.at(query.second);
            std::vector<int> d(n, std::numeric_limits<int>::max());
            d[from] = 0;
            using pii = pair<int, int>;
            std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
            pq.emplace(0, from);
            while (not pq.empty()) {
                int city = pq.top().second;
                int currCost = pq.top().first;
                pq.pop();
                if (currCost != d[city]) {
                    continue;
                }

                if (city == to) {
                    result.push_back(d[city]);
                    break;
                }
                for (const auto &nei : input->costs.at(city)) {
                    int next = nei.first - 1;
                    int c = nei.second;
                    if (d[next] > d[city] + c) {
                        d[next] = d[city] + c;
                        pq.emplace(d[next], next);
                    }
                }
            }
        }
        for (int x : result)
            cout << x << endl;
    }
    return 0;
}