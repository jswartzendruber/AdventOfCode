#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;

struct Node {
  vector<Node*> siblings;
  vector<int> sizes;
  Node *parent;
};

int sum(Node *root, vector<int> *including, int closestTo) {
  int s = 0;

  for (int size : root->sizes) {
    s += size;
  }

  for (Node *sib : root->siblings) {
    int tempsum = sum(sib, including, closestTo);
    if (tempsum >= closestTo) {
      // cout << "add " << tempsum << "\n";
      including->push_back(tempsum);
    }
    s += tempsum;
    // delete sib;
  }

  return s;
}

int main() {
  ifstream cin("7.input");
  string word;
  stringstream ss;
  ss << cin.rdbuf();

  Node root;
  Node *cwd = &root;

  while (ss >> word) {
    if (word == "$") {
      ss >> word; // cmd
      if (word == "cd") {
	ss >> word; // dir
	if (word == "..") {
	  cwd = cwd->parent;
	} else {
	  Node *node = new Node;

	  cwd->siblings.push_back(node);
	  node->parent = cwd;
	  cwd = node;
	}
      } else if (word == "ls") {
	ss >> word; // arg1
	if (word == "dir") {
	  ss >> word; // dirname
	  Node *node = new Node;
	  node->parent = cwd;
	  cwd->siblings.push_back(node);
	} else {
	  int size = stoi(word);
	  ss >> word; // filename
	  cwd->sizes.push_back(size);
	}
      }
    } else {
      if (word == "dir") {
	ss >> word; // dirname
	Node *node = new Node;
	node->parent = cwd;
	cwd->siblings.push_back(node);
      } else {
	int size = stoi(word);
	ss >> word; // filename
	cwd->sizes.push_back(size);
      }
    }
  }

  int total = 70000000;
  int free = 30000000;

  vector<int> is;
  int used = sum(&root, &is, total);
  int unused = total - used;
  int needToFree = free - unused;
  vector<int> possibleFrees;
  sum(&root, &possibleFrees, needToFree);
  int min = total;
  for (int i : possibleFrees) {
    if (i < min && i >= needToFree) {
      min = i;
    }
  }
  cout << "Free dir with: " << min << "\n";

  return 0;
}
