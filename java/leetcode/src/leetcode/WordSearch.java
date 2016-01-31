package leetcode;

public class WordSearch {
  public boolean exist(char[][] board, String word) {
    if (board == null || board.length == 0 || board[0].length == 0
        || word == null || word.length() == 0) {

      return false;
    }

    boolean res = false;
    for (int i = 0; i < board.length && !res; ++i) {
      for (int j = 0; j < board[0].length && !res; ++j) {
        res = btSearch(board, word, i, j);
      }
    }

    return res;
  }

  private boolean btSearch(char[][] board, String word, int currI, int currJ) {
    if (board[currI][currJ] != word.charAt(0)) {
      return false;
    } else if (word.length() == 1) {
      return true;
    }

    boolean res = false;

    board[currI][currJ] = '0';
    if (!res && currI > 0 && board[currI - 1][currJ] != '0') {
      res = btSearch(board, word.substring(1), currI - 1, currJ);
    }

    if (!res && currI < board.length - 1 && board[currI + 1][currJ] != '0') {
      res = btSearch(board, word.substring(1), currI + 1, currJ);
    }

    if (!res && currJ > 0 && board[currI][currJ - 1] != '0') {
      res = btSearch(board, word.substring(1), currI, currJ - 1);
    }

    if (!res && currJ < board[0].length - 1 && board[currI][currJ + 1] != '0') {
      res = btSearch(board, word.substring(1), currI, currJ + 1);
    }

    board[currI][currJ] = word.charAt(0);
    return res;
  }
}