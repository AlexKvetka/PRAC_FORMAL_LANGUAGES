#include "../headers/main.hpp"
extern std::vector<std::string> terminals_hnf;
extern std::vector<std::string>  non_terminals_hnf;
extern std::unordered_map<std::string, std::vector<std::vector<std::string>>> Rules_hnf;

extern std::vector<std::string> terminals;
extern std::vector<std::string>  non_terminals;
extern std::unordered_map<std::string, std::vector<std::vector<std::string>>> Rules;

extern void DeleteNotGeneratingOrNotReached();

extern void PrintNonTerminals();
extern void PrintTerminals();
extern void PrintRules();

extern void PrintNonTerminalsHNF();
extern void PrintTerminalsHNF();
extern void PrintRulesHNF();

extern void PrintAll();
extern void PrintAllHNF();