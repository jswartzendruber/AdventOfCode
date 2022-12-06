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

// False if they are equal
bool check(char a, char b) {
  return a != b;
}

bool checkHelper(char a, char b, char c, char d) {
  if (check(a,b) && check(a,c) && check(a,d) && check(b,c) && check(b,d) && check(c,d))
    return true;
  else
    return false;
}

int main() {
  ifstream cin("6.input");
  vector<string> v = {};
  string line;
  while (getline(cin, line)) {
    v.push_back(line);
  }

  int sum = 0;

  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      if (j > 3) {
	if (checkHelper(v[i][j], v[i][j - 1], v[i][j - 2], v[i][j - 3])) {
	  sum += j + 1;
	  break;
	}
      }
    }
  }

  cout << "Sum: " << sum << "\n";

  return 0;
}
