#include <iostream>
#include <string>

class DigitComparator {
 public:
  bool compare(const int &a, const int &b) {
    std::string a_str(std::to_string(a));
    std::string b_str(std::to_string(b));
    
    int i = 0, j = 0;
    int m = a_str.length(), n = b_str.length();
    int k = 0;
    while (a_str[i] == b_str[j] && k < (m > n? m : n)) {
        i = (i + 1) % m;
        j = (j + 1) % n;
        k++;
    }
    
    return (a_str[i] > b_str[j]);
  }
};

int main(int argc, char* argv[]) {
  DigitComparator dc;
  std::cout << dc.compare(98, 9897) << std::endl;
  std::cout << dc.compare(9, 8) <<std::endl;
  std::cout << dc.compare(65655, 6565598) << std::endl;
}
