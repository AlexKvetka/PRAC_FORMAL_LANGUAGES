#include <bits/stdc++.h>

// Free Rules of the grammar
std::vector<std::string> terminals;
std::vector<std::string>  non_terminals;
std::unordered_map<std::string, std::vector<std::vector<std::string>>> Rules;


// Homsky Normal Form Rules of the grammar
std::vector<std::string> terminals_hnf;
std::vector<std::string>  non_terminals_hnf;
std::unordered_map<std::string, std::vector<std::vector<std::string>>> Rules_hnf;


std::vector<std::vector<std::string>> all_words;

std::vector<int> is_reached;
std::vector<int> is_generating;

int number_non_terminal;