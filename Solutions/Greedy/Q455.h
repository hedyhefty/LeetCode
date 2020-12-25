#include "Solution.h"

class Q455 : public Solution
{
public:
	void Solve() override
	{
		vector<int> g{1,2,3};
		vector<int> s{1,1,1,1};

		cout << findContentChildren(g, s) << endl;
	}

	int findContentChildren(vector<int>& g, vector<int>& s)
	{
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());

		int i = 0;
		int j = 0;

		int res = 0;

		while(i < g.size())
		{
			while (j < s.size())
			{
				if (s[j] < g[i])
				{
					++j;
				}
				else
				{
					++res;
					++i;
					++j;
					break;
				}
			}

			if (j >= s.size())
			{
				break;
			}
		}

		return res;
	}
};