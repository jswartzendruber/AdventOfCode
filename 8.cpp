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

  int max = 0;
  for (int k = 1; k < v.size() - 1; k++) {
    for (int l = 1; l < v.size() - 1; l++) {
      int currScore = 1;
      int unblocked;
      int curr = trees[k][l];

      // L -> R
      unblocked = 0;
      for (int j = l + 1; j < v.size(); j++) {
	unblocked++;
	if (trees[k][j] >= curr) {
	  break;
	}
      }
      currScore *= unblocked;

      // R -> L
      unblocked = 0;
      for (int j = l - 1; j >= 0; j--) {
	unblocked++;
	if (trees[k][j] >= curr) {
	  break;
	}
      }
      currScore *= unblocked;

      // B -> T
      unblocked = 0;
      for (int j = k + 1; j < v.size(); j++) {
	unblocked++;
	if (trees[j][l] >= curr) {
	  break;
	}
      }
      currScore *= unblocked;

      // T -> B
      unblocked = 0;
      for (int j = k - 1; j >= 0; j--) {
	unblocked++;
	if (trees[j][l] >= curr) {
	  break;
	}
      }
      currScore *= unblocked;


      if (currScore > max) {
	max = currScore;
      }
    }
  }

  cout << "Max: " << max << "\n";

  return 0;
}
