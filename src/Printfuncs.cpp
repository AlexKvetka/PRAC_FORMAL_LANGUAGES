#include "full.hpp"

void PrintVecStr(std::vector<std::string> vec, std::string space = " ", std::string end = "\n") {
  for(int i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << space;
  }
  std::cout << end;
}

void PrintVecInt(std::vector<int> vec, std::string space = " ", std::string end = "\n") {
  for(int i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << space;
  }
  std::cout << end;
}

void PrintTerminals() {
  PrintVecStr(terminals);
}

void PrintNonTerminals() {
  PrintVecStr(non_terminals);
}

void PrintRules() {
  for(int i = 0; i < non_terminals.size(); ++i) {
    std::cout << non_terminals[i] << " ";
    for(int j = 0; j < Rules[non_terminals[i]].size(); ++j){
      PrintVecStr(Rules[non_terminals[i]][j], "_", " ");
    }
    std::cout << std::endl;
  }
}

void PrintTerminalsHNF() {
  PrintVecStr(terminals_hnf);
}
void PrintNonTerminalsHNF() {
  PrintVecStr(non_terminals_hnf);
}

void PrintRulesHNF() {
  for(int i = 0; i < non_terminals_hnf.size(); ++i) {
    std::cout << non_terminals_hnf[i] << " ";
    for(int j = 0; j < Rules_hnf[non_terminals_hnf[i]].size(); ++j){
      PrintVecStr(Rules_hnf[non_terminals_hnf[i]][j], "_", " ");
    }
    std::cout << std::endl;
  }
  
}

void PrintAll() {
  static int sum_num = 0;
  ++sum_num;
  std::cout << std::endl << std::endl << "start------ " << sum_num << " -----------" << std::endl;
  PrintTerminals();
  PrintNonTerminals();
  PrintRules();
  std::cout << "finish-----------------" << std::endl << std::endl;
}

void PrintAllHNF() {
  static int sum_num = 0;
  ++sum_num;
  std::cout << std::endl << std::endl << "startHNF------ " << sum_num << " -----------" << std::endl;
  PrintTerminalsHNF();
  PrintNonTerminalsHNF();
  PrintRulesHNF();
  std::cout << "finishHNF-----------------" << std::endl << std::endl;
}