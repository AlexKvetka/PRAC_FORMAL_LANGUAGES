#include "full.hpp"

void GetVector(std::vector<std::string>& vector, int number) {
  std::string str;
  for (int i = 0; i < number; ++i) {
    std::cin >> str;
    vector.push_back(str);
  }
}

void GetElements(std::vector<std::string>& vector, std::string type) {
  std::cout << "Write number of " + type + ":\n";
  int number;
  std::cin >> number;
  std::cout << "Write ALL " + type + " (separated by a space)\n";
  GetVector(vector, number);
}

std::vector<std::string> SplitRightPartRules(std::string str) {
  std::string to_elem = "";
  std::vector<std::string> to_elements;
  for (int i = 0; i < str.size(); ++i) {
    if (str[i] == '_') {
      to_elements.push_back(to_elem);
      to_elem = "";
    } else {
      to_elem += str[i];
    }
  }
  if (to_elem != "") {
    to_elements.push_back(to_elem);
  }
  return to_elements;
}

void GetRules() {
  int number_rules = 0;
  std::string from_str = "";
  std::string to_str = "";
  std::cout << "GETRULES  " <<  non_terminals.size() << std::endl;
  for (int i = 0; i < non_terminals.size(); ++i) {
    std::cin >> from_str;
    std::cin >> number_rules;
    if (number_rules == 0) {
      Rules[from_str].push_back({});
    } else {
      for (int j = 0; j < number_rules; ++j) {
        std::cin >> to_str;
        Rules[from_str].push_back(SplitRightPartRules(to_str));
      }
    }
  }
}

void ProcessInput() {
  GetElements(non_terminals, "NonTerminals");
  GetElements(terminals, "Terminals");
  std::cout << "Write Rules in format\n";
  std::cout << "A,B,C,D,E - non_terminals";

  std::cout << "if A->B A->C A->DEA B->C\n";

  std::cout << "Write: A 3 B C D_E_A\n";
  std::cout << "Write: B 1 C\n";
  std::cout << "Write: C 0\n";
  std::cout << "Write: D 0\n";
  std::cout << "Write: E 0\n";

  std::cout << " 3 is number of rules for NonTerminal\n";
  std::cout << "Write Format Rules for every NonTerminal:\n";
  GetRules();

}