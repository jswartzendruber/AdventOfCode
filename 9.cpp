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

using namespace std;

int flatten(int x, int y) {
  return (x * 100) + y;
}

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
  unordered_set<int> s;
  for (int i = 0; i < v.size(); i++) {
    string word;
    istringstream ss = istringstream(v[i], istringstream::in);
    while (ss >> word) {
      string direction = word;
      ss >> word;
      int dist = stoi(word);
      cout << "dir: " << direction << " dist: " << dist << "\n";
      for (int j = 0; j < dist; j++) {
	if (direction == "R") {
	  chy++;
	} else if (direction == "U") {
	  chx++;
	} else if (direction == "D") {
	  chx--;
	} else if (direction == "L") {
	  chy--;
	}

	int t = flatten(ctx, cty);
	int h = flatten(chx, chy);

	// . . .  If tail is in this grid, no change.
	// . H .
	// . . .
	bool skip = false;
	for (int k = chx - 1; k <= chx + 1; k++) {
	  for (int l = chy - 1; l <= chy + 1; l++) {
	    if (t == flatten(k, l)) {
	      skip = true;
	    }
	  }
	}

	// Two steps directly up, down, left, or right, move  tail once in that direction
	if (!skip) {
	  if (ctx == chx || cty == chy) {
	    if (h == t + 2) {
	      cty++; // R
	      cout << "r\n";
	    } else if (h == t - 2) {
	      cty--; // L
	      cout << "l\n";
	    } else if (h == t - 200) {
	      ctx--; // B
	      cout << "b\n";
	    } else if (h == t + 200) {
	      ctx++; // T
	      cout << "t\n";
	    }
	  } else {
	    // Move diagonally
	    if (cty < chy && ctx < chx) {
	      // cout << "rightup\n";
	      cty++;
	      ctx++;
	    } else if (cty > chy && ctx > chx) {
	      // cout << "leftdown\n";
	      cty--;
	      ctx--;
	    } else if (cty > chy && ctx < chx) {
	      // cout << "leftup\n";
	      cty--;
	      ctx++;
	    } else if (cty < chy && ctx < chx) {
	      // cout << "rightdown\n";
	      cty--;
	      ctx++;
	    }
	  }
	}

	cout << "T: " << ctx << "," << cty << " H: " << chx << "," << chy << "\n";
	// cout << "ins: " << ctx << "," << cty << "\n";
	s.insert(flatten(ctx, cty));
      }
    }
  }

  for (int i = 6; i >= 0; i--) {
    for (int j = 0; j < 6; j++) {
      if (s.find(flatten(i, j)) != s.end()) {
	cout << " #";
      } else {
	cout << " .";
      }
    }
    cout << "\n";
  }

  cout << "Positions: " << s.size() << "\n";

  return 0;
}
