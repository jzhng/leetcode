// 202. Happy Number
// https://leetcode.com/problems/happy-number/description/

/**
 * @param {number} n
 * @return {boolean}
 */
var isHappy = function(n) {
  const set = new Set();

  while (n !== 1) {
    let sum = 0;
    while (n > 0) {
      sum += Math.pow(n % 10, 2);
      n = Math.floor(n / 10);
    }
    n = sum;

    if (!set.has(n)) {
      set.add(n);
    } else {
      break;
    }
  }
  return n === 1;
};

console.info(isHappy(19));
