#pragma once
#include "../Solution.h"
#include "../../Structs/Node.h"

class Q116 : public Solution
{
public:
	void Solve() override
	{

	}

	Node* connect(Node* root) 
	{
		queue<Node*> nodeQueue;

		nodeQueue.push(root);

		while (!nodeQueue.empty())
		{
			size_t size = nodeQueue.size();
			for (size_t i = 0; i < size; ++i)
			{
				auto node = nodeQueue.front();
				nodeQueue.pop();

				if (node->left)
				{
					nodeQueue.push(node->left);
				}

				if (node->right)
				{
					nodeQueue.push(node->right);
				}

				if (i < size - 1)
				{
					node->next = nodeQueue.front();
				}
				else
				{
					node->next = nullptr;
				}
			}
		}

		return root;
	}
};