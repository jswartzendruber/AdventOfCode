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

struct Atom {
  int type;
  Atom *atom;
  vector<int> list;
};

Atom *matchList(string in) {
  Atom *atom = new Atom;
  if (in[1] == '[') {
    return matchList(in.substr(1));
  } else {
    string sublist = in.substr(1);
    int len = 0;
    while (len < sublist.size()) {
      if (sublist[len] == ']') {
	break;
      } else {
	len++;
      }
    }
    sublist = sublist.substr(0, len);
    cout << "sublist: " << sublist << "\n";

    istringstream values(sublist, istringstream::in);
    string chunk;
    while (getline(values, chunk, ',')) {
      atom->list.push_back(stoi(chunk));
    }

    return atom;
  }
}

int main() {
  ifstream cin("13.input");
  vector<string> v;
  string line;
  while (getline(cin, line)) {
    v.push_back(line);
  }

  string in = "[[10,12,8],[13,14]]";
  cout << "in: " << in << "\n";
  Atom *a = matchList(in);
  for (int i : a->list) {
    cout << i << ",";
  }
  cout << "\n";
  delete a;

  for (int i = 0; i < v.size(); ++i) {
    if (v[i][0] == '[') {

    }
  }

  return 0;
}
