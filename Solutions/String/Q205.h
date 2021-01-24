#pragma once
#include "Solution.h"

class Q205 : public Solution
{
public:
	void Solve() override
	{
		cout << boolalpha << isIsomorphic("erg", "add");
	}

    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
        {
            return false;
        }

        map<char, char> dict;
        map<char, char> dictReverse;

        for (size_t i = 0; i < s.size(); ++i)
        {
            if (dict.count(s[i]) != 0 && dict[s[i]] != t[i])
            {
                return false;
            }

            if (dictReverse.count(t[i]) != 0 && dictReverse[t[i]] != s[i])
            {
                return false;
            }

            dict[s[i]] = t[i];
            dictReverse[t[i]] = s[i];
        }

        return true;
    }
};