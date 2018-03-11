// 279. Perfect Squares
// https://leetcode.com/problems/perfect-squares/description/

/**
 * @param {number} n
 * @return {number}
 */
var numSquares = function(n) {
  const queue = [], visited = new Array(n+1).fill(false);

  queue.push({num: n, step: 0});
  visited[n] = true;

  while (queue.length !== 0) {
    let p = queue.shift(), num = p.num, step = p.step;

    for (let i = 0; ; i++) {
      let k = num - i * i;
      if (k < 0) break;
      if (k === 0) return step + 1;
      if (!visited[k]) {
        queue.push({num: k, step: step + 1});
        visited[k] = true;
      }
    }
  }
  throw (new Error('no solution'));
};

console.info(numSquares(12));
console.info(numSquares(13));
