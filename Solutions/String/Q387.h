#pragma once

#include "../Solution.h"

class Q387 : public Solution
{
public:
	void Solve() override
	{
		string test = "aaa";
		cout << firstUniqChar(test) << endl;
	}

	int firstUniqChar(string s) 
	{
		array<short, 255> arr{ 0 };

		for (auto& c : s)
		{
			++arr[c];
		}

		for (size_t i = 0; i < s.size(); ++i)
		{
			if (arr[s[i]] == 1)
			{
				return i;
			}
		}

		return -1;
	}
};