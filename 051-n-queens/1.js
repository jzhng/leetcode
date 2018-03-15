// n-queens
// https://leetcode.com/problems/n-queens/description/

/**
 * @param {number} n
 * @return {string[][]}
 */
var solveNQueens = function(n) {
  function putQueen(index, row) {
    if (index === n) {
      res.push(generateBoard(row));
    } else {
      for (let i = 0; i < n; i++) {
        if (!col[i] && !diag1[index + i] && !diag2[index - i + n - 1]) {
          row.push(i);
          col[i] = diag1[index + i] = diag2[index - i + n - 1] = true;
          putQueen(index + 1, row);
          col[i] = diag1[index + i] = diag2[index - i + n - 1] = false;
          row.pop();
        }
      }
    }
  }

  function generateBoard(row) {
    const board = [];
    for (let i = 0; i < n; i++) {
      let chs = new Array(n).fill('.');
      chs[row[i]] = 'Q';
      board.push(chs.join(''));
    }
    return board;
  }

  const res = [];
  const col = new Array(n).fill(false);
  const diag1 = new Array(2*n-1).fill(false);
  const diag2 = new Array(2*n-1).fill(false);
  putQueen(0, []);
  return res;
};

console.info(solveNQueens(4));
// console.info(solveNQueens(8));
