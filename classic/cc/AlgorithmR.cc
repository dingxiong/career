// Reservoir Sampling
// Algorithm R by Jeffrey Vitter. 
// assuming k < s and using one-based array indexing):
// (* S has items to sample, R will contain the result *)
//
// ReservoirSample(S[1..n], R[1..k])
//   // fill the reservoir array
//   for i = 1 to k
//       R[i] := S[i]

//   // replace elements with gradually decreasing probability
//   for i = k+1 to n
//     j := random(1, i)   // important: inclusive range
//     if j <= k
//         R[j] := S[i]

#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iterator>

using namespace std;

class RS {
public :
    vector<int> AlgorithmR(vector<int> S, int k){
	vector<int> R(S.begin(), S.begin() + k);
	for(int i = k + 1; i < S.size(); i++){
	    int j = rand() % i;
	    if(j < k)
		R[j] = S[i];
	}
	return R;
    }
};

int main(){
    vector<int> S = {1, 2, 3, 4, 5, 6, 7, 8};
    RS rs;
    srand(time(0));
    
    auto result = rs.AlgorithmR(S, 3);
    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
    
    return 0;
}
