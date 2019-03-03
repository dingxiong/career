#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

/// Problem description:
/// Given an array of integers, all of them appear k times except
/// one integer appears p times ( 0 < p < k). Then find this single
/// number.
///
/// Method see
/// https://discuss.leetcode.com/topic/11877/detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers
///
/// Main formulaes
/// 0) set up : m = ceiling(log k).  binary expresion k = [k_m, k_{m-1}, ..., k_1], p = [p_m, ..., p_1].
/// 1) x_m = x_m ^ (x_{m-1} & ... & x_1 & num);
/// 2) mask = ~(x'_m & ... & x'_1) Here x'_t = x_t if k_t = 1 else ~x_t
/// 3) x_t &= mask for t = 1, 2, ..., m
/// 4) single element = x_t where t is the index such that p_t != 0.
class SingleNumber {
public :
    
    int getSingleNumber(const vector<int> nums, int k, int p){
	int m = getBitLen(k);
	vector<int> xs(m, 0);
	for(int num : nums){

	    // update x_m by formual (1)
	    vector<int> tmp(m, 0);
	    tmp[0] = num;
	    for(int i = 1; i < m; i++)
		tmp[i] = xs[i-1] & tmp[i-1];
	    for(int i = 0; i < m; i++)
		xs[i] ^= tmp[i];

	    // obtain mask
	    int mask = ~0;
	    for(int i = 0; i < m; i++)
		mask &= (((k>>i) & 1) ? xs[i] : ~xs[i]);
	    mask = ~mask;

	    // reset count
	    for(int i = 0; i < m; i++)
		xs[i] &= mask;	    
	}

	// find the single number
	for(int i = 0; ;i++){
	    if( (p>>i) & 1 )
		return xs[(1<<i) - 1];		
	}
	return 0;
    }

    int getBitLen(int x){
	int len = 0;
	while(x > 0){
	    len++;
	    x >>= 1;
	}
	return len;
    }
};

int main(){
    SingleNumber sn;
    vector<int> nums = {1,1,1, 3,3,3, 5,5,5, 7};
    random_device rd;
    mt19937 g(rd()); 
    shuffle(nums.begin(), nums.end(), g);

    cout << sn.getSingleNumber(nums, 3, 1) << endl;
    return 0;
}
