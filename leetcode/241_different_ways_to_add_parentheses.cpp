#include <iostream>
#include <cctype>
#include <cstdlib>
#include <string>
#include <vector>

#define MMAP(i, j, n) ((i) * (n) + (j) - (i + 1) * (i) /2)

struct Expression {
  std::vector<int> operands;
  std::string ops;
};

// recursive manner, simple divide-and-conquer solution
// not efficient
class Solution1 {
 public:
  std::vector<int> diffWaysToCompute(std::string input);
 private:
  int compute(int left, int right, char op);
  Expression* parse(std::string input);
  std::vector<int> computeSubExpr(Expression *expr, int i, int j);
};

/* Dynamic Programming approach 
*/
class Solution2 {
 public:
  std::vector<int> diffWaysToCompute(std::string input);
 private:
  int compute(int left, int right, char op);
  Expression* parse(std::string input);
};

int Solution1::compute(int left, int right, char op) {
  int res;
  
  switch(op) {
    case '+': res = left + right; break;
    case '-': res = left - right; break;
    case '*': res = left * right; break;
    default: res = 0; //bad!
  }
  return res;
}

Expression* Solution1::parse(std::string input) {
  Expression* expr = new Expression();
  
  std::string operand;
  for (int i = 0; i < input.length(); i++) {
    if (isblank(input[i])) continue;
    
    if (isdigit(input[i])) {
      operand.push_back(input[i]);
    } else {
      expr->operands.push_back(atoi(operand.c_str()));
      expr->ops.push_back(input[i]);
      operand.clear();
    }
  }
  
  expr->operands.push_back(atoi(operand.c_str()));
  return expr;
}

std::vector<int> Solution1::computeSubExpr(Expression *expr, int i, int j) {
  std::vector<int> res;

  if (i == j) {
    res.push_back(expr->operands[i]);
    return res;
  }
  
  if (i == j - 1) {
    res.push_back(this->compute(expr->operands[i], expr->operands[j], expr->ops[i]));
    return res;
  }
  
  for (int mid = i; mid < j; mid++) {
    
  
    std::vector<int> left = computeSubExpr(expr, i, mid);
    std::vector<int> right = computeSubExpr(expr, mid + 1, j);
    
    for (std::vector<int>::iterator lit = left.begin(); lit != left.end(); lit++) {
      for (std::vector<int>::iterator rit = right.begin(); rit != right.end(); rit++) {
        res.push_back(compute(*lit, *rit, expr->ops[mid]));
      }
    }
  }
  
  return res;
}

std::vector<int> Solution1::diffWaysToCompute(std::string input) {
  Expression *expr = parse(input);
  return computeSubExpr(expr, 0, expr->operands.size() - 1);
}

int Solution2::compute(int left, int right, char op) {
  int res;
  
  switch(op) {
    case '+': res = left + right; break;
    case '-': res = left - right; break;
    case '*': res = left * right; break;
    default: res = 0; //bad!
  }
  return res;
}

Expression* Solution2::parse(std::string input) {
  Expression* expr = new Expression();
  
  std::string operand;
  for (int i = 0; i < input.length(); i++) {
    if (isblank(input[i])) continue;
    
    if (isdigit(input[i])) {
      operand.push_back(input[i]);
    } else {
      expr->operands.push_back(atoi(operand.c_str()));
      expr->ops.push_back(input[i]);
      operand.clear();
    }
  }
  
  expr->operands.push_back(atoi(operand.c_str()));
  return expr;
}

std::vector<int> Solution2::diffWaysToCompute(std::string input) {
  Expression *expr = parse(input);
  int n = expr->operands.size(); //input size, number of items in expression
  std::vector<int> ** m = new std::vector<int>*[n * (n + 1) / 2];
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i; j < n; j++) {
      m[MMAP(i, j, n)] = new std::vector<int>();
      if (i == j) {
        m[MMAP(i, j, n)]->push_back(expr->operands[i]);
      } else {
        for (int mid = i; mid < j; mid++) {
          for (std::vector<int>::iterator lit = m[MMAP(i, mid, n)]->begin();
               lit < m[MMAP(i, mid, n)]->end(); lit++) {
            for (std::vector<int>::iterator rit = m[MMAP(mid + 1, j, n)]->begin();
                 rit < m[MMAP(mid + 1, j, n)]->end(); rit++) {
              int val = compute(*lit, *rit, expr->ops[mid]);
              m[MMAP(i, j, n)]->push_back(val);
            }
          }
        }
      }
    }
  }
  
  return *m[MMAP(0, n - 1, n)];
}


int main(int argc, char* argv[]) {
  Solution2 solution;
  std::string test_strings[] = 
      {
        "1", "789", "200 - 50", "100 - 200 * 40", "57 - 21 + 78 * 8923" 
      };
  int size = sizeof(test_strings) / sizeof(char*);
  
  for (int i = 0; i < size; i++) {
    std::cout << "Expr: " << test_strings[i] << std::endl;
    std::cout << "Res: ";
    // std::string input(test_std::strings[i]);
    
    std::vector<int> res = solution.diffWaysToCompute(test_strings[i]);
    for (std::vector<int>::iterator it = res.begin(); it != res.end(); it++) {
      std::cout << *it << "   ";
    }
    
    std::cout << std::endl;
  }
}
