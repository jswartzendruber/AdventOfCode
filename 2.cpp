#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ifstream cin("2.input");

  // input = 0 = rock, 1 = paper, 2 = scissors
  int win[] = {2, 3, 1};
  int lose[] = {3, 1, 2};
  int draw[] = {1, 2, 3};

  int total = 0;

  string line;
  while (getline(cin, line)) {
    int round_points = 0;
    char opp = line[0];
    char me = line[2];
    if (me == 'X') {
      round_points += lose[opp - 'A'];
    } else if (me == 'Y') {
      round_points += draw[opp - 'A'] + 3;
    } else if (me == 'Z') {
      round_points += win[opp - 'A'] + 6;
    }
    total += round_points;
  }

  cout << "Total: " << total << "\n";
  return 0;
}
