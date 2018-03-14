// 79. Word Search
// https://leetcode.com/problems/word-search/description/

/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function(board, word) {
  function searchWord(index, startx, starty) {
    if (index === word.length - 1) {
      return board[startx][starty] === word[index];
    }

    if (board[startx][starty] === word[index]) {
      visited[startx][starty] = true;
      for (let i = 0; i < 4; i++) {
        const newx = startx + d[i][0], newy = starty + d[i][1];    
        if (inArea(newx, newy) && !visited[newx][newy]
            && searchWord(index + 1, newx, newy)) {
          return true;
        }
      }
      visited[startx][starty] = false;
    }

    return false;
  }

  function inArea(x, y) {
    return x >= 0 && x < m && y >= 0 && y < n;
  }

  const d = [[1, 0], [0, 1], [-1, 0], [0, -1]];
  const m = board.length, n = board[0].length;
  const visited = [];
  for (let i = 0; i < m; i++) {
    visited.push(new Array(n).fill(false));
  }

  for (let i = 0; i < board.length; i++) {
    for (let j = 0; j < board[i].length; j++) {
      if (searchWord(0, i, j)) return true;
    }
  }
  return false;
};

const board = [
  ['A', 'B', 'C', 'E'],
  ['S', 'F', 'C', 'S'],
  ['A', 'D', 'E', 'E']
];
console.info(exist(board, 'ABCCED'));
console.info(exist(board, 'SEE'));
console.info(exist(board, 'ABCB'));
