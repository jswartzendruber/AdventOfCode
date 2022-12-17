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

struct Monkey {
  vector<long> items;
  bool multiply;
  long op_num;
  long divis_by;
  long monkey_if_true;
  long monkey_if_false;
  long inspections;
};

int main() {
  ifstream cin("11.input");
  vector<string> v;
  string line;
  while (getline(cin, line)) {
    v.push_back(line);
  }

  vector<Monkey> monkeys;
  for (long i = 0; i < v.size(); i++) {
    if (v[i].rfind("Monkey", 0) == 0) {
      // cout << v[i] << "\n";
      istringstream start_items(v[i + 1], istringstream::in);
      vector<long> starting_items;
      string temp;
      while (start_items >> temp) {
	if (isdigit(temp[0]))
	  starting_items.push_back(stoi(temp));
      }

      // for (auto x : starting_items)
      // 	cout << x << ",";
      // cout << "\n";

      bool mult = v[i + 2].find('*') == -1 ? false : true;
      // if (mult) cout << "times\n"; else cout << "add\n";
      istringstream operator_number(v[i + 2], istringstream::in);
      long op_num = 0;
      while (operator_number >> temp) {
	if (isdigit(temp[0]))
	  op_num = stoi(temp);
      }
      // cout << op_num << "\n";
      // if (op_num == 0) {
      // 	// old and old
      // } else {
      // 	// old and op_num
      // }

      istringstream divis_by(v[i + 3], istringstream::in);
      long divisible_by = 0;
      while (divis_by >> temp) {
	if (isdigit(temp[0]))
	  divisible_by = stoi(temp);
      }
      // cout << divisible_by << "\n";

      long monkey_if_true = 0;
      long monkey_if_false = 0;
      istringstream if_true(v[i + 4], istringstream::in);
      while (if_true >> temp) {
	if (isdigit(temp[0]))
	  monkey_if_true = stoi(temp);
      }
      istringstream if_false(v[i + 5], istringstream::in);
      while (if_false >> temp) {
	if (isdigit(temp[0]))
	  monkey_if_false = stoi(temp);
      }

      // cout << "tr: " << monkey_if_true << "\n";
      // cout << "fa: " << monkey_if_false << "\n";
      Monkey monkey;
      monkey.items = starting_items;
      monkey.multiply = mult;
      monkey.op_num = op_num;
      monkey.divis_by = divisible_by;
      monkey.monkey_if_true = monkey_if_true;
      monkey.monkey_if_false = monkey_if_false;
      monkey.inspections = 0;
      monkeys.push_back(monkey);
    }
  }

  long rounds = 10000;

  int magic_modulo = 1;
  for (auto m : monkeys)
    magic_modulo *= m.divis_by;

  for (long i = 0; i < rounds; i++) {
    for (auto& m : monkeys) {
      for (auto items = m.items.begin(); items != m.items.end();) {
	m.inspections++;

	// Worry level - inspect
	if (m.op_num == 0)
	  if (m.multiply) {
	    *items *= *items;
	  } else
	    *items += *items;
	else
	  if (m.multiply) {
	    *items *= m.op_num;
	  } else
	    *items += m.op_num;

	// Worry - bored
	// *items /= 3;
	*items %= magic_modulo;

	// Test worry level
	if (*items % m.divis_by == 0) {
	  monkeys[m.monkey_if_true].items.push_back(*items);
	} else {
	  monkeys[m.monkey_if_false].items.push_back(*items);
	}
	m.items.erase(items);
      }
    }
  }

  sort(monkeys.begin(), monkeys.end(), [](Monkey a, Monkey b) {
    return a.inspections > b.inspections;
  });

  long n = 0;
  for (Monkey m : monkeys) {
    cout << "monkey " << n << " insp: " << m.inspections << "\n";
    n++;
  }

  cout << "Monkey business: " << monkeys[0].inspections * monkeys[1].inspections << "\n";

  return 0;
}
