/*
 * https://leetcode.com/problems/sum-of-prefix-scores-of-strings
 */
#include <cstddef>
#include <cstring>
#include <string>
#include <vector>

class Solution
{
private:
	class Node
	{
	public:
		Node *children[26];
		int score;

		Node() : score(0)
		{
			std::memset(children, 0, sizeof(children));
		}

		~Node()
		{
			for (int i = 0; i < 26; ++i)
			{
				if (children[i])
					delete children[i];
			}
		}

		static size_t idx(char c)
		{
			return c - 'a';
		}

		void insert(const std::string &word)
		{
			Node *cur = this;

			for (char c : word)
			{
				int idx = Node::idx(c);

				if (!cur->children[idx])
					cur->children[idx] = new Node();
				cur = cur->children[idx];
				cur->score++;
			}
		}
	};

public:
	std::vector<int> sumPrefixScores(std::vector<std::string> &words)
	{
		int n = words.size();
		std::vector<int> res(n);
		Node node;

		for (auto &word : words)
		{
			node.insert(word);
		}
		for (int i = 0; i < n; ++i)
		{
			std::string &word = words[i];
			Node *cur = &node;

			for (int j = 0; j < word.size(); ++j)
			{
				cur = cur->children[Node::idx(word[j])];
				if (cur == NULL)
					break;
				if (cur->score == 1)
				{
					res[i] += word.size() - j;
					break;
				}
				res[i] += cur->score;
			}
		}
		return res;
	}
};
