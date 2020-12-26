#include "Solution.h"

class Q17 : public Solution
{
public:
	void Solve() override
	{
		auto res = letterCombinations("7");

		for (auto& str : res)
		{
			cout << str << endl;
		}
	}

	vector<string> letterCombinations(string digits) 
	{
		vector<string> res;

		if(digits.empty())
		{
			return res;
		}

		BackTracking(digits, 0, "", res);
		return res;
	}

	void BackTracking(const string& digits, int level, string curr, vector<string>& res)
	{
		static vector<string> dict
		{
			"abc",
			"def",
			"ghi",
			"jkl",
			"mno",
			"pqrs",
			"tuv",
			"wxyz"
		};

		int d = digits[level] - '2';

		vector<string> strs;
		for (size_t i = 0; i < dict[d].size(); ++i)
		{
			string hold = curr;
			hold.push_back(dict[d][i]);
			strs.push_back(hold);
		}

		if (level >= digits.size() - 1)
		{
			for (auto& str : strs)
			{
				res.push_back(str);
			}
			return;
		}
		else
		{
			for (auto& str : strs)
			{
				BackTracking(digits, level + 1, str, res);
			}
		}
	}
};