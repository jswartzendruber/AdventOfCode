#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ifstream cin("1.input");

  int curr_elf = 0;

  vector<int> v = {};
  string line;
  while (getline(cin, line)) {
    if (line.empty()) {
      v.push_back(curr_elf);
      curr_elf = 0;
      continue;
    } else {
      curr_elf += stoi(line);
    }
  }
  v.push_back(curr_elf);
  sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
  int max = v[0] + v[1] + v[2];

  cout << "max: " << max << "\n";
  return 0;
}
