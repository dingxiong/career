#include <climits>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

/// Floyd–Warshall algorithm is an algorithm for finding all-pair shortest
/// paths in a weighted graph with positive or negative edge weights
/// (but with no negative cycles).
///
/// The dynamic relation is
/// dp[i][j][k+1] = min{ dp[i][j][k], dp[i][k+1][k]+dp[k+1][j][k] }
/// Here dp[i][j][k] refers to the shortest path length from vertex i to
/// vertex j by using only the first k vertices.
///
/// For path reconstruction, define next[i][j][k] the next vertex from i to
/// j by using only the first k vertices. Then
/// next[i][j][k+1] = next[i][k+1][k]  if dp[i][k+1][k] + dp[k+1][j][k] >
/// dp[i][j][k]
///                   unchanged        else
///
/// Time complexity : O(|V|^3)
/// Space complexity : O(|V|^2) by using index rotation to get rid of the third
///                    index of dp and next.

class FloydWarshall {
public:
  vector<vector<int>> next;
  vector<vector<long long>> len;

  FloydWarshall(int nV, vector<tuple<int, int, int>> weights)
      : nV(nV), weights(weights), len(nV, vector<long long>(nV, INT_MAX)),
        next(nV, vector<int>(nV, -1)) {}

  void shortestPath() {
    // initialization
    for (int i = 0; i < nV; ++i) {
      len[i][i] = 0;
    }

    int i, j, w;
    for (int p = 0; p < weights.size(); ++p) {
      tie(i, j, w) = weights[p];
      len[i][j] = w;
      next[i][j] = j;
    }

    for (int k = 0; k < nV; ++k) {
      for (int i = 0; i < nV; ++i) {
        for (int j = 0; j < nV; ++j) {
          if (len[i][j] > len[i][k] + len[k][j]) {
            len[i][j] = len[i][k] + len[k][j];
            next[i][j] = next[i][k];
          }
        }
      }
    }
  }

  vector<int> retrievePath(int from, int to) {
    if (from == to)
      return {from};
    if (next[from][to] == -1)
      return {};

    vector<int> path{from};
    while (from != to) {
      from = next[from][to];
      path.push_back(from);
    }
    return path;
  }

  void printPath(vector<int> path) {
    for (auto i : path)
      cout << i << (i != path.back() ? "->" : "");
    cout << endl;
  }

  void printLen() {
    for (auto row : len) {
      for (auto col : row)
        cout << col << ' ';
      cout << endl;
    }
  }

private:
  int nV; // number of vertices. Index from 0 to nv - 1.

  // <i, j, w> : edge weight w = weight[i][j], i, j \in [0, nV- 1]
  vector<tuple<int, int, int>> weights;
};

int main() {
  int nV = 5;
  vector<tuple<int, int, int>> weights = {
      tuple<int, int, int>(0, 1, 3), tuple<int, int, int>(1, 2, -1),
      tuple<int, int, int>(2, 3, 1), tuple<int, int, int>(3, 4, 8),
      tuple<int, int, int>(4, 0, -2)};

  FloydWarshall fw(nV, weights);
  fw.shortestPath();
  fw.printLen();
  fw.printPath(fw.retrievePath(0, 4));

  return 0;
}
