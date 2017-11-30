//https://www.hackerrank.com/challenges/contacts/problem
#include <bits/stdc++.h>
using namespace std;

#define MAX 26

struct Node
{
	Node *child[MAX];
	int cntPass;
};

Node *newNode()
{
	Node *p = new Node;

	p->cntPass = 0;

	for (int i = 0; i < MAX; i++)
	{
		p->child[i] = NULL;
	}

	return p;
}

void addWord(Node *root, string s)
{
	int ch;
	Node *p = root;

	for (int i = 0; i < s.length(); i++)
	{
		ch = s[i] - 'a';
		if (p->child[ch] == NULL)
		{
			p->child[ch] = newNode();
		}

		if (p->child[ch]) p->child[ch]->cntPass++;
		p = p->child[ch];
	}

}

int findPartial(Node *root, string s)
{
	int ch;
	Node *p = root;

	int res = 0;
	for (int i = 0; i < s.length(); i++)
	{
		ch = s[i] - 'a';
		if (p->child[ch] == NULL)
		{
			return 0;
		}

		p = p->child[ch];
	}

	return p->cntPass;
}

int main(int argc, char const *argv[])
{
	//freopen("xx.txt", "r", stdin);
	int n;
	cin >> n;

	string s, query;
	Node *root = newNode();

	for (int i = 0; i < n; i++)
	{
		cin >> query >> s;

		if (query == "add")
		{
			addWord(root, s);
		}
		else if (query == "find")
		{
			cout << findPartial(root, s) << endl;
		}
	}

	return 0;
}