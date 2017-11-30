//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/search-engine/
#include <iostream>
#include <string>
#include <queue>
#include <fstream>
using namespace std;

#define MAX 26

struct Node
{
	Node *child[MAX];
	int cntLeaf;
	int wei;
};

Node* newNode()
{
	Node *p = new Node;

	p->cntLeaf = 0;

	for (int i = 0; i < MAX; i++)
	{
		p->child[i] = NULL;
	}

	return p;
}

void AddWord(Node *root, string s, int wei)
{
	int ch;
	Node *p = root;

	for (int i = 0; i < s.length(); i++)
	{
		ch = s[i] - 'a';
		if (p->child[ch] == NULL)
		{
			p->child[ch] = newNode();
			p->child[ch]->wei = wei;
		}

		p = p->child[ch];
	}

	p->cntLeaf++;
}

int getResult(Node *root, string s)
{
	int ch;
	Node *p = root;
	int res = 1;
	for (int i = 0; i < s.length(); i++)
	{
		ch = s[i] - 'a';
		if (p->child[ch] == NULL)
		{
			return -1;
		}
		
		res = p->child[ch]->wei;

		p = p->child[ch];
		
	}

	return res;
}

int main(int argc, char const *argv[])
{
	//freopen("xx.txt", "r", stdin);
	int n, q;
	cin >> n >> q;

	priority_queue <pair<int, string> > pq;

	string tmp;
	int w;
	for (int i = 0; i < n; i++)
	{	
		cin >> tmp >> w;
		pq.push(pair<int, string>(w, tmp));
	}

	pair<int, string> to;
	Node *root = newNode();
	while (pq.empty() == false)
	{
		to = pq.top();
		pq.pop();
		AddWord(root, to.second, to.first);
	}

	for (int i = 0; i < q; i++)
	{
		cin >> tmp;
		cout << getResult(root, tmp) << endl;
	}

	return 0;
}