#include "full.hpp"

bool CYKParse(std::vector<std::string> w) {
  int n = (int)w.size();
  std::map<int, std::map<int, std::set<std::string>>> Table;
  std::string lhs;
	std::vector<std::vector<std::string>> rule;
	bool condition0;
	bool condition1;
	bool condition2;
	for (int j = 0; j < n; j++) {
    for (auto x : Rules_hnf) {
      lhs = x.first;
      rule = x.second;
      for (auto rhs : rule) {
        if (rhs.size() == 1 && rhs[0] == w[j]) Table[j][j].insert(lhs);
      }
    }
    for (int i = j; i >= 0; i--) {
      for (int k = i; k <= j; k++) {
        for (auto x : Rules_hnf) {
          lhs = x.first;
          rule = x.second;
          for (auto rhs : rule) {
						condition0 = rhs.size() == 2;
						if(condition0){
							condition1 = Table[i][k].find(rhs[0]) != Table[i][k].end();
							if(condition1){
								condition2 = Table[k + 1][j].find(rhs[1]) != Table[k + 1][j].end();
								if(condition2){
									Table[i][j].insert(lhs);
								}
							}
						}

          }
        }
      }
    }
  }
  if (Table[0][n - 1].size() != 0) {
    return true;
  } else {
    return false;
  }
}

