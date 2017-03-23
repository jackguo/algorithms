package epi;

public class ScoreCombination {
  public int numScoreComb(int s, int[] w) {
    if (s < 0 || w.length == 0) {
      return -1;
    }
    
    int[] numComb = new int[s + 1];
    numComb[0] = 1;
    
    for (int i = 0; i < w.length; ++i) {
      for (int sum = s; sum >= 0; --sum) {
        int remained = sum;
        int currNum = 0;
        while (remained >= 0) {
          currNum += numComb[remained];
          remained -= w[i];
        }
        numComb[sum] = currNum;
      }
    }
    
    return numComb[s];
  }
}