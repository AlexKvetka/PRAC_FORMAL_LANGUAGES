#include "full.hpp"

extern void ProcessInput();
extern void GetWords();
extern bool CYKParse(std::vector<std::string> w);
extern void HomskyNormalForm();
extern std::vector<std::vector<std::string>> all_words;

int main() {
  ProcessInput();
  GetWords();
  std::cout << "\nGETTEN: " ;
  std::cout << all_words.size() << std::endl;
  for(int i = 0; i < all_words.size(); ++i) {
    for(int j = 0; j < all_words[i].size(); ++j){
      std::cout << all_words[i][j] << " ";
    }
    std::cout << '\n';
  }
  
  HomskyNormalForm();

  for(int i = 0; i < all_words.size(); ++i) {
    for(int j = 0; j < all_words[i].size(); ++j){
      std::cout << all_words[i][j] << " ";
    }
    std::cout << std::endl;
    if(CYKParse(all_words[i])) {
      std::cout << "True" << std::endl;
    } else {
      std::cout << "False" << std::endl;
    }
    std::cout << std::endl;

  }

  return 0;
}