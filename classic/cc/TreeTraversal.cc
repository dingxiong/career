#include <vector>
#include <stack>
#include <iostream>
#include <memory>
#include <algorithm>

struct TreeNode;
using TreeNodePtr = std::shared_ptr<TreeNode>;

struct TreeNode
{
	int val;
	TreeNodePtr left, right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class TreeTraversal
{
public:
	TreeTraversal() = default;

	/* ---------------             pre order        ----------------- */
	std::vector<int> preorder_recursive(const TreeNodePtr &root)
	{
		std::vector<int> result;
		preorder_helper(root, result);
		return result;
	}

	void preorder_helper(const TreeNodePtr &root, std::vector<int> &result)
	{
		if (root == nullptr)
		{
			return;
		}
		result.push_back(root->val);
		preorder_helper(root->left, result);
		preorder_helper(root->right, result);
	}

	std::vector<int> preorder_stack(const TreeNodePtr &root)
	{
		std::vector<int> result;
		if (not root)
			return result;

		TreeNodePtr curt = root;
		std::stack<TreeNodePtr> stk;
		stk.push(curt);
		while (not stk.empty())
		{
			curt = stk.top();
			stk.pop();
			result.push_back(curt->val);
			if (curt->right)
				stk.push(curt->right);
			if (curt->left)
				stk.push(curt->left);
		}
		return result;
	}

	/* ---------------             in order        ----------------- */
	std::vector<int> inorder_recursive(const TreeNodePtr &root)
	{
		std::vector<int> result;
		inorder_helper(root, result);
		return result;
	}

	void inorder_helper(const TreeNodePtr &root, std::vector<int> &result)
	{
		if (not root)
			return;
		inorder_helper(root->left, result);
		result.push_back(root->val);
		inorder_helper(root->right, result);
	}

	std::vector<int> inorder_stack(const TreeNodePtr &root)
	{
		std::vector<int> result;
		std::stack<TreeNodePtr> stk;
		TreeNodePtr curt = root;
		while (curt || not stk.empty())
		{
			while (curt)
			{
				stk.push(curt);
				curt = curt->left;
			}
			auto tmp = stk.top();
			stk.pop();
			result.push_back(tmp->val);
			curt = tmp->right;
		}
		return result;
	}

	/* ---------------             post order        ----------------- */
	std::vector<int> postorder_recursive(const TreeNodePtr &root)
	{
		std::vector<int> result;
		postorder_helper(root, result);
		return result;
	}

	void postorder_helper(const TreeNodePtr &root, std::vector<int> &result)
	{
		if (not root)
			return;
		postorder_helper(root->left, result);
		postorder_helper(root->right, result);
		result.push_back(root->val);
	}

	std::vector<int> postorder_reverse_preorder(const TreeNodePtr &root)
	{
		std::vector<int> result;
		if (not root)
			return result;

		TreeNodePtr curt = root;
		std::stack<TreeNodePtr> stk;
		stk.push(curt);
		while (not stk.empty())
		{
			TreeNodePtr tmp = stk.top();
			stk.pop();
			result.push_back(tmp->val);
			if (tmp->left)
				stk.push(tmp->left);
			if (tmp->right)
				stk.push(tmp->right);
		}
		std::reverse(result.begin(), result.end());
		return result;
	}

	std::vector<int> postorder_stack(const TreeNodePtr &root)
	{
		std::vector<int> result;
		if (root == NULL)
			return result;

		std::stack<TreeNodePtr> stk;
		stk.push(root);
		TreeNodePtr curt, prev;
		while (!stk.empty())
		{
			curt = stk.top();
			if ((curt->left == nullptr && curt->right == nullptr) || (prev && (prev == curt->left || prev == curt->right)))
			{
				stk.pop();
				result.push_back(curt->val);
				prev = curt;
			}
			else
			{
				if (curt->right)
					stk.push(curt->right);
				if (curt->left)
					stk.push(curt->left);
			}
		}
		return result;
	}

	/* ---------------             DFS level traversal        ----------------- */
	std::vector<std::vector<int>> dfs_level(const TreeNodePtr &root)
	{
		std::vector<std::vector<int>> result;
		dfs_level_helper(root, result, 0);
		return result;
	}

	void dfs_level_helper(const TreeNodePtr &root, std::vector<std::vector<int>> &result, int level)
	{
		if (not root)
			return;
		if (result.size() <= level)
			result.push_back({});
		result.at(level).push_back(root->val);
		dfs_level_helper(root->left, result, level + 1);
		dfs_level_helper(root->right, result, level + 1);
	}

	/* ---------------             DFS      traversal        ----------------- */
	std::vector<std::vector<int>> dfs(const TreeNodePtr &root) {
		std::vector<std::vector<int>> result;
		if (not root) return result;
		std::vector<int> path;
		dfs_helper(root, path, result);
		return result;
	}

	void dfs_helper(const TreeNodePtr &root, std::vector<int> &path, std::vector<std::vector<int>> &result) {
		path.push_back(root->val);
		if (not root->left and not root->right) result.push_back(path);
		if (root->left) dfs_helper(root->left, path, result);
		if (root->right) dfs_helper(root->right, path, result);
		path.pop_back();
	}
};

std::ostream &operator<<(std::ostream &os, const std::vector<int> &vec)
{
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(os, ","));
	return os;
}

std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<int>> &vec)
{
	for (const auto& v : vec) os << v << std::endl;
	return os;
}

int main(int argc, char *argv[])
{
	// construct tree
	//          1
	//        /   \
    //       2     3
	//        \   / \
    //         4 5   6
	TreeNodePtr root = std::make_shared<TreeNode>(1);
	root->left = std::make_shared<TreeNode>(2);
	root->right = std::make_shared<TreeNode>(3);
	root->left->right = std::make_shared<TreeNode>(4);
	root->right->left = std::make_shared<TreeNode>(5);
	root->right->right = std::make_shared<TreeNode>(6);

	TreeTraversal t;

	std::cout << "preorder" << std::endl;
	std::cout << t.preorder_recursive(root) << std::endl;
	std::cout << t.preorder_stack(root) << std::endl;

	std::cout << "inorder" << std::endl;
	std::cout << t.inorder_recursive(root) << std::endl;
	std::cout << t.inorder_stack(root) << std::endl;

	std::cout << "postorder" << std::endl;
	std::cout << t.postorder_recursive(root) << std::endl;
	std::cout << t.postorder_reverse_preorder(root) << std::endl;
	std::cout << t.postorder_stack(root) << std::endl;

	std::cout << "dfs level" << std::endl;
	std::cout<< t.dfs_level(root) << std::endl;

	std::cout << "dfs" << std::endl;
	std::cout << t.dfs(root) << std::endl;

	return 0;
}