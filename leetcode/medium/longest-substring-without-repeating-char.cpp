/*
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longestLen = 0;

        for (int it = 0; it < s.size(); ++it)
        {
            int len = 1;
            bool ascii[256] = { 0 };

            ascii[s[it]] = true;
            for (int i = it + 1; i < s.size(); ++i)
            {
                if (ascii[s[i]] == true)
                    break;
                len++;
                ascii[s[i]] = true;
            }
            longestLen = max(longestLen, len);
            if (longestLen == s.size())
                break;
        }
        return longestLen;
    }
};
