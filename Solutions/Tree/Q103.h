#pragma once

#include "../Solution.h"

#include "../../Structs/TreeNode.h"

class Q103 : public Solution
{
public:
	void Solve() override
	{
		TreeNode root{ 3 };
		TreeNode a{ 1 };
		TreeNode b{ 2 };
		TreeNode c{ 5 };
		TreeNode d{ 7 };
		root.left = &a;
		root.right = &b;
		b.left = &c;
		b.right = &d;

		auto res = zigzagLevelOrder(&root);

		for (auto& r : res)
		{
			for (auto& c : r)
			{
				cout << c << " ";
			}
			cout << endl;
		}
	}

	vector<vector<int>> zigzagLevelOrder(TreeNode* root)
	{
		vector<vector<int>> ans;
		vector<pair<TreeNode*, int>> proccedList{ {root,1} };

		BFSWalking(proccedList, ans);

		for (size_t i = 0; i < ans.size(); ++i)
		{
			if (i % 2 == 1)
			{
				reverse(ans[i].begin(), ans[i].end());
			}
		}

		return ans;
	}

	void BFSWalking(vector<pair<TreeNode*, int>>& proccedList, vector<vector<int>>& map)
	{
		if (proccedList.empty())
		{
			return;
		}

		auto node = proccedList.begin()->first;
		auto level = proccedList.begin()->second;

		if (map.size() < level)
		{
			map.push_back(vector<int>{});
		}

		map[level - 1].push_back(node->val);

		if (node->left)
		{
			proccedList.push_back({ node->left,level + 1 });
		}

		if (node->right)
		{
			proccedList.push_back({ node->right,level + 1 });
		}

		proccedList.erase(proccedList.begin());

		BFSWalking(proccedList, map);
	}
};