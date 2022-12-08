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

int main() {
  ifstream cin("8.input");
  vector<string> v;
  string line;
  while (getline(cin, line)) {
    v.push_back(line);
  }

  int trees[v[0].size()][v[0].size()];
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      trees[i][j] = v[i][j] - '0';
    }
  }

  int vis[v[0].size()][v[0].size()];
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      vis[i][j] = 0;
    }
  }

  // L -> R
  for (int i = 1; i < v.size() - 1; i++) {
    int rowMax = trees[i][0];
    for (int j = 1; j < v[i].size() - 1; j++) {
      if (trees[i][j] > rowMax) {
	rowMax = trees[i][j];
	vis[i][j]++;
      }
    }
  }

  // R -> L
  for (int i = 1; i < v.size() - 1; i++) {
    int rowMax = trees[i][v.size() - 1];
    for (int j = v[i].size() - 1; j >= 1; j--) {
      if (trees[i][j] > rowMax) {
	rowMax = trees[i][j];
	vis[i][j]++;
      }
    }
  }

  // B -> T
  for (int i = 1; i < v.size() - 1; i++) {
    int rowMax = trees[v.size() - 1][i];
    // cout << "rom: " << rowMax << "\n";
    for (int j = v[i].size() - 1; j >= 1; j--) {
      // cout << "tr: " << trees[j][i] << " rom " << rowMax << "\n";
      if (trees[j][i] > rowMax) {
	rowMax = trees[j][i];
	vis[j][i]++;
      }
    }
  }

  // T -> B
  for (int i = 1; i < v.size() - 1; i++) {
    int rowMax = trees[0][i];
    for (int j = 1; j < v[i].size() - 1; j++) {
      if (trees[j][i] > rowMax) {
	rowMax = trees[j][i];
	vis[j][i]++;
      }
    }
  }

  int visible = v.size() * 4 - 4;
  for (int i = 1; i < v.size() - 1; i++) {
    for (int j = 1; j < v[i].size() - 1; j++) {
      if (vis[i][j] > 0) {
	visible++;
      }
    }
  }

  for (int i = 0; i < v.size(); i++) {
    cout << trees[i][v.size() - 1] << " ";
  }

  cout << "Visible: " << visible << "\n";

  return 0;
}
