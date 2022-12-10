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

void drawCRT(int cyclen, int x) {
  int pos = cyclen % 40;
  if (x == pos || x - 1 == pos || x + 1 == pos) {
    cout << "#";
  } else {
    cout << ".";
  }
  if (pos == 39)
    cout << "\n";
}

int main() {
  ifstream cin("10.input");
  vector<string> v;
  string line;
  while (getline(cin, line)) {
    v.push_back(line);
  }

  int x = 1;
  int cyclen = 0;
  for (int i = 0; i < v.size(); i++) {
    drawCRT(cyclen, x);
    cyclen++;
    if (v[i][0] == 'a') {
      string num;
      for (int j = 5; j < v[i].size(); j++) {
	if (v[i][j] != '-')
	  num.push_back(v[i][j]);
      }
      int n;
      if (v[i][5] == '-')
	n = -stoi(num);
      else
	n = stoi(num);
      drawCRT(cyclen, x);
      cyclen++;
      x += n;
    }
  }

  return 0;
}
