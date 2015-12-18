// knuth - morris - pratt algorithm
#include <iostream>
#include <vector>
#include <string>

// find the first occurence of word 
int find(const std::string &s, const std::string &word);
std::vector<int>& buildTable(const std::string &word);

std::vector<int>& buildTable(const std::string &word) {
  std::vector<int> *res = new std::vector<int>(word.length(), 0);
  if (word.length() == 0) return *res;
  (*res)[0] = -1;
  if (word.length() == 1) return *res;
  (*res)[1] = 0;
  
  int cnd = 0;
  int pos = 2;
  while (pos != word.length()) {
    if (word[pos - 1] == word[cnd]) {
      ++cnd;
      (*res)[pos] = cnd;
      ++pos;
    } else if (cnd != 0) {
      cnd = (*res)[cnd];
    } else {
      (*res)[pos] = 0;
      ++pos;
    }
  }
  
  return *res;
}

int find(const std::string &s, const std::string &word) {
  if (word.length() == 0) return 0;
  if (s.length() < word.length()) return -1;
  
  int m, i;
  m = i = 0;
  std::vector<int> &T = buildTable(word);
  
  while (m + i <= s.length()) {
    if (i == word.length()) return m;
    
    if (s[m + i] == word[i]) {
      ++i;
    } else {
      m = m + i - T[i];
      i = T[i] < 0 ? 0 : T[i];
    }
  }

  return -1;
  
}

int main(int argc, char* argv[]) {
  std::string s("a");
  std::string word("a");
  std::cout << find(s, word) << std::endl;
}
