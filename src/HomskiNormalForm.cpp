#include "full.hpp"

void DeleteNotGeneratingOrNotReached();
int IsGenerating(std::string str, int index);
int IsReached(int index);
void HomskyNormalForm();
bool IsInVec(std::vector<std::vector<std::string>> vec, std::string str);
void AddNewStartNeterminal();

void DelNonTermEpsilon(std::string non_term);
void ChangeEpsilonBorn() ;
void ChangeMixed();
bool IsMixed(std::string str);
void ChangeLong();
bool IsLong();
void ChangeEpsilonBorn();
bool IsEpsilonBorning();
bool IsNonTerm(std::string str);
bool IsTerminal(std::string str);
std::vector<std::string> BesidesThat(std::vector<std::string> vec, std::string str);
void UpdateRules();

void UpdateRules() {
  std::vector<std::vector<std::string>> final_vec;
  bool flag;
	for(int i = 0; i < non_terminals_hnf[i].size(); ++i) {
		final_vec = {};
		for(int j = 0; j < Rules_hnf[non_terminals_hnf[i]].size(); ++j) {
      flag = 1;
			for(int k = 0; k < Rules_hnf[non_terminals_hnf[i]][j].size(); ++k) {
        if((!IsNonTerm(Rules_hnf[non_terminals_hnf[i]][j][k])) && (!IsTerminal(Rules_hnf[non_terminals_hnf[i]][j][k]))){
          flag = 0;
					break;
				} 
      }
			if(flag) {
				final_vec.push_back(Rules_hnf[non_terminals_hnf[i]][j]);
			}
		}
		Rules_hnf[non_terminals_hnf[i]] = final_vec;
  }
}

void HomskyNormalForm() {
  terminals_hnf = terminals;
  DeleteNotGeneratingOrNotReached();
  ChangeEpsilonBorn();
  for(int i = 0; i < non_terminals_hnf.size(); ++i) {
    Rules_hnf[non_terminals_hnf[i]] = Rules[non_terminals_hnf[i]];
  }
  ChangeMixed();
  UpdateRules();
}

bool IsNonTerm(std::string str) {
  for(int i = 0; i < non_terminals_hnf.size(); ++i) {
    if(str == non_terminals_hnf[i]) {
      return true;
    }
  }
  return false;
}


void DeleteNotGeneratingOrNotReached(){
  std::string non_term;
  is_reached.resize(non_terminals.size());
  for(int i = 1; i < non_terminals.size(); ++i) {
    is_reached[i] = -1;
  }
  is_reached[0] = 1;
  for(int i = 1; i < non_terminals.size(); i++) {
    IsReached(i);
  }
  for(int i = 0; i < non_terminals.size(); ++i) {
    if(is_reached[i] == 1) {
      non_terminals_hnf.push_back(non_terminals[i]);
    }
  }  
  is_generating.resize(non_terminals_hnf.size());
  is_generating[0] = 1;
  
  for(int i = 1; i < non_terminals_hnf.size(); ++i) {
    is_generating[i] = -1;
  }
  for(int i = 0; i < non_terminals_hnf.size(); ++i) {
    IsGenerating(non_terminals_hnf[i], i);
  }
  for(int i = 0; i < non_terminals_hnf.size(); ++i) {
    if(is_generating[i] == 0) {
      non_terminals_hnf.erase(non_terminals_hnf.begin() + i);
    }
  }
}

bool IsTerminal(std::string str) {
  for(int i = 0; i < terminals.size(); ++i) {
    if(str == terminals[i]) {
      return 1;
    }
  }
  return 0;
}

int GetNonTerminalIndex(std::string str) {
  for(int i = 0; i < non_terminals_hnf.size(); ++i) {
    if(str == non_terminals[i]) {
      return i;
    }
  }
  return -1;
}

int IsGenerating(std::string str, int index) {
  if(is_generating[GetNonTerminalIndex(str)] != -1) {
    return is_generating[GetNonTerminalIndex(str)];
  }
  int all_terminals = -1;
  for(int i = 0; i < Rules[str].size(); ++i) {
    int exist_non_term = -1;
    for(int j = 0; j < Rules[str][i].size(); ++j) {
      std::string elem = Rules[str][i][j];
      if(str != elem) {
        if(IsTerminal(elem) == 0){
          exist_non_term = 1;
          int recursive_index = GetNonTerminalIndex(elem);
          IsGenerating(elem, recursive_index);
          if(is_generating[recursive_index] == 1) {
            is_generating[index] = 1;
            return 1;
          }
        }
      } else {
        exist_non_term = 1;
        continue;
      }
    }
    if(exist_non_term == -1) {
      is_generating[index] = 1;
      return 1;
    }
  }
  is_generating[index] = 0;
  return 0;
}

int IsReached(int index) {
  if(is_reached[index] == 1) {
    return 1;
  }
  if(is_reached[index] == 0) {
    return 0;
  }
  for(int i = 0; i < non_terminals.size(); ++i) {
    if(IsInVec(Rules[non_terminals[i]], non_terminals[index])) {
      if(IsReached(i) == 1) {
        is_reached[index] = 1;
        return 1;
      } 
    } 
  }
  is_reached[index] = 0;
  return 0;
}

bool IsInVec(std::vector<std::vector<std::string>> vec, std::string str) {
  for(int i = 0; i < vec.size(); ++i) {
    for(int j = 0; j < vec[i].size(); ++j) {
      if(str == vec[i][j]) {
        return true;
      }
    }
  }
  return false;
}

void ChangeMixed(){
  for(int i = 0; i < non_terminals_hnf.size(); ++i) {
    if(IsMixed(non_terminals_hnf[i])){
      for(int j = 0; j < Rules_hnf[non_terminals_hnf[i]].size(); ++j){
        for(int k = 0; k < Rules_hnf[non_terminals_hnf[i]][j].size(); ++k){
          std::string elem = Rules_hnf[non_terminals_hnf[i]][j][k];
          if(IsTerminal(elem)){
            std::string str = "Added" + std::to_string(number_non_terminal); 
            ++number_non_terminal;
            Rules_hnf[non_terminals_hnf[i]][j][k] = str;
            non_terminals_hnf.push_back(str);
            Rules_hnf[str] = {{elem}}; 
          }
        }
      }
    }
  }
}

bool IsMixed(std::string str) {
  int terminals_num = 0;
  int non_terminals_num = 0;
  for(int j = 0; j < Rules_hnf[str].size(); ++j){
    for(int k = 0; k < Rules_hnf[str][j].size(); ++k){
      std::string elem = Rules_hnf[str][j][k];
      if(IsTerminal(elem)){
        ++terminals_num;
      } else {
        ++non_terminals_num;
      }
      if(non_terminals_num > 0 && terminals_num > 0) {
        return 1;
      }
    }
  }
  return 0;
}

void DeleteOnlyEpsilons(std::string non_term) {
  for(int i = 0; i < non_terminals_hnf.size(); ++i) {
    for(int j = 0; j < Rules[non_terminals_hnf[i]].size(); ++j) {
      for(int k = 0; k < Rules[non_terminals_hnf[i]][j].size(); ++k) {
        if(Rules[non_terminals_hnf[i]][j][k] == non_term) {
          Rules[non_terminals_hnf[i]][j].erase(Rules[non_terminals_hnf[i]][j].begin() + k);
        }
      
      }
    }
  }
}

void ChangeEpsilonBorn() {
  for(int i = 0; i < non_terminals_hnf.size(); ++i) {
    for(int j = 0; j < Rules[non_terminals_hnf[i]].size(); ++j) {
      for(int k = 0; k < Rules[non_terminals_hnf[i]][j].size(); ++k) {
        std::vector<std::string> vec = Rules[non_terminals_hnf[i]][j];
        std::string elem = vec[k];
        if(elem == "epsilon") {
          if(Rules[non_terminals_hnf[i]].size() == 1 && Rules[non_terminals_hnf[i]][0].size()){
            DeleteOnlyEpsilons(non_terminals_hnf[i]);
            non_terminals_hnf.erase(non_terminals_hnf.begin() + i);
          } else {
            Rules[non_terminals_hnf[i]][j].erase(std::remove(Rules[non_terminals_hnf[i]][j].begin(), Rules[non_terminals_hnf[i]][j].end(), "epsilon"), Rules[non_terminals_hnf[i]][j].end());
            DelNonTermEpsilon(non_terminals_hnf[i]);
          }
        }
      }
    }
  }
}

void DelNonTermEpsilon(std::string non_term) {
  for(int i = 0; i < non_terminals_hnf.size(); ++i) {
    for(int j = 0; j < Rules[non_terminals_hnf[i]].size(); ++j) {
      for(int k = 0; k < Rules[non_terminals_hnf[i]][j].size(); ++k) {
        std::vector<std::string> vec = Rules[non_terminals_hnf[i]][j];
        if(vec[k] == non_term) {
          if(vec.size() == 1) {
            Rules[non_terminals_hnf[i]].push_back({"epsilon"});
          } else {
            Rules[non_terminals_hnf[i]].push_back(BesidesThat(vec, non_term));
          }
        }
      }
    }
  }
}

std::vector<std::string> BesidesThat(std::vector<std::string> vec, std::string str) {
  std::vector<std::string> new_vec;
  for(int i = 0; i < vec.size(); ++i) {
    if(vec[i] != str) {
      new_vec.push_back(vec[i]);
    }
  }
  return new_vec;
}

void AddNewStartNeterminal() {
  std::string S0 = "S0";
  non_terminals_hnf.push_back(S0);
  Rules[S0].push_back({non_terminals[0]});
}
