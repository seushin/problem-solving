/*
 * https://leetcode.com/problems/implement-trie-prefix-tree/
 */
#include <cstring>
#include <string>
using namespace std;

class Trie {
private:
    Trie *child[26];
    bool end;

    Trie *searchNode(string prefix)
    {
        Trie *node = this;
        for (auto c : prefix)
        {
            int idx = c - 'a';
            if (node->child[idx] == NULL)
                return NULL;
            node = node->child[idx];
        }
        return node;
    }

public:
    Trie() {
        memset(child, 0, sizeof(child));
        end = false;
    }

    void insert(string word) {
        Trie *node = this;

        for (auto c : word)
        {
            int idx = c - 'a';
            if (node->child[idx] == NULL)
                node->child[idx] = new Trie;
            node = node->child[idx];
        }
        node->end = true;
    }

    bool search(string word) {
        Trie *node = searchNode(word);
        return node && node->end;
    }

    bool startsWith(string prefix) {
        return searchNode(prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
