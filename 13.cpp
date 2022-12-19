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

vector<int> matchIntList(string in) {
  cout << "MatchIntList: " << in << "\n";
  int idx = 1; // Past first bracket

  int start = 0;
  int end = 0;
  vector<int> list;
  while (in[idx] != ']') { // Until bracket
    if (isdigit(in[idx])) {
      idx++;
    } else {
      end = idx;
      cout << "substr: " << in.substr(start, end) << "\n";
      list.push_back(stoi(in.substr(start, end)));
      idx++;
      start = idx;
    }
  }

  return list;
}

Atom matchAtom(string in) {
  cout << "MatchAtom: " << in << "\n";
  if (in[0] == '[') {
    return matchAtom(in.substr(1));
  } else {
    Atom atom;
    atom.list = matchIntList(in);
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
  Atom a = matchAtom(in);
  for (int i : a.list) {
    cout << i << ",";
  }
  cout << "\n";

  for (int i = 0; i < v.size(); ++i) {
    if (v[i][0] == '[') {

    }
  }

  return 0;
}
