#pragma once

struct TreeNode {
	int val;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
	TreeNode(int x) : val(x) {}
};