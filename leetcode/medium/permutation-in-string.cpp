/*
 * https://leetcode.com/problems/permutation-in-string/
 */
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution1 {
public:
    bool checkInclusion(string s1, string s2) {
        int len = s1.size();
        sort(s1.begin(), s1.end());

        for (int i = 0; i + len <= s2.size(); ++i)
        {
            string tmp = s2.substr(i, len);

            sort(tmp.begin(), tmp.end());
            if (tmp == s1)
                return true;
        }
        return false;
    }
};

class Solution2 {
public:
    bool checkInclusion(string s1, string s2) {
        int len = s1.size();
        vector<int> target(26, 0), tmp(26, 0);

        for (auto c : s1)
            target[c - 'a']++;
        for (int i = 0; i < s2.size(); ++i)
        {
            /* 지나간(s1의 길이를 벗어난) 글자는 삭제한다 */
            if (len <= i)
                tmp[s2[i - len] - 'a']--;
            tmp[s2[i] - 'a']++;
            if (target == tmp)
                return true;
        }
        return false;
    }
};
