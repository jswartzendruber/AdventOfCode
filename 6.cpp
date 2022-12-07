#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;

int main() {
  ifstream cin("6.input");
  vector<string> v = {};
  string line;
  while (getline(cin, line)) {
    v.push_back(line);
  }

  int sum = 0;
  int n = 14;
  for (int i = 0; i < v.size(); i++) {
    set<char> set;
    for (int j = n; j < v[i].size(); j++) {
      for (int l = j - 1; l >= j - n; l--) {
	set.insert(v[i][l]);
      }

      int size = set.size();
      set.clear();
      if (size == n) {
	cout << "found : " << j << "\n";
	sum += j;
	break;
      }
    }
  }

  cout << "Sum: " << sum << "\n";

  return 0;
}
