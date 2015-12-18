#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num_islands = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++num_islands;
                    bfs(grid, i, j);
                }
            }
        }
        
        return num_islands;
    }
    
private:
    void bfs(std::vector<std::vector<char>>& grid, int i_start, int j_start) {
        std::deque<std::pair<int, int>> neighbors;
        neighbors.push_back(pair<int, int>(i_start, j_start));
        while (! neighbors.empty()) {
            std::pair<int, int> p = neighbors.front();
            neighbors.pop_front();
            grid[p.first][p.second] = '2';
            if (p.first > 0 && grid[p.first - 1][p.second] == '1') {
              grid[p.first - 1][p.second] = '3';
                neighbors.push_back(std::pair<int, int>(p.first - 1, p.second));
            }
            
            if (p.first < (int) grid.size() - 1 && grid[p.first + 1][p.second] == '1') {
              grid[p.first + 1][p.second] = '3';
                neighbors.push_back(std::pair<int, int>(p.first + 1, p.second));
            }
            
            if (p.second > 0 && grid[p.first][p.second - 1] == '1') {
              grid[p.first][p.second - 1] = '3';
                neighbors.push_back(std::pair<int, int>(p.first, p.second - 1));
            }
            
            if (p.second < (int) grid[0].size() - 1 && grid[p.first][p.second + 1] == '1') {
              grid[p.first][p.second + 1] = '3';
                neighbors.push_back(std::pair<int, int>(p.first, p.second + 1));
            }
        }
    }
};

int main(int argc, char* argv[]) {
  vector<string> test_case(
      { "11111011111111101011","01111111111110111110","10111001101111111111","11110111111111111111","10011111111111111111","10111111011101110111","01111111111101101111","11111111111101111011","11111111110111111111","11111111111111111111","01111111011111111111","11111111111111111111","11111111111111111111","11111011111110111111","10111110111011110111","11111111111101111110","11111111111110111100","11111111111111111111","11111111111111111111","11111111111111111111" });
  
  vector<vector<char>> input;
  for (int i = 0; i < test_case.size(); ++i) {
    const char* chars = test_case[i].c_str();
    vector<char> line(chars, chars + test_case.size());
    input.push_back(line);
  }
  
  Solution solution;
  std::cout << solution.numIslands(input) << std::endl;
}

                           
