#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
#include <cmath>

using namespace std;

int main() {
  ifstream cin("9.input");
  vector<string> v;
  string line;
  while (getline(cin, line)) {
    v.push_back(line);
  }

  int chx = 0;
  int chy = 0;
  int ctx = 0;
  int cty = 0;
  unordered_set<string> s;

  int len = 10;
  int rx[len];
  int ry[len];

  for (int i = 0; i < 10; i++) rx[i] = 0;
  for (int i = 0; i < 10; i++) ry[i] = 0;

  for (int i = 0; i < v.size(); i++) {
    string word;
    istringstream ss = istringstream(v[i], istringstream::in);
    while (ss >> word) {
      string direction = word;
      ss >> word;
      int dist = stoi(word);

      for (int j = 0; j < dist; j++) {
	if (direction == "R") {
	  rx[0]++;
	} else if (direction == "U") {
	  ry[0]++;
	} else if (direction == "D") {
	  ry[0]--;
	} else if (direction == "L") {
	  rx[0]--;
	}

	for (int r = 1; r < len; r++) {
	  int dx = rx[r - 1] - rx[r];
	  int dy = ry[r - 1] - ry[r];
	  int dist = max(abs(dx), abs(dy));

	  if (dist > 1) {
	    if (ry[r - 1] > ry[r]) ry[r]++;
	    if (ry[r - 1] < ry[r]) ry[r]--;
	    if (rx[r - 1] > rx[r]) rx[r]++;
	    if (rx[r - 1] < rx[r]) rx[r]--;
	  }
	}

	s.insert(to_string(rx[len - 1])+":"+to_string(ry[len - 1]));
      }
    }
  }

  cout << "Positions: " << s.size() << "\n";

  return 0;
}
