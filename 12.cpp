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

void search(int cx, int cy, [][]) {
  return;
}

int main() {
  ifstream cin("12.input");
  vector<string> v;
  string line;
  while (getline(cin, line)) {
    v.push_back(line);
  }

  int sx = 0;
  int sy = 0;
  int ex = 0;
  int ey = 0;
  char g[v.size()][v[v.size() - 1].size()];
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      if (v[i][j] == 'S') {
	sx = i;
	sy = j;
	g[i][j] = 'a';
      } else if (v[i][j] == 'E') {
	ex = i;
	ey = j;
	g[i][j] = 'z';
      } else {
	g[i][j] = v[i][j];
      }
    }
  }

  cout << "start: " << sx << "," << sy << "\n";
  cout << "end: " << ex << "," << ey << "\n";
  // for (int i = 0; i < v.size(); i++) {
  //   for (int j = 0; j < v[i].size(); j++) {
  //     cout << g[i][j];
  //   }
  //   cout << "\n";
  // }

  return 0;
}
