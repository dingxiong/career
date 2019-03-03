#include <string>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

#define CASE_20

using namespace std;

/// get the kmp match table 
std::vector<int> getMatchTable(const std::string &s){
    vector<int> match(s.size());
    match[0] = 0;
    for(int i = 1; i < s.size(); i++){
	int k = match[i-1];
	while(s[i] != s[k] && k > 0)
	    k = match[k-1];
	match[i] = k + (s[i] == s[k]); // should not be k + 1 if the termination comes from k = 0
				       // but not from s[i] == s[k]
    }

    return match;
}

/// find all matching indices
/// @param[in] s string
/// @param[in] p pattern
vector<int> kmp(const string &s, const string &p){
    int n = s.length(), m = p.length();
    vector<int> result;
    if(m == 0){
	result.resize(n);
	iota(result.begin(), result.end(), 0);
	return result;
    }
	
    int i = 0, j = 0; 
    vector<int> match = getMatchTable(p);
    while(i < n){
	while(i < n && j < m && s[i] == p[j]){
	    i++;
	    j++;
	}
	if(j == m){
	    result.push_back(i - j);
	    j = match[j-1];
	}
	else {
	    if(j == 0)
		i++;
	    else 
		j = match[j-1];
	}
	    
    }

    return result;

}


template<class T>
void printVec(vector<T> vec){
    for(auto &x : vec)
	cout << x << ' ';
    cout << endl;
}

int main(){

//////////////////////////////////////////////////////////////////////
#ifdef CASE_10
    string s = "ababababca";
    printVec(getMatchTable(s));

#endif
//////////////////////////////////////////////////////////////////////
#ifdef CASE_20
    string s = "san and linux training";
    string p = "lin";
    printVec(kmp(s, p));

#endif

    return 0;
}

