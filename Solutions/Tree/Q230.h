#pragma once
#include "../Solution.h"
#include "../../Structs/TreeNode.h"

class Q230 : public Solution
{
public:
	void Solve() override
	{

	}

	int kthSmallest(TreeNode* root, int k) 
	{
		vector<TreeNode*> nodeList;

		nodeList.push_back(root);

		size_t i = 0;

		while (i < nodeList.size())
		{
			auto node = nodeList[i];
			if (node->left)
			{
				nodeList.push_back(node->left);
			}
			if (node->right)
			{
				nodeList.push_back(node->right);
			}
			++i;
		}

		auto comp = [](TreeNode* a, TreeNode* b)
		{
			return a->val <= b->val;
		};

		sort(nodeList.begin(), nodeList.end(), comp);

		return nodeList[k - 1]->val;
	}
};