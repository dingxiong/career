#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

// SegmentTree implements two methods: query && update
class SegmentTree {
public:
    struct SegNode {
        int low, high, sum = 0;
        SegNode *left, *right;
        SegNode(int s, int e) : low(s), high(e), left(NULL), right(NULL) {}
    };
    
    
    SegmentTree(vector<int> &nums) {
        int n = nums.size();
        root = new SegNode(0, n-1);
        
        for(int i = 0; i < n; i++){
            SegNode *curt = root;
            while(curt->low < curt->high){
                curt->sum += nums[i];
                int mid = curt->low + (curt->high - curt->low) / 2;
                if(i <= mid){
                    if(curt->left == NULL)
                        curt->left = new SegNode(curt->low, mid);
                    curt = curt->left;
                }
                else {
                    if(curt->right == NULL)
                        curt->right = new SegNode(mid + 1, curt->high);
                    curt = curt->right;
                }
            }
            curt->sum += nums[i]; 
        }
    }

    void update(int i, int val) { 
        int change = val - sumRange(i, i);
        
        SegNode *curt = root;
        while(curt->low < curt->high){
            curt->sum += change;
            int mid = curt->low + (curt->high - curt->low)/2;
            if(i <= mid)
                curt = curt->left;
            else
                curt = curt->right;
        }
        curt->sum += change;
    }

    int sumRange(int i, int j) {
        return sumRangeHelper(i, j, root);
    }
    
    int sumRangeHelper(int i, int j, SegNode *root){
        if(root->low == i && root->high == j)
            return root->sum;
            
        int mid = root->low + (root->high - root->low) / 2;
        if(i > mid)
            return sumRangeHelper(i, j, root->right);
        else if(j <= mid)
            return sumRangeHelper(i, j, root->left);
        else
            return sumRangeHelper(i, mid, root->left) + sumRangeHelper(mid + 1, j, root->right);
    }
    
private :
    SegNode *root;
};

int main(){
    // Given nums = [1, 3, 5]
    // sumRange(0, 2) -> 9
    // update(1, 2)
    // sumRange(0, 2) -> 8    
    vector<int> nums = {1, 3, 5};
    SegmentTree st(nums);
    cout << st.sumRange(0, 2) << endl;
    st.update(1, 2);
    cout << st.sumRange(0, 2) << endl;

    return 0;
}
