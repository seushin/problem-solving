/*
 * https://leetcode.com/problems/stream-of-characters/
 */
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class StreamChecker {
public:
    StreamChecker(vector<string>& words) : maxLength(0) {
        for (string word : words) {
            maxLength = max(maxLength, word.size());
            trie.insertSuffix(word);
        }
    }

    bool query(char letter) {
        target.append(1, letter);
        if (target.size() > maxLength)
            target.erase(0, 1);
        return (trie.searchSuffix(target));
    }
private:
    string::size_type maxLength;
    string target;

    class Trie {
    public:
        Trie() {
            memset(node, 0, sizeof(node));
            end = false;
        }

        void insertSuffix(string word) {
            Trie *cur = this;

            for (int i = word.size() - 1; i >= 0; i--) {
                int c = word[i] - 'a';

                if (cur->node[c] == NULL)
                    cur->node[c] = new Trie;
                cur = cur->node[c];
            }
            cur->end = true;
        }

        bool searchSuffix(string word) {
            Trie *res = this;

            for (int i = word.size() - 1; i >= 0; i--) {
                int c = word[i] - 'a';

                if (res->end)
                    return (true);
                if (res->node[c] == NULL)
                    break;
                res = res->node[c];
            }
            return (res && res->end);
        }
    private:
        Trie *node[26];
        bool end;
    } trie;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
