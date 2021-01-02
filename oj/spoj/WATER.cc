#include <algorithm>
#include <iostream>
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
template <class T>
using Mat = vector<vector<T>>;

template <class T>
ostream &operator<<(ostream &os, const Mat<T> &mat) {
    for (const auto &v : mat) {
        for (const auto &x : v) {
            os << (&x == &(*v.begin()) ? "" : ",") << x;
        }
        os << endl;
    }
    return os;
}

vector<Mat<int>> getInput() {
    int t, n, m;
    std::cin >> t;
    vector<Mat<int>> result(t);
    for (int i = 0; i < t; i++) {
        std::cin >> n >> m;
        result[i].assign(n, vector<int>(m));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                std::cin >> result[i][j][k];
            }
        }
    }
    return result;
}

vector<Mat<int>> getMockInput() {
    Mat<int> mat;
    int mode = 2;

    if (mode == 1) {
        mat = {{3, 3, 4, 4, 4, 2}, {3, 1, 3, 2, 1, 4}, {7, 3, 1, 6, 4, 1}};
    } else if (mode == 2) {
        mat = {{78, 16, 94, 36}, {87, 93, 50, 22}, {63, 28, 91, 60},
               {64, 27, 41, 27}, {73, 37, 12, 69}, {68, 30, 83, 31},
               {63, 24, 68, 36}};
    }
    return {mat};
}

int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int x, int y, int m, int n) {
    return x >= 0 and x < m and y >= 0 and y < n;
}

void dfs(const Mat<int> &mat, Mat<int> &high, int x, int y, int currHigh) {
    int m = high.size(), n = high[0].size();
    if (not valid(x, y, m, n)) {
        return;
    }
    currHigh = std::max(currHigh, mat[x][y]);
    if (high[x][y] != -1 and high[x][y] <= currHigh) {
        return;
    }
    high[x][y] = currHigh;
    for (int i = 0; i < 4; i++) {
        int newx = x + dirs[i][0], newy = y + dirs[i][1];
        dfs(mat, high, newx, newy, currHigh);
    }
}

int solve(const Mat<int> &mat) {
    int m = mat.size(), n = mat[0].size();
    Mat<int> high(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++) {
        dfs(mat, high, i, 0, -1);
        dfs(mat, high, i, n - 1, -1);
    }
    for (int i = 0; i < n; i++) {
        dfs(mat, high, 0, i, -1);
        dfs(mat, high, m - 1, i, -1);
    }

    int result = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result += high[i][j] - mat[i][j];
        }
    }

    pp("input matix\n" << mat);
    pp("high matrix\n" << high);
    return result;
}

int main(int argc, char *argv[]) {
#ifdef DEBUG
    auto input = getMockInput();
#else
    auto input = getInput();
#endif

    for (const auto &mat : input) {
        cout << solve(mat) << endl;
    }
    return 0;
}