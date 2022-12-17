#include <bits/stdc++.h>
#include "GetPrintFuncs.hpp"

extern std::vector<std::vector<std::string>> all_words;
extern std::vector<std::string> terminals;
extern std::vector<std::string>  non_terminals;
extern std::unordered_map<std::string, std::vector<std::vector<std::string>>> Rules;

extern std::vector<std::string> terminals_hnf;
extern std::vector<std::string>  non_terminals_hnf;
extern std::unordered_map<std::string, std::vector<std::vector<std::string>>> Rules_hnf;

extern int number_non_terminal;

extern std::vector<int> is_reached;
extern std::vector<int> is_generating;

extern void DeleteNotGeneratingOrNotReached();
