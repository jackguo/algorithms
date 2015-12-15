#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> res;
        
        int i_s, i_e, j_s, j_e, i, j;
        i_s = j_s = 0;
        if ((i_e = matrix.size()) == 0 || (j_e = matrix[0].size()) == 0) {
            return res;
        }
        
        while (i_s < i_e && j_s < j_e) {
            for (i = i_s, j = j_s; j < j_e; ++j) {
                res.push_back(matrix[i][j]);
            }
            
            for (j = j_e - 1, i = i_s + 1; i < i_e; ++i) {
                res.push_back(matrix[i][j]);
            }
            
            if (i_e > i_s + 1) {
                for (i = i_e - 1, j = j_e - 2; j >= j_s; --j) {
                    res.push_back(matrix[i][j]);
                }
            }
            
            if (j_e > j_s + 1) {
                for (j = j_s, i = i_e - 2; i > i_s; --i) {
                    res.push_back(matrix[i][j]);
                }
            }
            
            ++i_s;
            ++j_s;
            --i_e;
            --j_e;
        }
        
        return res;
    }
};

int main(int argc, char* argv[]) {
  Solution solution;
  vector<vector<int> > inputs;
  vector<int> line(2);
  line[0] = 1;
  line[1] = 2;
  inputs.push_back(line);
  line[0] = 3;
  line[1] = 4;
  inputs.push_back(line);
  solution.spiralOrder(inputs);
}
