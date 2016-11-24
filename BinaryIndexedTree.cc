#include <vector>
#include <iostream>

using namespace std;

// Binary indexed tree (Fenwick tree). See
// http://cs.stackexchange.com/questions/10538/bit-what-is-the-intuition-behind-a-binary-indexed-tree-and-how-was-it-thought-a
class BIT {
public:
    BIT(vector<int> &nums) {
        bit = vector<int>(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++)
            update(i, nums[i]);
    }
    
    void update(int i, int val) {
        int change = val - sumRange(i, i);
        i++;
        while(i < bit.size()){
            bit[i] += change;
            i += i & -i; // go left
        }
    }

    int sumRange(int i, int j) {
        return prefixSum(++j) - prefixSum(i); 
    }
    
    int prefixSum(int i){ // i is the index in bit not nums
        int s = 0;
        while(i > 0){
            s += bit[i];
            i -= i & -i; // go right
        }
        return s;
    }
    
private : 
    vector<int> bit;
};
