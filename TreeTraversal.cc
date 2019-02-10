#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class stackMethod {
    vector<int> preorder(TreeNode *root){
	vector<int> result;
	if(root == NULL)
	    return result;
	
	stack<TreeNode*> stk;
	stk.push(root);
	TreeNode *curt;
	while(!stk.empty()){
	    curt = stk.top();
	    stk.pop();
	    result.push_back(curt->val);
	    if(curt->right)
		stk.push(curt->right);
	    if(curt->left)
		stk.push(curt->left);
	}
	return result;
    }
    
    vector<int> inorder(TreeNode *root){
	vector<int> result;
	stack<TreeNode*> stk;
	TreeNode *curt;
	while(root != NULL || !stk.empty()){
	    while(root != NULL){
		stk.push(root);
		root = root->left;
	    }
	    curt = stk.top();
	    stk.pop();
	    result.push_back(pop->val);
	    root = curt->right;	    
	}
	return result;
    }
    
    vector<int> postorder(TreeNode *root){
	vector<int> result;
	if(root == NULL)
	    return result;

	vector<TreeNode*> stk;
	stk.push(root);
	TreeNode *curt, prev = NULL;
	while(!stk.empty()){
	    curt = stk.top();
	    if(curt->left == NULL && curt->right == NULL || prev && (prev == curt->left || prev == curt->right)){
		stk.pop();
		result.push_back(curt->val);
		prev = curt;
	    }
	    else {
		if(curt->right)
		    stk.push(curt->right);
		if(curt->left)
		    stk.push(curt->left);
	    }
	}
	return result;
    }
};
