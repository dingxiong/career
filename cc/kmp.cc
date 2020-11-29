#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

#define CASE_20

using namespace std;

/**
 * KMP: Given a long string S (text) and a short string W (pattern), find all positons in S 
 * 	such that the substring starting from that position equals W.
 * 
 * 1. bad senario for a brute-force solution: S = one million A, W = 100 A + B.
 * 
 * Personally, I feel the geeksforgeeks website explanation is better than Wikipedia.
 * https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
 * 
 * Key point:
 * 1. Construct lps : longest proper prefix which is also a suffix
 * 	lps[i] = the longest proper prefix of W[0..i]  which is also a suffix of W[0..i]. 
 * 	proper prfix = it is prefix but not equal to itself.
 * 2. The mismatched position is the crutial part
 * 
 * Simulation cases
 * Let i = current compare pos of S
 * 	   j = current compare pos of W
 * 
 * 01234567[8]90123456789012345 => S
 * 	   0123[4]56                => W
 * 
 * Above i = 8, j = 4, and we find S[i] != W[j]. what should we do? 
 * 
 * For brute-force method, we simply shift W to right by one space and compare from start again, namely,
 * reset i = 5, j = 0.
 * 01234[5]67890123456789012345 => S
 * 	   	[0]123456               => W
 * 
 * Same for KMP, we need shift W to right, but the question is could we shift more than one space?
 * In this case, we already know that S[4:7] = W[0:3]. The curtial part is that we should find
 * a character in W[x] to compare S[8]. We must have x < 4 since we will shift W to right. (Please think 
 * about this part!) Suppose x = 2
 * 01234567[8]90123456789012345 => S
 * 	   	 01[2]3456              => W
 * This configuration also means that S[6:7] = W[0:1], but from about S[4:7] = W[0:3] 
 * so, we have S[6:7] = W[0:1] = W[2:3], that is prefix = suffix
 * In order to be conservative and not miss any possible solution, we need x to be as large as possible,
 * that is we need to find largest prefix = suffix. That is lps[i].
 * Please draw the relation on a piece of paper!
 * 
 * *****
 * lps algorithm
 * It combines some DP idea with the same idea as KMP main part.
 * len(lps) = len(W)
 * lps[i] = the max length of equal prefix and suffix for W[0:i]
 * Then two cases 
 * 	1) W[k] = W[lps[k-1]] => lps[k] = lps[k-1] + 1
 * 		abcx...abcx
 * 	2) Else, we need iterate to narrow down the length
 * 		say, for example,
 * 01234567890[1]23456
 * abcdexabcde[y]
 * 		lps[10] = 5, but W[11] != W[5]
 * Very similar idea to the main part of KMP. You need to find max length inside W[lps[10]].
 * 		
 * 
 */

/// get the kmp lps table
std::vector<int> get_lps(const std::string &s) {
  std::vector<int> lps(s.size());
  lps[0] = 0;
  for (int i = 1; i < s.size(); i++) {
    int k = lps[i - 1];
    while (s[i] != s[k] && k > 0)
      k = lps[k - 1];
    lps[i] = k + (s[i] == s[k]); // should not be k + 1 if the termination
                                   // comes from k = 0 but not from s[i] == s[k]
  }

  return lps;
}

/// find all matching indices
/// @param[in] s string
/// @param[in] p pattern
vector<int> kmp(const string &s, const string &p) {
  int n = s.length(), m = p.length();
  vector<int> result;
  if (m == 0) {
    result.resize(n);
    iota(result.begin(), result.end(), 0);
    return result;
  }

  int i = 0, j = 0;
  vector<int> match = get_lps(p);
  while (i < n) {
    while (i < n && j < m && s[i] == p[j]) {
      i++;
      j++;
    }
    if (j == m) {
      result.push_back(i - j);
      j = match[j - 1];
    } else {
      if (j == 0)
        i++;
      else
        j = match[j - 1];
    }
  }

  return result;
}

template <class T> void printVec(vector<T> vec) {
	std::copy(vec.begin(), vec.end(), std::iostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}

int main() {

//////////////////////////////////////////////////////////////////////
#ifdef CASE_10
  string s = "ababababca";
  printVec(get_lps(s));

#endif
//////////////////////////////////////////////////////////////////////
#ifdef CASE_20
  string s = "san and linux training";
  string p = "lin";
  printVec(kmp(s, p));

#endif

  return 0;
}
