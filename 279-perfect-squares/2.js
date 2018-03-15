/**
 * @param {number} n
 * @return {number}
 */
var numSquares = function(n) {
  const squares = [0, 1];

  for (let i = 2; i <= n; i++) {
    for (let j = 1; j * j <= i; j++) {
      squares[i] = Math.min(squares[i] || i, 1 + squares[i - j * j]);
    }
  }
  return squares[n];
};

console.info(numSquares(12));
console.info(numSquares(13));
