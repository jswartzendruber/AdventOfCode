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

  // for (string s : v) {
  //   vector<char> temp;
  //   for (char c : s) {
  //     if (temp.size() == 4) {
  // 	auto loc = find(temp.begin(), temp.end(), c);
  // 	if (loc == temp.end()) {
  // 	  cout << "first marker: " << loc - temp.begin() << "\n";
  // 	  sum += loc - temp.begin();

  // 	  for (auto x : temp)
  // 	    cout << c << " ";
  // 	  cout << "\n";
  // 	  break;
  // 	} else {
  // 	  temp.erase(loc);
  // 	}
  //     } else {
  // 	cout << "push " << c << "\n";
  // 	temp.push_back(c);
  //     }
  //   }
  // }

  for (int i = 0; i < v.size(); i++) {
    set<char> set = {};
    for (int j = 0; j < v[i].size(); j++) {
      if (j > 3) {
	auto find = set.find(j);
	if (find == set.end()) {
	  cout << "found at idx: " << j << "\n";
	  sum += j;
	  break;
	} else {
	  set.erase(v[i][j - 3]);
	}
      } else {
	set.insert(v[i][j]);
      }
    }
  }

  cout << "Sum: " << sum << "\n";



  return 0;
}
