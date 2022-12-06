#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  ifstream cin("3.input");
  vector<string> v = {};
  string line;
  while (getline(cin, line)) {
    v.push_back(line);
  }

  int points = 0;

  for (int i = 0; i < v.size(); i += 3) {
    for (int j = 0; j < v[i].size(); j++) {
      if (v[i + 1].find(v[i][j]) != -1 && v[i + 2].find(v[i][j]) != -1) {
        if (v[i][j] >= 65 && v[i][j] <= 90) {
          points += v[i][j] - 38;
        } else {
          points += v[i][j] - 96;
        }
        break;
      }
    }
  }

  cout << "Points: " << points << "\n";

  return 0;
}
