/*
 * https://leetcode.com/problems/word-search-ii/
 */
#include <string>
#include <vector>
using namespace std;

class Trie {
public:
    Trie *child[26];
    string word;

    Trie() : word("")
    {
        memset(child, 0, sizeof(child));
    }

    void insert(string word)
    {
        Trie *node = this;

        for (auto c : word)
        {
            int idx = c - 'a';

            if (node->child[idx] == NULL)
                node->child[idx] = new Trie();
            node = node->child[idx];
        }
        node->word = word;
    }
};

class Solution {
private:
    const int dy[4] = { 1, -1, 0, 0 };
    const int dx[4] = { 0, 0, 1, -1 };
    void findWords(vector<vector<char>>& board, int y, int x,
                       Trie *node, vector<string>& res)
    {
        if (y < 0 || y > board.size() - 1 ||
               x < 0 || x > board[0].size() - 1)
            return;

        char c = board[y][x];
        int idx = c - 'a';
        if (c == ' ')
            return;
        if (node->child[idx] == NULL)
            return;

        node = node->child[idx];
        if (node->word.size() > 0)
        {
            res.push_back(node->word);
            node->word = "";
        }

        board[y][x] = ' ';
        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            findWords(board, ny, nx, node, res);
        }
        board[y][x] = c;
    }

    Trie* insertWords(vector<string>& words)
    {
        Trie *res = new Trie();

        for (auto word : words)
            res->insert(word);
        return res;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        Trie *node = insertWords(words);

        for (int y = 0; y < board.size(); ++y)
        {
            for (int x = 0; x < board[0].size(); ++x)
            {
                findWords(board, y, x, node, res);
            }
        }
        return res;
    }
};
