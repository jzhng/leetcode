// 52. N-Queens II
// https://leetcode.com/problems/n-queens-ii/description/

/**
 * @param {number} n
 * @return {number}
 */
var totalNQueens = function(n) {
  function putQueen(index, row) {
    if (index === n) {
      res++;
    } else {
      for (let i = 0; i < n; i++) {
        const id1 = index + i, id2 = index - i + n - 1;
        if (!col[i] && !diag1[id1] && !diag2[id2]) {
          row.push(i);
          col[i] = diag1[id1] = diag2[id2] = true;
          putQueen(index + 1, row);
          col[i] = diag1[id1] = diag2[id2] = false;
          row.pop();
        }
      }
    }
  }

  const col = new Array(n).fill(false);
  const diag1 = new Array(2*n-1).fill(false);
  const diag2 = new Array(2*n-1).fill(false);

  let res = 0;
  putQueen(0, []);
  return res;
};

console.info(totalNQueens(4));
