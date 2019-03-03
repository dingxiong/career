#include <iostream>
#include <string>
#include <vector>
 
using namespace std;

class Manacher {

public :
    pair<int, int> findLongestPalindromicString(string text) {
	int n = text.length();
	if(n == 0)
	    return {0, 0};

	n = 2 * n + 1; //Position count
	vector<int> len(n);
	len[0] = 0;
	len[1] = 1; // initialize the first two elements; otherwise iMirror is nagative.
	int curtC = 1; 
	int maxLPSLength = 0;
	int maxLPSCenterPosition = 0;
     
	for (int i = 2; i < n; i++) {
	    int iMirror  = 2 * curtC - i;
	    int r = curtC + len[curtC];
	    bool expand = false;
	    int diff = r - i;

	    if(diff > 0) {
		if(len[iMirror] < diff || len[iMirror] == diff && r == n - 1)
		    len[i] = len[iMirror];
		else if(len[iMirror] > diff || len[iMirror] == diff && r < n-1){
		    len[i] = diff;
		    expand = true; 
		}
	    }
	    else{
		len[i] = 0;
		expand = true; 
	    }
         
	    if (expand == 1){
		while (((i + len[i]) < n && (i - len[i]) > 0) && 
		       ( ((i + len[i] + 1) % 2 == 0) || (text[(i + len[i] + 1)/2] == text[(i - len[i] - 1)/2] ))){
		    len[i]++;
		}
	    }
	
	    if(len[i] > maxLPSLength){
		maxLPSLength = len[i];
		maxLPSCenterPosition = i;
	    }
 
	    if (i + len[i] > r)
		curtC = i;
	}
	
	int start = (maxLPSCenterPosition - maxLPSLength)/2;
	return {start, maxLPSLength};
    }
};
 
int main(int argc, char *argv[]){
    vector<string> ss{"babcbabcbaccba", "abaaba", "abababa", "abcbabcbabcba", "forgeeksskeegfor",
	    "caba", "abacdfgdcaba", "abacdfgdcabba", "abacdedcaba"};
    Manacher manacher;
    for(auto s : ss){
	auto p = manacher.findLongestPalindromicString(s);
	cout << s << ": "<< s.substr(p.first, p.second) << endl;
    }
    return 0;
}
