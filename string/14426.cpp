#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Trie{
	struct Node {
		int child[26];
		bool valid;
		Node()
		{
			for (int i = 0; i < 26; i++)
			{
				child[i] = -1;
			}
			valid = false;
		}
	};
	vector<Node> trie;
	int root;
	int product()
	{
		Node next;
		trie.push_back(next);
		return (int)trie.size() - 1;
	}
	Trie()
	{
		root = product();
	}
	void add(string &str, int node, int index)
	{
		if (index == str.length())
		{
			trie[node].valid = true;
			return;
		}
		int c = str[index] - 'a';
		if (trie[node].child[c] == -1)
		{
			int new_node = product();
			trie[node].child[c] = new_node;
		}
		int next = trie[node].child[c];
		add(str, next, index + 1);
	}
	void add(string &str)
	{
		add(str, root, 0);
	}
	
	bool search(string &str, int node, int index)
	{
		if (node == -1)
		{
			return false;
		}
		if (index == str.length())
		{
			return true;
		}
		int c = str[index] - 'a';
		int next = trie[node].child[c];
		return search(str, next, index + 1);
	}
	bool search(string& str)
	{
		return search(str, root, 0);
	}
};

int N, M, cnt;
string str;
Trie trie;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	
    for (int i = 0; i < N; i++){
		cin >> str;
		trie.add(str);
	}
	for (int i = 0; i < M; i++){
		cin >> str;
		if (trie.search(str)){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}