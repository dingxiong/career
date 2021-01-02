#include <iostream>
#include <cmath>
#include <limits>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

using Mat = std::vector<vector<int>>;

vector<int> split(const string& str) {
	string s;
	stringstream ss(str);
	vector<int> ret;
	while(std::getline(ss, s, ' ')) {
		if (s.empty()) continue;
		ret.push_back(std::stoi(s));
	}
	return ret;
}

int main() {
	string line;
	std::getline(std::cin, line);
	int n = std::stoi(line);
	std::getline(std::cin, line);
	vector<int> nums = split(line);
    std::getline(std::cin, line);
    int q = std::stoi(line);
    vector<pair<int, int>> queries;
    for (int i = 0; i < q; i++) {
        std::getline(std::cin, line);
        vector<int> tmp = split(line);
        queries.emplace_back(tmp.at(0), tmp.at(1));
    }

    /*
    std::cout << "n:" << n << std::endl;
    std::cout << "nums:";
    for (int i : nums) std::cout << i << ",";
    std::cout << std::endl;
    std::cout << "q:" << q << std::endl;
    std::cout << "queries" << std::endl;
    for (const auto& p : queries) {
        std::cout << p.first << "," << p.second << std::endl;
    }
    */


    int max_int = std::numeric_limits<int>::max();
    int m = std::log2(n) + 1;
    Mat dp(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        dp[i][0] = nums[i];
    }
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int mid = j+(1<<(i-1));
            dp[j][i] = std::min(dp[j][i-1], (mid < n ? dp[mid][i-1]: max_int));
        }
    }

    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << dp[i][j] << ",";
        }
        std::cout << std::endl;
    }
    */

    vector<int> ret(q);
    for (int i = 0; i < q; i++) {
        auto& p = queries[i];
        int j = log2(p.second - p.first + 1);
        ret[i] = std::min(dp[p.first][j], dp[p.second + 1 - (1<<j)][j]);
    }
	for(int r: ret) std::cout << r << std::endl;

	return 0;
}