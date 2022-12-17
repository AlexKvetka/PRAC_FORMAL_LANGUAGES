#include "full.hpp"

void GetWord(int check_number) {
  int lenth = 0;
  for(int i = 0; i < check_number; ++i){
    std::vector<std::string> word;
    std::cin >> lenth;
    for(int j = 0; j < lenth; ++j){
      std::string symbol;
      std::cin >> symbol;
      std::cout << symbol << " ";
      word.push_back(symbol);
      std::cout << symbol << " \n";
    }
    std::cout << "\n\n";
    all_words.push_back(word);
    
  }
  

}

void GetWords() {
  std::cout << "Write Number of Words you want check:\n";
  int check_number;
  std::cin >> check_number;
  std::cout << "Write Word you want check in format:\n";
  std::cout << "i, love, you - symbols\n";
  std::cout << "if word iloveyoulove - symbols\n";
  std::cout << "Write: 4 i love you love" << std::endl;
  GetWord(check_number);
}