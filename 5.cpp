#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
  ifstream cin("5.input");
  vector<string> v = {};
  string line;
  while (getline(cin, line)) {
    v.push_back(line);
  }

  int i = 1;
  while (v[i] != "") {
    i++;
  }

  vector<vector<char>> cols = {};

  int j = i - 1;
  int rown = 0;
  while (rown < v[j].size()) {
    if (v[j][rown] != ' ') {
      vector<char> col;
      // cout << "col: " << v[j][rown] << ": ";
      for (int k = j - 1; k >= 0; k--) {
	if (v[k][rown] != ' ')
	  col.push_back(v[k][rown]);
      }
      // cout << "\n";
      cols.push_back(col);
    }
    rown++;
  }


  for (int j = i + 1; j < v.size(); j++) {
    string word;
    istringstream iss(v[j], istringstream::in);
    vector<int> x = {};

    while (iss >> word) {
      if (isdigit(word[0]))
	x.push_back(stoi(word));
    }

    for (int xi = 0; xi < x.size(); xi += 3) {
      int times = x[xi];
      if (times == 1) {
	int from = x[(xi * 3) + 1] - 1;
	int to = x[(xi * 3) + 2] - 1;

	char temp = cols[from].back();
	// cout << "move " << temp << " from: " << from << " to: " << to << "\n";
	cols[from].pop_back();
	cols[to].push_back(temp);
      } else {
	int from = x[(xi * 3) + 1] - 1;
	int to = x[(xi * 3) + 2] - 1;

	vector<char> temp;
	for (int tim = 0; tim < times; tim++) {
	  temp.push_back(cols[from].back());
	  cols[from].pop_back();
	}
	// cout << "move " << temp << " from: " << from << " to: " << to << "\n";
	for (int y = temp.size() - 1; y >= 0; y--)
	  cols[to].push_back(temp[y]);
      }
    }
  }

  for (auto col : cols) {
    cout << col.back();
  }
  cout << "\n";

  return 0;
}
