/*
https://www.spoj.com/problems/CHAIN/
*/

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <sstream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <functional>
using namespace std;

using plusx = std::plus<int>
using Mat = std::vector<vector<int>>;
using P = std::unordered_map<int, pair<int, int>>;
using R = std::unordered_map<int, int>;

bool debug = false;

template <class T1, class T2>
ostream &operator<<(ostream &os, const std::pair<T1, T2> &v) {
  os << v.first << ":" << v.second;
  return os;
}

template <class T> ostream &operator<<(ostream &os, std::vector<T> v) {
  for (const auto &item : v) {
    os << item << ",";
  }
  os << endl;
  return os;
}

vector<int> split(const string &str) {
  string s;
  stringstream ss(str);
  vector<int> ret;
  while (std::getline(ss, s, ' ')) {
    if (s.empty())
      continue;
    ret.push_back(std::stoi(s));
  }
  return ret;
}

pair<int, int> find(P &parents, int i) {
    auto iter = parents.find(i);
    if (iter == parents.end()) {
        parents[i] = {i, 0};
    }
  if (parents.at(i).first != i) {
    auto t = find(parents, parents.at(i).first);
    parents.at(i) = {t.first, (t.second + parents.at(i).second) % 3};
  }
  return parents.at(i);
}

bool uni(P &parents, R &ranks, int i, int j, int type) {
    int pi, ri, pj, rj;
  std::tie(pi, ri) = find(parents, i);
  std::tie(pj, rj) = find(parents, j);
  if (debug)
    cout << "ps : " << pi << " " << ri << " " << pj << " " << rj << endl;
  if (pi == pj) {
    bool is_not_same = (type == 1) and ((ri - rj + 3) % 3 != 0);
    bool cannot_eat = (type == 2) and ((ri - rj + 3) % 3 != 2);
    if (is_not_same or cannot_eat) {
      return false;
    }
  } else {
    int dir = (type == 1) ? 0 : 1;
    if (ranks[pi] < ranks[pj]) {
      std::swap(pi, pj);
      std::swap(ri, rj);
      dir *= -1;
    }
    parents[pj] = {pi, (ri + dir - rj + 3) % 3};
    if (ranks.at(pi) == ranks.at(pj)) {
      ranks.at(pi)++;
    }
  }
  return true;
}

void work(std::istream &istr) {
  std::string line;
  // while(std::getline(istr, line)) cout << "line " << line << endl;
  std::getline(istr, line);
  int t = std::stoi(line);
  vector<int> ret;

  for (int i = 0; i < t; i++) {
    std::getline(istr, line);
    vector<int> tokens = split(line);
    int n = tokens.at(0);
    int k = tokens.at(1);

    P parents;
    R ranks;

    int bad = 0;
    for (int j = 0; j < k; j++) {
      std::getline(istr, line);
      if (debug)
        std::cout << "Working on " << j << " line " << line << endl;
      vector<int> piece = split(line);
      if (piece.at(1) > n or piece.at(2) > n) {
        if (debug)
          std::cout << "bad range " << std::endl;
        bad++;
        continue;
      }
      if (not uni(parents, ranks, piece[1], piece[2], piece[0])) {
        if (debug)
          std::cout << "bad relation " << std::endl;
        bad++;
      }
    }
    cout << bad << endl;
  }
}

int main() {
  if (debug) {
    std::ifstream f("input.txt");
    work(f);
    f.close();
  } else {
    work(std::cin);
  }

  return 0;
}