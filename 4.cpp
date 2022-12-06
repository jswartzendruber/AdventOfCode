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
  ifstream cin("4.input");
  vector<string> v = {};
  string line;
  while (getline(cin, line)) {
    v.push_back(line);
  }

  int overlap = 0;

  for (int i = 0; i < v.size(); ++i) {
    string g1 = v[i].substr(0, v[i].find(","));
    string g2 = v[i].substr(v[i].find(",") + 1, v[i].size());

    int n1 = stoi(g1.substr(0, g1.find("-")));
    int n2 = stoi(g1.substr(g1.find("-") + 1, g1.size()));

    int n3 = stoi(g2.substr(0, g2.find("-")));
    int n4 = stoi(g2.substr(g2.find("-") + 1, g2.size()));

    if ((n1 >= n3 && n1 <= n4) || (n2 >= n3 && n2 <= n4) || (n3 >= n1 && n3 <= n2) || (n4 >= n1 && n4 <= n2)) {
      overlap++;
    }
    // vector<int> v1 = {};
    // vector<int> v2 = {};

    // for (int j = n1; j <= n2; j++) {
    //   v1.push_back(j);
    // }
    // for (int j = n3; j <= n4; j++) {
    //   v2.push_back(j);
    // }

    // vector<int> intersection;
    // set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(intersection));
    // if (intersection.size() > 0 || intersection.size() > 0)
    //   overlap++;
  }

  cout << "Overlap: " << overlap << "\n";

  return 0;
}
